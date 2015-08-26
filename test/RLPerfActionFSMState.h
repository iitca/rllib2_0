#ifndef RLPERFACTIONFSMSTATE_H
#define RLPERFACTIONFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the chosen action is performed */
	template<typename Ty1, typename Ty2>
	class RLPerfActionFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLPerfActionFSMState(RLFSMStatesEnum);
		/*in this state the chosen action is performed */

		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLPerfActionFSMState<Ty1, Ty2>::RLPerfActionFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLPerfActionFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		return rlfsm->GetRLEntity()->PerfAction();
	}
}

#endif