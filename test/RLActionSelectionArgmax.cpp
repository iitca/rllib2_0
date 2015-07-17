#include "RLActionSelectionArgmax.h"

using namespace RLENTITY_NMSPC;

RLActionBase* RLActionSelectionArgmax::
	SelectAction(const RLTableBase* table, RLStateBase* state)
{
	return table->GetBestAction(state);
}