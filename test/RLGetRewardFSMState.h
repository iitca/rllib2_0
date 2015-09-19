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

		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLGetRewardFSMState<Ty1, Ty2>::RLGetRewardFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLGetRewardFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		//returns a value to choose the next fsm state
		return rlfsm->GetRLEntity()->GetReward();
	}
}

#endif