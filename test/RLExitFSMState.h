#ifndef RLEXITFSMSTATE_H
#define RLEXITFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the current rlstate is observed */
	template<typename Ty1, typename Ty2>
	class RLExitFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLExitFSMState(RLFSMStatesEnum);
		/*in this state the current rl_state is fetched from the environment
		and stored in the rl_agent*/

		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLExitFSMState<Ty1, Ty2>::RLExitFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLExitFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		//returns a value to choose the next fsm state
		return rlfsm->GetRLEntity()->Exit();
	}
}

#endif