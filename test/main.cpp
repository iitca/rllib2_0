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
	//create our example environment of the size  2x2 with the goal state at x=1, y=1
	GridWorldEnvironment<GridWorldState, GridWorldAction>* gwEnv = 
		new GridWorldEnvironment<GridWorldState, GridWorldAction>(20, 20, 10, 10, 10000);

	//create rl table
	RLTable<GridWorldState, GridWorldAction>* rlTbl = 
		new RLTable<GridWorldState, GridWorldAction>();

	//create rl learning algorithm
	RLLearningQ<GridWorldState, GridWorldAction>* rlLearn = 
		new RLLearningQ<GridWorldState, GridWorldAction>(rlTbl);

	//create rl action selection (e = 0.0 meaning that the action is always selected randomly)
	RLActionSelectionEGreedy<GridWorldState, GridWorldAction>* rlASel = 
		new RLActionSelectionEGreedy<GridWorldState, GridWorldAction>(0.0);

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