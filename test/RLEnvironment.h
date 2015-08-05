#ifndef RLENVIRONMENT_H
#define RLENVIRONMENT_H

#include "RLEnvironmentBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLEnvironment : public RLEnvironmentBase<Ty1, Ty2>
	{
	public:
		RLEnvironment() : RLEnvironmentBase(){};
		virtual void GetState() override;
		virtual Ty1* GetStoredPrevState() override;
		virtual Ty1* GetStoredCurrState() override;
		virtual void GetReward() override;
		virtual RLRewardBase* GetStoredReward() override;
		virtual void PerformAction(Ty2*) override;
	};
}

#endif