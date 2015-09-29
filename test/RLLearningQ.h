#ifndef RLLEARNING_H
#define RLLEARNING_H

#include "RLLearningBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLLearningQ : public RLLearningBase<Ty1, Ty2>
	{
	public:
		RLLearningQ(RLTableBase<Ty1, Ty2>* tbl) : RLLearningBase(tbl){};
		virtual void Update(RLStateActionBase<Ty1, Ty2>, Ty1*, RLRewardBase*) override;
		virtual RLTableBase<Ty1, Ty2>* GetTable() override;
	};


	template<typename Ty1, typename Ty2>
	void RLLearningQ<Ty1, Ty2>::Update(RLStateActionBase<Ty1, Ty2> stateActionPrev, Ty1* state, RLRewardBase* reward)
	{
		/*
		here we update a table with a new value, calculated according to:
		diff = (r + gamma*Qmax)-Q -> Q here is the value,
		assigned to the previous state with the current action
		Q := Q + alpha * diff
		*/

		//old Q of the previous state-action
		double Qold = this->table->Get(stateActionPrev);
		//Qmax of the current state
		double Qmax = this->table->GetMax(state);

		//arbitrary learning rate and discount factor for the time being
		double alpha = 0.5;
		double gamma = 0.9;

		//new Q
		double Qnew = Qold + alpha * (reward->GetValue() + gamma * Qmax - Qold);

		//set the new value to the table
		this->table->Set(stateActionPrev, Qnew);
	}

	template<typename Ty1, typename Ty2>
	RLTableBase<Ty1, Ty2>* RLLearningQ<Ty1, Ty2>::GetTable()
	{
		return this->table;
	}
}

#endif