#ifndef RLACTIONSELECTIONESOFTMAX_H
#define RLACTIONSELECTIONESOFTMAX_H

#include "RLActionSelectionBase.h"
#include "RLTableBase.h"
#include "RLStateBase.h"

namespace RLENTITY_NMSPC
{
	class RLActionSelectionSoftmax : public RLActionSelectionBase
	{
	public:
		virtual RLActionBase* SelectAction(RLTableBase*, RLStateBase*) override;
	};

}

#endif