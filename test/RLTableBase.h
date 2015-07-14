#ifndef RLTABLEBASE_H
#define RLTABLEBASE_H

#include "RLStateActionBase.h"
#include <map>

namespace RLENTITY_NMSPC
{
	class RLTableBase
	{
	public:
		//gets Q of the state-action
		virtual double Get(RLStateActionBase*) = 0;
		//sets Q of the state-action
		virtual void Set(RLStateActionBase*, double) = 0;
		//gets max Q of the best action of the state
		virtual double GetMax(RLStateBase*) = 0;
		//gets the best action in the state
		virtual RLActionBase* GetBestAction(RLStateBase*) = 0;
		//gets a random action in the state
		virtual RLActionBase* GetRandAction(RLStateBase*) = 0;
	protected:
		std::map<RLStateActionBase*, double> table;
	};
}

#endif