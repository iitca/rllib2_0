#ifndef RLFSMTRANSITIONTABLE_H
#define RLFSMTRANSITIONTABLE_H

#include "RLFSMFactory.h"
#include "RLFSMStateInput.h"
#include <vector>

namespace RLFSM_NMSPC
{

	/*this class represents a transition sequence*/
	class RLFSMTransitionTable
	{
	public:
		RLFSMTransitionTable();
		RLFSMStatesEnum GetNextFSMState(RLFSMStatesEnum, unsigned int);
	private:
		std::vector<std::vector<RLFSMStatesEnum>> table;
	};
}

#endif