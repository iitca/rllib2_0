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
	GridWorldEnvironment* gwEnv = new GridWorldEnvironment(2, 2, 1, 1);
	//create rl table
	RLTable* rlTbl = new RLTable();
	//create rl learning algorithm
	RLLearningQ* rlLearn = new RLLearningQ(rlTbl);
	//create rl action selection
	RLActionSelectionEGreedy* rlASel = new RLActionSelectionEGreedy(0.3);
	//create rl agent
	RLAgent* rlAgent = new RLAgent(rlLearn, rlASel);
	//create finally the rl entity
	RLEntity* rlent = new RLEntity(rlAgent,gwEnv);

	//create RL fsm table
	RLFSMTransitionTable* rltt = new RLFSMTransitionTable();
	//create rlfsm
	RLFSM rlfsm(rltt, rlent);

	//create an fsm state
	RLFSMState* state = RLFSMFactory::CreateState(RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE);
	//feed the initial state
	rlfsm.SetFSMState(state);
	//go
	rlfsm.Update();
}