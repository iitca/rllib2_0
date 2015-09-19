#include "RLFSMTransitionTable.h"
#include <assert.h>

using namespace RLFSM_NMSPC;

RLFSMTransitionTable::RLFSMTransitionTable()
{
	std::vector<RLFSMStatesEnum> obsrvCurrStateTransitions = {RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE};
	std::vector<RLFSMStatesEnum> selActionStateTransitions = { RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE };
	std::vector<RLFSMStatesEnum> perfActionStateTransitions = { RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE };
	std::vector<RLFSMStatesEnum> obsrvNextStateTransitions = { RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE };
	std::vector<RLFSMStatesEnum> getRewardStateTransitions = { RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE };
	std::vector<RLFSMStatesEnum> adjustQStateTransitions = { RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE,
													RLFSMStatesEnum::RL_RESET_FSM_STATE };
	std::vector<RLFSMStatesEnum> resetStateTransitions = { RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE,
													RLFSMStatesEnum::RL_EXIT_FSM_STATE };

	this->table.push_back(obsrvCurrStateTransitions);
	this->table.push_back(selActionStateTransitions);
	this->table.push_back(perfActionStateTransitions);
	this->table.push_back(obsrvNextStateTransitions);
	this->table.push_back(getRewardStateTransitions);
	this->table.push_back(adjustQStateTransitions);
	this->table.push_back(resetStateTransitions);


}

RLFSMStatesEnum RLFSMTransitionTable::GetNextFSMState(RLFSMStatesEnum state, unsigned int input)
{
	//retrieve the next 
	//state from the table 
	//if it exists
	if (state < this->table.size()){
		if (input < this->table[state].size()){
			return this->table[state][input];
		}
	}
	assert(true);
}