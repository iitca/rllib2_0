#ifndef RLTABLE_H
#define RLTABLE_H

#include "RLTableBase.h"
#include <stdlib.h>
#include <time.h>

namespace RLENTITY_NMSPC
{
	class RLTable : public RLTableBase
	{
	public:
		//gets Q of the state-action
		virtual double Get(RLStateActionBase*) override;
		//sets Q of the state-action
		virtual void Set(RLStateActionBase*, double) override;
		//gets max Q of the best action of the state
		virtual double GetMax(RLStateBase*) override;
		//gets the best action in the state
		virtual RLActionBase* GetBestAction(RLStateBase*) override;
		//gets the vector of pairs of actions-Qs
		virtual std::vector<std::pair<RLActionBase*, double>> GetActionsQ(RLStateBase*) override;
	};
}

#endif