#include "RLStateActionBase.h"

using namespace RLENTITY_NMSPC;

RLStateActionBase::RLStateActionBase(RLStateBase* state, RLActionBase* action)
{
	this->state = state;
	this->action = action;
}

bool RLStateActionBase::operator==(RLStateActionBase& rlStateAction) const
{
	return (this->state == rlStateAction.GetState() &&
		this->action == rlStateAction.GetAction());
}

RLStateBase* RLStateActionBase::GetState()
{
	return this->state;
}

RLActionBase* RLStateActionBase::GetAction()
{
	return this->action;
}