#include "RLFSM.h"
#include "RLEntity.h"
#include "RLAgent.h"
#include "RLLearningQ.h"
#include "RLTable.h"
#include "RLActionSelectionEGreedy.h"
#include "GridWorldEnvironment.h"


using namespace RLFSM_NMSPC;
using namespace RLENTITY_NMSPC;

int main()
{
	//create our example environment of the size  8x8 with the goal state at x=4, y=4
	GridWorldEnvironment<GridWorldState, GridWorldAction>* gwEnv = 
		new GridWorldEnvironment<GridWorldState, GridWorldAction>(2, 2, 1, 1);

	//create rl table
	RLTable<GridWorldState, GridWorldAction>* rlTbl = 
		new RLTable<GridWorldState, GridWorldAction>();

	//create rl learning algorithm
	RLLearningQ<GridWorldState, GridWorldAction>* rlLearn = 
		new RLLearningQ<GridWorldState, GridWorldAction>(rlTbl);

	//create rl action selection
	RLActionSelectionEGreedy<GridWorldState, GridWorldAction>* rlASel = 
		new RLActionSelectionEGreedy<GridWorldState, GridWorldAction>(0.3);

	//create rl agent
	RLAgent<GridWorldState, GridWorldAction>* rlAgent = 
		new RLAgent<GridWorldState, GridWorldAction>(rlLearn, rlASel);

	//create finally the rl entity
	RLEntity<GridWorldState, GridWorldAction>* rlent = 
		new RLEntity<GridWorldState, GridWorldAction>(rlAgent, gwEnv);

	//create RL fsm table
	RLFSMTransitionTable* rltt = new RLFSMTransitionTable();

	//create rlfsm
	RLFSM<GridWorldState, GridWorldAction> rlfsm(rltt, rlent);

	//create an fsm state
	RLFSMState<GridWorldState, GridWorldAction>* state = 
		RLFSMFactory<GridWorldState, GridWorldAction>::CreateState(RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE);

	//feed the initial state
	rlfsm.SetFSMState(state);
	//go
	rlfsm.Update();
}