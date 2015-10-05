#ifndef RLACTIONSELECTIONESOFTMAX_H
#define RLACTIONSELECTIONESOFTMAX_H

#include "RLActionSelectionBase.h"
#include "RLDefaultAction.h"
#include "RLTableBase.h"
#include "RLStateBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLActionSelectionSoftmax : public RLActionSelectionBase<Ty1, Ty2>
	{
	public:
		RLActionSelectionSoftmax(int);
		virtual Ty2 SelectAction(const RLTableBase<Ty1, Ty2>*, Ty1*) override;
	private:
		int t;
	};

	template<typename Ty1, typename Ty2>
	RLActionSelectionSoftmax<Ty1, Ty2>::RLActionSelectionSoftmax(int t)
	{
		if (t == 0)
			t++;
		this->t = t;
	}

	template<typename Ty1, typename Ty2>
	Ty2 RLActionSelectionSoftmax<Ty1, Ty2>::SelectAction(const RLTableBase<Ty1, Ty2>* table, Ty1* state)
	{
		//srand(time(NULL));
		double randP = rand() / RAND_MAX;
		//get the Q values of all the possible actions in the state
		Ty2 action = nullptr;
		vector<pair<Ty2*, double>> actionsQ =
			table->GetActionsQ(state);
		//get the sum of exponents of the rest of the actions
		double expSumQactions = 0.0;
		for (int i = 0; i < (int)actionsQ.size(); i++)
			expSumQactions += exp(actionsQ[i].second / this->t);
		//get the probabilities of the actions
		for (int i = 0; i < (int)actionsQ.size(); i++){
			double p = exp(actionsQ[i].second / this->t) / expSumQactions;
			//check of the action should be selected
			if (randP < p)
				return actionsQ[i].first;
		}
		//if for some reasons the action is not selected, return the best action
		action = table->GetBestAction(state);

		return action;
	}
}

#endif