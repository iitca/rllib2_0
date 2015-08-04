#ifndef RLACTIONSELECTIONEARGMAX_H
#define RLACTIONSELECTIONEARGMAX_H

#include "RLActionSelectionBase.h"
#include "RLDefaultAction.h"

namespace RLENTITY_NMSPC
{
	class RLActionSelectionArgmax : public RLActionSelectionBase
	{
	public:
		virtual RLActionBase* SelectAction(const RLTableBase*, RLStateBase*) override;
	};

}

#endif