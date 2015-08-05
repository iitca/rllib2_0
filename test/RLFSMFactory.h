#ifndef RLFSMFACTORY_H
#define RLFSMFACTORY_H

#include "RLFSMStatesEnum.h"
#include "RLFSMState.h"
#include "RLObsrvCurrentFSMState.h"
#include "RLObsrvNextFSMState.h"
#include "RLSelActionFSMState.h"
#include "RLPerfActionFSMState.h"
#include "RLGetRewardFSMState.h"
#include "RLAdjQFSMState.h"


namespace RLFSM_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLFSMState;

	template<typename Ty1, typename Ty2>
	class RLFSMFactory
	{
	public:
		static RLFSMState<Ty1, Ty2>* CreateState(RLFSMStatesEnum);
	};

	template<typename Ty1, typename Ty2>
	RLFSMState<Ty1, Ty2>* RLFSMFactory<Ty1, Ty2>::CreateState(RLFSMStatesEnum stateEnum)
	{
		RLFSMState<Ty1, Ty2>* state;
		switch (stateEnum)
		{
		case RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE:
		{
			state = new	RLObsrvCurrentFSMState<Ty1, Ty2>(RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE);
			break;
		}
		case RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE:
		{
			state = new RLSelActionFSMState<Ty1, Ty2>(RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE);
			break;
		}
		case RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE:
		{
			state = new RLPerfActionFSMState<Ty1, Ty2>(RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE);
			break;
		}
		case RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE:
		{
			state = new RLObsrvNextFSMState<Ty1, Ty2>(RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE);
			break;
		}
		case RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE:
		{
			state = new RLGetRewardFSMState<Ty1, Ty2>(RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE);
			break;
		}
		case RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE:
		{
			state = new RLAdjQFSMState<Ty1, Ty2>(RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE);
			break;
		}
		default:{}
		}
		return state;
	}
}

#endif