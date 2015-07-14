#include "RLActionSelectionArgmax.h"

using namespace RLENTITY_NMSPC;

RLActionBase* RLActionSelectionArgmax::SelectAction(RLTableBase* table, RLStateBase* state)
{
	return table->GetBestAction(state);
}