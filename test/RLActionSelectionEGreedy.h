#ifndef RLACTIONSELECTIONEGREEDY_H
#define RLACTIONSELECTIONEGREEDY_H

#include "RLActionSelectionBase.h"

namespace RLENTITY_NMSPC
{
	class RLActionSelectionEGreedy : public RLActionSelectionBase
	{
	public:
		RLActionSelectionEGreedy(double);
		virtual RLActionBase* SelectAction(RLTableBase*, RLStateBase*) override;
	private:
		double e;
	};

}
#endif