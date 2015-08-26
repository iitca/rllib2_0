#ifndef GRIDWORLDEXPERIMENT
#define GRIDWORLDEXPERIMENT

#include "RLEnvironmentBase.h"
#include "GridWorldState.h"
#include "GridWorldAction.h"
#include "GridWorldReward.h"

using namespace RLENTITY_NMSPC;

template<typename Ty1, typename Ty2>
class GridWorldEnvironment : public RLEnvironmentBase<Ty1, Ty2>
{
public:
	GridWorldEnvironment(int, int, int, int);
	virtual unsigned int GetState() override;
	virtual Ty1* GetStoredPrevState() override;
	virtual Ty1* GetStoredCurrState() override;
	virtual unsigned int GetReward() override;
	virtual RLRewardBase* GetStoredReward() override;
	virtual unsigned int PerformAction(Ty2) override;
	virtual unsigned int Reset() override;
	virtual unsigned int Exit() override;
private:
	int xSize;
	int ySize;
	Ty1* goalState;
	Ty1* currState;
	Ty1* prevState;
	GridWorldReward* reward;
};

template<typename Ty1, typename Ty2>
GridWorldEnvironment<Ty1, Ty2>::GridWorldEnvironment(int x, int y, int xGoal, int yGoal)
{
	this->xSize = x;
	this->ySize = y;
	this->goalState = new GridWorldState(xGoal, yGoal);
	//set the states to 0,0
	this->currState = new GridWorldState(0, 0);
	this->prevState = new GridWorldState(0, 0);
	//reward is nullptr
	this->reward = nullptr;
}

template<typename Ty1, typename Ty2>
unsigned int GridWorldEnvironment<Ty1, Ty2>::GetState()
{


}

template<typename Ty1, typename Ty2>
Ty1* GridWorldEnvironment<Ty1, Ty2>::GetStoredPrevState()
{
	return this->prevState;
}

template<typename Ty1, typename Ty2>
Ty1* GridWorldEnvironment<Ty1, Ty2>::GetStoredCurrState()
{
	return this->currState;
}

template<typename Ty1, typename Ty2>
unsigned int GridWorldEnvironment<Ty1, Ty2>::GetReward()
{
	//create reward
	if (this->reward == nullptr)
		this->reward = new GridWorldReward();

	//check if the goal state was reached
	if (*this->currState == *this->goalState)
		this->reward->SetValue(10);
	else
		this->reward->SetValue(-5);

}

template<typename Ty1, typename Ty2>
RLRewardBase* GridWorldEnvironment<Ty1, Ty2>::GetStoredReward()
{
	if (this->reward != nullptr)
		return this->reward;
	else
		return new GridWorldReward(0);
}

template<typename Ty1, typename Ty2>
unsigned int GridWorldEnvironment<Ty1, Ty2>::PerformAction(Ty2 action)
{
	if (this->currState == nullptr ||
		this->prevState == nullptr)
		return 0;
	//save the current state first
	*(this->prevState) = *(this->currState);
	//get current coordinates
	int x = this->currState->GetX();
	int y = this->currState->GetY();
	//get the action's value
	int actionVal = action.GetValue() % Direction::DIR_NUM;
	action.SetValue(actionVal);
	//apply the action
	if (actionVal == Direction::EAST){
		if (this->currState->GetX() > 0)
			this->currState->SetCoordinates(--x, y);
	}
	else if (actionVal == Direction::NORTH){
		if (this->currState->GetY() < this->ySize-1)
			this->currState->SetCoordinates(x, ++y);
	}
	else if (actionVal == Direction::SOUTH){
		if (this->currState->GetY() > 0)
			this->currState->SetCoordinates(x, --y);
	}
	else if (actionVal == Direction::WEST){
		if (this->currState->GetX() < this->xSize-1)
			this->currState->SetCoordinates(++x, y);
	}
	//action applied!
	return 0;
}

template<typename Ty1, typename Ty2>
unsigned int GridWorldEnvironment<Ty1, Ty2>::Reset()
{
	this->currState->SetCoordinates(0, 0);
	this->prevState->SetCoordinates(0, 0);
}

template<typename Ty1, typename Ty2>
unsigned int GridWorldEnvironment<Ty1, Ty2>::Exit()
{
	return 1;
}

#endif