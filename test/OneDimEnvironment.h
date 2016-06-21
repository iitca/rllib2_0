#ifndef ONEDIMENVIRONMENT_H
#define ONEDIMENVIRONMENT_H

#include "RLEnvironmentBase.h"
#include "OneDimState.h"
#include "OneDimAction.h"
#include "OneDimReward.h"

using namespace RLENTITY_NMSPC;

template<typename Ty1, typename Ty2>
class OneDimEnvironment : public RLEnvironmentBase < Ty1, Ty2 >
{
public:
	OneDimEnvironment(unsigned int);
	virtual unsigned int GetState() override;
	virtual Ty1* GetStoredPrevState() override;
	virtual Ty1* GetStoredCurrState() override;
	virtual unsigned int GetReward() override;
	virtual RLRewardBase* GetStoredReward() override;
	virtual unsigned int PerformAction(Ty2) override;
	virtual unsigned int Reset() override;
	virtual unsigned int Exit() override;
	virtual bool IsInGoalState() override;
private:
	unsigned int episodesNum;
	unsigned int episodesCounter;
	bool goalStateReached;
	Ty1* goalState;
	Ty1* currState;
	Ty1* prevState;
	OneDimReward* reward;
	double GetFragmentation(unsigned char);
};

template<typename Ty1, typename Ty2>
OneDimEnvironment<Ty1, Ty2>::OneDimEnvironment(unsigned int episodesNum)
{
	this->goalState = new OneDimState(UCHAR_MAX);
	this->currState = new OneDimState(0);
	this->prevState = new OneDimState(0);
	this->reward = nullptr;
	this->episodesNum = episodesNum;
	this->episodesCounter = 0;
	this->goalStateReached = false;
}

template<typename Ty1, typename Ty2>
unsigned int OneDimEnvironment<Ty1, Ty2>::GetState()
{
	//the return value will be used as an input to choose the next fsm state
	return 0;
}

template<typename Ty1, typename Ty2>
Ty1* OneDimEnvironment<Ty1, Ty2>::GetStoredPrevState()
{
	return this->prevState;
}

template<typename Ty1, typename Ty2>
Ty1* OneDimEnvironment<Ty1, Ty2>::GetStoredCurrState()
{
	return this->currState;
}

template<typename Ty1, typename Ty2>
unsigned int OneDimEnvironment<Ty1, Ty2>::GetReward()
{
	//create reward
	if (this->reward == nullptr)
		this->reward = new OneDimReward();
	unsigned char value = this->currState->Get();
	//frag level
	double frag = this->GetFragmentation(value);
	//0.9375 - max possible fragmentation
	int fragLevel = 0.9375*100 - (int)(this ->GetFragmentation(value) * 100);
	/*if (frag < 0.01)
		reward->SetValue(10);
	else
		reward->SetValue(-10);*/
	reward->SetValue(fragLevel);

	if (*this->currState == *this->prevState)
		reward->SetValue(-10);
	
	//check if the goal state was reached
	if (*this->currState == *this->goalState)
		this->goalStateReached = true;
	
	return 0;
}

template<typename Ty1, typename Ty2>
RLRewardBase* OneDimEnvironment<Ty1, Ty2>::GetStoredReward()
{
	if (this->reward != nullptr)
		return this->reward;
	else
		return new OneDimReward(0);
}

template<typename Ty1, typename Ty2>
unsigned int OneDimEnvironment<Ty1, Ty2>::PerformAction(Ty2 action)
{
	if (this->currState == nullptr ||
		this->prevState == nullptr)
		return 0;
	//save the current state first
	*(this->prevState) = *(this->currState);
	//get current value
	unsigned int currVal = this->currState->Get();
	//get the action's value
	int actionVal = action.GetValue();// % (sizeof(unsigned int) * 8);
	//action.SetValue(actionVal);
	//apply the action
	currVal |= (1 << actionVal);
	//store the new state
	this->currState->Set(currVal);
	//the return value is used as an value to select the next fsm state
	return 0;
}

template<typename Ty1, typename Ty2>
unsigned int OneDimEnvironment<Ty1, Ty2>::Reset()
{
	this->currState->Set(0);
	this->prevState->Set(0);
	//from this state we either go to EXIT_STATE or to the OBSRV_CURR_STATE
	//check if the desired number of episodes passed
	this->goalStateReached = false;
	this->episodesCounter++;
	if (this->episodesCounter > this->episodesNum){
		//here we exit
		this->episodesCounter = 0;
		return 1;
	}
	else
		//here we proceed to the OBSRV_CURR_STATE
		return 0;
}

template<typename Ty1, typename Ty2>
unsigned int OneDimEnvironment<Ty1, Ty2>::Exit()
{
	//here we might want to store the gained experience
	std::exit(0);
}

template<typename Ty1, typename Ty2>
bool OneDimEnvironment < Ty1, Ty2 >::IsInGoalState()
{
	return this->goalStateReached;
}

template<typename Ty1, typename Ty2>
double OneDimEnvironment < Ty1, Ty2 >::GetFragmentation(unsigned char val)
{
	int free = 0;
	int freeMax = 0;
	int freeMaxFin = 0;
	for (int i = 0; i < sizeof(val)*8; i++){
		if (((val)& (1 << i)) == 0){
			free++;
			freeMax++;
		}else{
			if (freeMax > freeMaxFin)
				freeMaxFin = freeMax;
			freeMax = 0;
		}
	}
	if (freeMax > freeMaxFin)
		freeMaxFin = freeMax;
	if (free)
		return ((double)free - (double)freeMaxFin) / (double)free;
	return 0.0;
}

#endif