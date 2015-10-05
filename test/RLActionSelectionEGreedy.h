#ifndef RLACTIONSELECTIONEGREEDY_H
#define RLACTIONSELECTIONEGREEDY_H

#include "RLActionSelectionBase.h"
#include "RLDefaultAction.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLActionSelectionEGreedy : public RLActionSelectionBase<Ty1, Ty2>
	{
	public:
		RLActionSelectionEGreedy(double);
		virtual Ty2 SelectAction(const RLTableBase<Ty1, Ty2>*, Ty1*) override;
	private:
		//this value represents the probability of taking the best action
		double e;
	};

	template<typename Ty1, typename Ty2>
	RLActionSelectionEGreedy<Ty1, Ty2>::RLActionSelectionEGreedy(double e)
	{
		if (e >= 0 && e <= 1)
			this->e = e;
		else
			e = 0.5;
	}

	template<typename Ty1, typename Ty2>
	Ty2 RLActionSelectionEGreedy<Ty1, Ty2>::
		SelectAction(const RLTableBase<Ty1, Ty2>* table, Ty1* state)
	{
		//the action to return
		Ty2 action;
		//srand(time(NULL));
		double r = ((double)rand() / (double)RAND_MAX);

		//
		action = table->GetBestAction(state);
		//check if to select the best action
		if (r >= this->e)
			action.Randomize();

		return action;
	}

}
#endif 