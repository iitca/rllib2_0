#include "RLActionSelectionSoftmax.h"
#include <vector>
#include <time.h>


using namespace RLENTITY_NMSPC;
using namespace std;

RLActionSelectionSoftmax::RLActionSelectionSoftmax(int t)
{
	if (t == 0) 
		t ++;
	this->t = t;
}

RLActionBase* RLActionSelectionSoftmax::SelectAction(RLTableBase* table, RLStateBase* state)
{
	srand(time(NULL));
	double randP = rand() / RAND_MAX;
	//get the Q values of all the possible actions in the state
	RLActionBase* action = nullptr;
	vector<pair<RLActionBase*, double>> actionsQ =
		table->GetActionsQ(state);
	//get the sum of exponents of the rest of the actions
	double expSumQactions = 0.0;
	for (int i = 0; i < (int)actionsQ.size(); i++)
		expSumQactions += exp(actionsQ[i].second/this->t);
	//get the probabilities of the actions
	for (int i = 0; i < (int)actionsQ.size(); i++){
		double p = exp(actionsQ[i].second/this->t) / expSumQactions;
		//check of the action should be selected
		if (randP < p)
			return actionsQ[i].first;
	}

}