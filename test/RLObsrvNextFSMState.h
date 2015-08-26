#ifndef RLOBSRVNEXTFSMSTATE_H
#define RLOBSRVNEXTFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the next rlstate is observed */
	template<typename Ty1, typename Ty2>
	class RLObsrvNextFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLObsrvNextFSMState(RLFSMStatesEnum);
		/*in this state the next rl_state is fetched from the environment
		and stored in the rl_agent*/

		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLObsrvNextFSMState<Ty1, Ty2>::RLObsrvNextFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLObsrvNextFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		return rlfsm->GetRLEntity()->ObsrvNextState();
	}
}
#endif