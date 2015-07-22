#ifndef GRIDWORLDREWARD
#define GRIDWORLDREWARD

#include "RLRewardBase.h"

using namespace RLENTITY_NMSPC;

class GridWorldReward : public RLRewardBase
{
public:
	GridWorldReward();
	GridWorldReward(double);
	virtual void SetValue(double) override;
	virtual double GetValue() override;
};

#endif