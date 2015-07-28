#ifndef RLENVIRONMENTBASE_H
#define RLENVIRONMENTBASE_H

#include "RLActionBase.h"
#include "RLStateBase.h"
#include "RLRewardBase.h"
#include "RLStateActionBase.h"

namespace RLENTITY_NMSPC
{
	class RLEnvironmentBase
	{
	public:
		RLEnvironmentBase(){};
		virtual void GetState() = 0;
		virtual RLStateBase* GetStoredPrevState() = 0;
		virtual RLStateBase* GetStoredCurrState() = 0;
		virtual void GetReward() = 0;
		virtual RLRewardBase* GetStoredReward() = 0;
		virtual void PerformAction(RLActionBase*) = 0;
	};
}

#endif 