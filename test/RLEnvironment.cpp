#include "RLEnvironment.h"

using namespace RLENTITY_NMSPC;

void RLEnvironment::GetState()
{

}
RLStateBase* RLEnvironment::GetStoredCurrState()
{
	return this->currState;
}

RLStateBase* RLEnvironment::GetStoredPrevState()
{
	return this->prevState;
}
void RLEnvironment::GetReward()
{

}
RLRewardBase* RLEnvironment::GetStoredReward()
{
	return this->reward;
}
void RLEnvironment::PerformAction(RLActionBase*)
{

}