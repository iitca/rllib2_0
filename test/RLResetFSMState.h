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
		virtual void Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLResetFSMState<Ty1, Ty2>::RLResetFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	void RLResetFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		rlfsm->GetRLEntity()->Reset();
	}

}

#endif