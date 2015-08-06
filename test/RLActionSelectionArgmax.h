#ifndef RLACTIONSELECTIONEARGMAX_H
#define RLACTIONSELECTIONEARGMAX_H

#include "RLActionSelectionBase.h"
#include "RLDefaultAction.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLActionSelectionArgmax : public RLActionSelectionBase<Ty1, Ty2>
	{
	public:
		virtual Ty2 SelectAction(const RLTableBase<Ty1, Ty2>*, Ty1*) override;
	};

	template<typename Ty1, typename Ty2>
	Ty2 RLActionSelectionArgmax<Ty1, Ty2>::
		SelectAction(const RLTableBase<Ty1, Ty2>* table, Ty1* state)
	{
		//action to return
		Ty2 action;
		//get the best available action
		action = table->GetBestAction(state);
		//check if the action has been fetched
		return action;
	}

}

#endif