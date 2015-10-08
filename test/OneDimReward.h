#ifndef ONEDIMREWARD
#define ONEDIMREWARD

#include "RLRewardBase.h"

using namespace RLENTITY_NMSPC;

class OneDimReward : public RLRewardBase
{
public:
	OneDimReward();
	OneDimReward(double);
	virtual void SetValue(double) override;
	virtual double GetValue() override;
};

#endif