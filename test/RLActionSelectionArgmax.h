#ifndef RLACTIONSELECTIONEARGMAX_H
#define RLACTIONSELECTIONEARGMAX_H

#include "RLActionSelectionBase.h"

namespace RLENTITY_NMSPC
{
	class RLActionSelectionArgmax : public RLActionSelectionBase
	{
	public:
		virtual RLActionBase* SelectAction(RLTableBase*, RLStateBase*) override;
	};

}

#endif