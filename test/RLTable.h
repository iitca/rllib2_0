#ifndef RLTABLE_H
#define RLTABLE_H

#include "RLTableBase.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>

namespace RLENTITY_NMSPC
{
	//types: state, action
	template<typename Ty1, typename Ty2>
	class RLTable : public RLTableBase<Ty1, Ty2>
	{
	public:
		//gets Q of the state-action
		virtual double Get(RLStateActionBase<Ty1, Ty2>) const override;
		//sets Q of the state-action
		virtual void Set(RLStateActionBase<Ty1, Ty2>, double) override;
		//gets max Q of the best action of the state
		virtual double GetMax(Ty1*) const override;
		//gets the best action in the state
		virtual Ty2 GetBestAction(Ty1*) const override;
		//gets the vector of pairs of actions-Qs
		virtual std::vector<std::pair<Ty2, double>> GetActionsQ(Ty1*) const override; 
		//checks if the table is empty
		virtual bool IsEmpty() const override;
		//returns the table
		virtual std::map<RLStateActionBase<Ty1, Ty2>, double> GetTable() override;

	};

	template<typename Ty1, typename Ty2>
	double RLTable<Ty1, Ty2>::Get(RLStateActionBase<Ty1, Ty2> stateAction) const
	{
		//check if the element exists
		if (this->table.count(stateAction))
			return this->table.at(stateAction);
		return 0.0;
	}

	template<typename Ty1, typename Ty2>
	void RLTable<Ty1, Ty2>::Set(RLStateActionBase<Ty1, Ty2> stateAction, double q)
	{
		//check if the element exists
		if (this->table.count(stateAction))
			this->table[stateAction] = q;
		else
			//there is a new value
			this->table.insert(std::make_pair(stateAction, q));
	}

	template<typename Ty1, typename Ty2>
	double RLTable<Ty1, Ty2>::GetMax(Ty1* state) const
	{
		//get the best action
		Ty2 bestAction = GetBestAction(state);
		//create a stateaction
		RLStateActionBase<Ty1, Ty2>* stateAction = new RLStateActionBase<Ty1, Ty2>(*state, bestAction);
		//now get the Q of the best action in the state
		double Qmax = this->Get(*stateAction);
		return Qmax;
	}

	template<typename Ty1, typename Ty2>
	Ty2 RLTable<Ty1, Ty2>::GetBestAction(Ty1* state) const
	{
		Ty2 action;
		double Qmax = 0.0;
		bool init = false;
		//if the table is empty
		if (this->table.empty())
			return action;
		//get the iterator
		std::map<RLStateActionBase<Ty1, Ty2>, double>::const_iterator it = this->table.begin();

		it->first.GetState();
		//iterate through all table's entries
		for (; it != table.end(); it++){
			if (it->first.GetState() == *state){
				if (!init){
					//initialize Qmax with the first value
					init = true;
					action = it->first.GetAction();
					Qmax = this->Get(it->first);
				}
				else{
					//choose the max Q
					if (this->Get(it->first) > Qmax){
						Qmax = this->Get(it->first);
						action = it->first.GetAction();
					}
				}
			}
		}

		return action;
	}

	template<typename Ty1, typename Ty2>
	std::vector<std::pair<Ty2, double>> RLTable<Ty1, Ty2>::GetActionsQ(Ty1* state) const
	{
		std::vector<std::pair<Ty2, double>> actionsQ;
		std::map<RLStateActionBase<Ty1, Ty2>, double>::const_iterator it = this->table.begin();
		for (; it != this->table.end(); it++){
			if (it->first.GetState() == *state){
				//push it to the vector
				actionsQ.push_back(std::make_pair(it->first.GetAction(), it->second));
			}
		}
		return actionsQ;
	}

	template<typename Ty1, typename Ty2>
	bool RLTable<Ty1, Ty2>::IsEmpty() const
	{
		return this->table.empty();
	}

	template<typename Ty1, typename Ty2>
	std::map<RLStateActionBase<Ty1, Ty2>, double> RLTable<Ty1, Ty2>::GetTable()
	{
		return this->table;
	}

}

#endif