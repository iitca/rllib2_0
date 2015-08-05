#ifndef RLADJQFSMSTATE_H
#define RLADJQFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state Q is recalculated */
	template<typename Ty1, typename Ty2>
	class RLAdjQFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLAdjQFSMState(RLFSMStatesEnum);
		/*in this state the Q is recalculated based on old Q, reward, previous and current state as well as
		an action*/
		virtual void Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLAdjQFSMState<Ty1, Ty2>::RLAdjQFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	void RLAdjQFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		rlfsm->GetRLEntity()->AdjQ();
	}
}

#endif