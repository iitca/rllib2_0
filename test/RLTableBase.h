#ifndef RLTABLEBASE_H
#define RLTABLEBASE_H

#include "RLStateActionBase.h"
#include <vector>
#include <map>


namespace RLENTITY_NMSPC
{
	class RLTableBase
	{
	public:
		//gets Q of the state-action
		virtual double Get(RLStateActionBase*) const = 0;
		//sets Q of the state-action
		virtual void Set(RLStateActionBase*, double) = 0;
		//gets max Q of the best action of the state
		virtual double GetMax(RLStateBase*) const = 0;
		//gets the best action in the state
		virtual RLActionBase* GetBestAction(RLStateBase*) const = 0;
		//gets the vector of pairs of actions-Qs
		virtual std::vector<std::pair<RLActionBase*, double>> GetActionsQ(RLStateBase*) const = 0;
		//check if empty
		virtual bool IsEmpty() const = 0;
	protected:
		std::map<RLStateActionBase*, double> table;
	};
}

#endif