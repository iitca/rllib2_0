#ifndef RLRESETFSMSTATE_H
#define RLRESETFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the experiment is reset*/
	template<typename Ty1, typename Ty2>
	class RLResetFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLResetFSMState(RLFSMStatesEnum);

		/*in this state the experiment is reset*/
		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLResetFSMState<Ty1, Ty2>::RLResetFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLResetFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		//returns a value to choose the next fsm state
		return rlfsm->GetRLEntity()->Reset();
	}

}

#endif