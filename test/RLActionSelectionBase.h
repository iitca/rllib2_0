#ifndef RLACTIONSELECTIONBASE_H
#define RLACTIONSELECTIONBASE_H

#include "RLTableBase.h"
#include "RLStateBase.h"
#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	class RLActionSelectionBase
	{
	public:
		virtual RLActionBase* SelectAction(const RLTableBase*, RLStateBase*) = 0;
	};
}

#endif