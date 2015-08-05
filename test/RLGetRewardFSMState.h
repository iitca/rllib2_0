#ifndef RLGETREWARDFSMSTATE_H
#define RLGETREWARDFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the reward is obtained for the environment */
	template<typename Ty1, typename Ty2>
	class RLGetRewardFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLGetRewardFSMState(RLFSMStatesEnum);
		/*in this state the rewarde is fetched from the environment
		to recalculate Q*/

		virtual void Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLGetRewardFSMState<Ty1, Ty2>::RLGetRewardFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	void RLGetRewardFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		rlfsm->GetRLEntity()->GetReward();
	}
}

#endif