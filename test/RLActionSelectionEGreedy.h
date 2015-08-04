#ifndef RLACTIONSELECTIONEGREEDY_H
#define RLACTIONSELECTIONEGREEDY_H

#include "RLActionSelectionBase.h"
#include "RLDefaultAction.h"

namespace RLENTITY_NMSPC
{
	class RLActionSelectionEGreedy : public RLActionSelectionBase
	{
	public:
		RLActionSelectionEGreedy(double);
		virtual RLActionBase* SelectAction(const RLTableBase*, RLStateBase*) override;
	private:
		//this value represents the probability of taking the best action
		double e;
	};

}
#endif 