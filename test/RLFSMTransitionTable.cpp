#include "RLFSMTransitionTable.h"
#include <assert.h>

using namespace RLFSM_NMSPC;

RLFSMTransitionTable::RLFSMTransitionTable()
{
	std::vector<int> obsrvCurrStateTransitions = {RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE};
	std::vector<int> selActionStateTransitions = {RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE};
	std::vector<int> perfActionStateTransitions = {RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE};
	std::vector<int> obsrvNextStateTransitions = {RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE };
	std::vector<int> getRewardStateTransitions = {RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE };
	std::vector<int> adjustQStateTransitions = {RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE,
													RLFSMStatesEnum::RL_RESET_FSM_STATE };
	std::vector<int> resetStateTransitions = { RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE,
													RLFSMStatesEnum::RL_EXIT_FSM_STATE };

}

RLFSMStatesEnum RLFSMTransitionTable::GetNextFSMState(RLFSMStatesEnum state, unsigned int input)
{
	//retrieve the next 
	//state from the table 
	//if it exists
	if (this->table.size() < state){
		if (this->table[state].size() < input){
			return this->table[state][input];
		}
	}
	assert(true);
}