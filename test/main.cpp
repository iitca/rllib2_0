#include "RLFSM.h"
#include "RLEntity.h"
#include "RLAgent.h"
#include "RLLearningQ.h"
#include "RLTable.h"
#include "RLActionSelectionEGreedy.h"
#include "GridWorldEnvironment.h"
#include "OneDimEnvironment.h"


using namespace RLFSM_NMSPC;
using namespace RLENTITY_NMSPC;

int main()
{
	//create our example environment of the size  2x2 with the goal state at x=1, y=1
	OneDimEnvironment<OneDimState, OneDimAction>* gwEnv =
		new OneDimEnvironment<OneDimState, OneDimAction>(10000);

	//create rl table
	RLTable<OneDimState, OneDimAction>* rlTbl =
		new RLTable<OneDimState, OneDimAction>();

	//create rl learning algorithm
	RLLearningQ<OneDimState, OneDimAction>* rlLearn =
		new RLLearningQ<OneDimState, OneDimAction>(rlTbl);

	//create rl action selection (e = 0.0 meaning that the action is always selected randomly)
	RLActionSelectionEGreedy<OneDimState, OneDimAction>* rlASel =
		new RLActionSelectionEGreedy<OneDimState, OneDimAction>(0.0);

	//create rl agent
	RLAgent<OneDimState, OneDimAction>* rlAgent =
		new RLAgent<OneDimState, OneDimAction>(rlLearn, rlASel);

	//create finally the rl entity
	RLEntity<OneDimState, OneDimAction>* rlent =
		new RLEntity<OneDimState, OneDimAction>(rlAgent, gwEnv);

	//create RL fsm table
	RLFSMTransitionTable* rltt = new RLFSMTransitionTable();

	//create rlfsm
	RLFSM<OneDimState, OneDimAction> rlfsm(rltt, rlent);

	//create an fsm state
	RLFSMState<OneDimState, OneDimAction>* state =
		RLFSMFactory<OneDimState, OneDimAction>::CreateState(RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE);

	//feed the initial state
	rlfsm.SetFSMState(state);
	//go
	rlfsm.Update();
}