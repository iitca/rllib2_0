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
	RLActionBase* action = nullptr;
	srand(time(NULL));
	double r = ((double)rand() / (double)RAND_MAX);

	if (r >= this->e){
		//get an action and randomize it
		action = table->GetBestAction(state);
		action->Randomize();
	}else{
		action = table->GetBestAction(state);
	}

	//if the action is nullptr, then the random action should be created
	action = new RLActionBase();

	return action;
}