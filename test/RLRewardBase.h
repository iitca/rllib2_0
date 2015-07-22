#ifndef RLREWARDBASE_H
#define RLREWARDBASE_H

#include "RLStateBase.h"

namespace RLENTITY_NMSPC
{
	class RLRewardBase
	{
	public:
		virtual void SetValue(double) = 0;
		virtual double GetValue() = 0;
	protected:
		double value;
	};
}

#endif