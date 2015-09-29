#ifndef RLLEARNINGBASE_H
#define RLLEARNINGBASE_H

#include "RLStateActionBase.h"
#include "RLRewardBase.h"
#include "RLTableBase.h"

namespace RLENTITY_NMSPC
{
	//types: state, action
	template<typename Ty1, typename Ty2>
	class RLLearningBase
	{
	public:
		RLLearningBase(RLTableBase<Ty1, Ty2>* tbl) : table(tbl){};
		virtual void Update(RLStateActionBase<Ty1, Ty2>, Ty1*, RLRewardBase*) = 0;
		virtual RLTableBase<Ty1, Ty2>* GetTable() = 0;
	protected:
		RLTableBase<Ty1, Ty2>* table;
	};
}

#endif