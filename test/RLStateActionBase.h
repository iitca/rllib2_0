#ifndef RLSTATEACTION_H
#define RLSTATEACTION_H

#include "RLStateBase.h"
#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	class RLStateActionBase
	{
	public:
		RLStateActionBase(RLStateBase*, RLActionBase*);
		virtual bool operator==(RLStateActionBase&) const;
		virtual bool operator<(RLStateActionBase&) const;
		virtual RLStateBase* GetState();
		virtual RLActionBase* GetAction();
	private:
		RLStateBase* state;
		RLActionBase* action;
	};

}

#endif