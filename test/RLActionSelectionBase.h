#ifndef RLACTIONSELECTIONBASE_H
#define RLACTIONSELECTIONBASE_H

#include "RLTableBase.h"
#include "RLStateBase.h"
#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLActionSelectionBase
	{
	public:
		virtual Ty2 SelectAction(const RLTableBase<Ty1, Ty2>*, Ty1*) = 0;
	};
}

#endif