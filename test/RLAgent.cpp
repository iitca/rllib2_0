#include "RLAgent.h"

using namespace RLENTITY_NMSPC;

void RLAgent::SelAction(RLStateBase* state)
{
	//here the new action is selected using one of the action selection algorithms
	//greedy, argmax, softmax
	this->rlAction = this->rlActionSelection->
			SelectAction(this ->rlLearning ->GetTable(), state);
}

RLActionBase* RLAgent::GetStoredAction()
{
	return this->rlAction;
}

void RLAgent::AdjQ(RLStateBase* statePrev, RLStateBase* stateCurr, RLRewardBase* reward)
{
	//create a state-action
	RLStateActionBase* stateAction = new RLStateActionBase(statePrev, this->rlAction);
	//update a table, using the obtained state-action
	this->rlLearning->Update(stateAction, stateCurr, reward);
}