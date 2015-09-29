#ifndef RLAGENT
#define RLAGENT

#include "RLAgentBase.h"
#include "RLLearningBase.h"
#include "RLActionBase.h"
#include "RLStateActionBase.h"
#include "RLActionSelectionBase.h"
#include "RLTableBase.h"

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLAgent : public RLAgentBase<Ty1, Ty2>
	{
	public:
		RLAgent(RLLearningBase<Ty1, Ty2>* learning, RLActionSelectionBase<Ty1, Ty2>* actionSelection) : RLAgentBase(learning, actionSelection){};
		virtual unsigned int SelAction(Ty1*) override;
		virtual Ty2 GetStoredAction() override;
		virtual void AdjQ(Ty1*, Ty1*, RLRewardBase*) override;
		virtual std::map<RLStateActionBase<Ty1, Ty2>, double> GetTable() override;
		virtual void StoreToTable(RLStateActionBase<Ty1, Ty2>, double) override;
	};

	template<typename Ty1, typename Ty2>
	unsigned int RLAgent<Ty1, Ty2>::SelAction(Ty1* state)
	{
		//here the new action is selected using one of the action selection algorithms
		//greedy, argmax, softmax
		this->rlAction = this->rlActionSelection->
			SelectAction(this->rlLearning->GetTable(), state);
		//the returned value will be used to select the next state
		return 0;
	}

	template<typename Ty1, typename Ty2>
	Ty2 RLAgent<Ty1, Ty2>::GetStoredAction()
	{
		return this->rlAction;
	}

	template<typename Ty1, typename Ty2>
	void RLAgent<Ty1, Ty2>::AdjQ(Ty1* statePrev, Ty1* stateCurr, RLRewardBase* reward)
	{
		//create a state-action
		RLStateActionBase<Ty1, Ty2> stateAction(*statePrev, this->rlAction);
		//update a table, using the obtained state-action
		this->rlLearning->Update(stateAction, stateCurr, reward);
	}

	template<typename Ty1, typename Ty2>
	std::map<RLStateActionBase<Ty1, Ty2>, double> RLAgent<Ty1, Ty2>::GetTable()
	{
		return this->rlLearning->GetTable()->GetTable();
	}

	template<typename Ty1, typename Ty2>
	void RLAgent<Ty1, Ty2>::StoreToTable(RLStateActionBase<Ty1, Ty2> stateAction, double Q)
	{
		this->rlLearning->GetTable()->Set(stateAction, Q);
	}

}

#endif