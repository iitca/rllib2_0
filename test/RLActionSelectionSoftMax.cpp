#include "RLActionSelectionSoftmax.h"
#include <vector>


using namespace RLENTITY_NMSPC;
using namespace std;

RLActionSelectionSoftmax::RLActionSelectionSoftmax(int t)
{
	this->t = t;
}

RLActionBase* RLActionSelectionSoftmax::SelectAction(RLTableBase* table, RLStateBase* state)
{
	//get the Q values of all the possible actions in the state
	RLActionBase* action = nullptr;
	vector<pair<RLActionBase*, double>> actionsQ =
		table->GetActionsQ(state);
	//calculate

	return action;
}