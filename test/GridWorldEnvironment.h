#ifndef GRIDWORLDEXPERIMENT
#define GRIDWORLDEXPERIMENT

#include "RLEnvironmentBase.h"
#include "GridWorldState.h"
#include "GridWorldAction.h"
#include "GridWorldReward.h"

using namespace RLENTITY_NMSPC;


class GridWorldEnvironment : RLEnvironmentBase
{
public:
	GridWorldEnvironment(int, int, int, int);
	virtual void GetState() override;
	virtual RLStateBase* GetStoredPrevState() override;
	virtual RLStateBase* GetStoredCurrState() override;
	virtual void GetReward() override;
	virtual RLRewardBase* GetStoredReward() override;
	virtual void PerformAction(RLActionBase*) override;
private:
	int xSize;
	int ySize;
	GridWorldState* goalState;
	GridWorldState* currState;
	GridWorldState* prevState;
	GridWorldReward* reward;
};

#endif