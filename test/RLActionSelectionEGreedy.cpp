#include "RLActionSelectionEGreedy.h"
#include <stdlib.h>
#include <time.h>


using namespace RLENTITY_NMSPC;

RLActionSelectionEGreedy::RLActionSelectionEGreedy(double e)
{
	if (e >= 0 && e <= 1)
		this->e = e;
	else
		e = 0.5;
}

RLActionBase* RLActionSelectionEGreedy::
	SelectAction(const RLTableBase* table, RLStateBase* state)
{
	//the action to return
	RLActionBase* action = nullptr;
	srand(time(NULL));
	double r = ((double)rand() / (double)RAND_MAX);

	//
	action = table->GetBestAction(state);
	//check if to select the best action
	if (action != nullptr &&
			r >= this->e){
		action->Randomize();
	}

	//if the action has not been instantiated
	if (action == nullptr)
		action = new RLDefaultAction(0);
	
	//the action is ready
	return action;
}