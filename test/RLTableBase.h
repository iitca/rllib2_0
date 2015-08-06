#ifndef RLTABLEBASE_H
#define RLTABLEBASE_H

#include "RLStateActionBase.h"
#include <vector>
#include <map>



namespace RLENTITY_NMSPC
{
	//types: state, action
	template<typename Ty1, typename Ty2>
	class RLTableBase
	{
	public:
		//gets Q of the state-action
		virtual double Get(RLStateActionBase<Ty1, Ty2>) const = 0;
		//sets Q of the state-action
		virtual void Set(RLStateActionBase<Ty1, Ty2>, double) = 0;
		//gets max Q of the best action of the state
		virtual double GetMax(Ty1*) const = 0;
		//gets the best action in the state
		virtual Ty2 GetBestAction(Ty1*) const = 0;
		//gets the vector of pairs of actions-Qs
		virtual std::vector<std::pair<Ty2, double>> GetActionsQ(Ty1*) const = 0;
		//check if empty
		virtual bool IsEmpty() const = 0;
	protected:
		std::map<RLStateActionBase<Ty1, Ty2>, double> table;
	};
}

#endif