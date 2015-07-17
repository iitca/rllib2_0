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
		RLActionSelectionSoftmax(int);
		virtual RLActionBase* SelectAction(const RLTableBase*, RLStateBase*) override;
	private:
		int t;
	};

}

#endif