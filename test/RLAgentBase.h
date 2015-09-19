#ifndef RLAGENTBASE_H
#define RLAGENTBASE_H

#include "RLStateBase.h"
#include "RLLearningBase.h"
#include "RLActionBase.h"
#include "RLStateActionBase.h"
#include "RLActionSelectionBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLAgentBase
	{
	public:
		RLAgentBase(RLLearningBase<Ty1, Ty2>* learning, RLActionSelectionBase<Ty1, Ty2>* actionSelection)
			: rlLearning(learning), rlActionSelection(actionSelection){};
		virtual unsigned int SelAction(Ty1*) = 0;
		virtual Ty2 GetStoredAction() = 0;
		virtual void AdjQ(Ty1*, Ty1*, RLRewardBase*) = 0;
	protected:
		RLLearningBase<Ty1, Ty2>* rlLearning;
		Ty2 rlAction;
		RLActionSelectionBase<Ty1, Ty2>* rlActionSelection;
	};
}

#endif 