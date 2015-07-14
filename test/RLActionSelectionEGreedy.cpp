#include "RLActionSelectionEGreedy.h"
#include <stdlib.h>
#include <time.h>


using namespace RLENTITY_NMSPC;

RLActionSelectionEGreedy::RLActionSelectionEGreedy(double e)
{
	if (e <= 1 && e >= 0)
		this->e = e;
}

RLActionBase* RLActionSelectionEGreedy::SelectAction(RLTableBase* table, RLStateBase* state)
{
	RLActionBase* action = nullptr;
	srand(time(NULL));
	double r = ((double)rand() / (double)RAND_MAX);
	if (r < this->e){
		//choose the best action
		return table->GetBestAction(state);
	}else{
		//choose a random action

	}
	return action;
}