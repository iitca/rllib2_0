#ifndef RLENVIRONMENTBASE_H
#define RLENVIRONMENTBASE_H

#include "RLActionBase.h"
#include "RLStateBase.h"
#include "RLRewardBase.h"
#include "RLStateActionBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLEnvironmentBase
	{
	public:
		RLEnvironmentBase(){};
		virtual void GetState() = 0;
		virtual Ty1* GetStoredPrevState() = 0;
		virtual Ty1* GetStoredCurrState() = 0;
		virtual void GetReward() = 0;
		virtual RLRewardBase* GetStoredReward() = 0;
		virtual void PerformAction(Ty2) = 0;
		virtual void Reset() = 0;
	};
}

#endif 