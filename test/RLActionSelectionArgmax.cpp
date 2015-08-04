#include "RLActionSelectionArgmax.h"

using namespace RLENTITY_NMSPC;

RLActionBase* RLActionSelectionArgmax::
	SelectAction(const RLTableBase* table, RLStateBase* state)
{
	//action to return
	RLActionBase* action = nullptr;
	//get the best available action
	action = table->GetBestAction(state);
	//check if the action has been fetched
	if (action = nullptr){
		RLActionBase* action = new RLDefaultAction(0);
		action->Randomize();
	}
	return action;
}