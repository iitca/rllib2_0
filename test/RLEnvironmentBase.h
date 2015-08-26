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
		virtual unsigned int GetState() = 0;
		virtual Ty1* GetStoredPrevState() = 0;
		virtual Ty1* GetStoredCurrState() = 0;
		virtual unsigned int GetReward() = 0;
		virtual RLRewardBase* GetStoredReward() = 0;
		virtual unsigned int PerformAction(Ty2) = 0;
		virtual unsigned int Reset() = 0;
		virtual unsigned int Exit() = 0;
	};
}

#endif 