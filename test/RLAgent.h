#ifndef RLAGENT
#define RLAGENT

#include "RLAgentBase.h"
#include "RLLearningBase.h"
#include "RLActionBase.h"
#include "RLStateActionBase.h"
#include "RLActionSelectionBase.h"

namespace RLENTITY_NMSPC
{
	class RLAgent : public RLAgentBase
	{
	public:
		RLAgent(RLLearningBase* learning, RLActionSelectionBase* actionSelection) : RLAgentBase(learning, actionSelection){};
		virtual void SelAction(RLStateBase*) override;
		virtual RLActionBase* GetStoredAction() override;
		virtual void AdjQ(RLStateBase*, RLStateBase*, RLRewardBase*) override;
	};
}

#endif