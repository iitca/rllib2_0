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
		virtual RLActionBase* SelectAction(RLTableBase*, RLStateBase*) = 0;
	};
}

#endif