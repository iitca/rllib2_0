#ifndef GRIDWORLDACTION
#define GRIDWORLDACTION

#include "RLActionBase.h"

using namespace RLENTITY_NMSPC;

enum Direction
{
	NORTH,
	WEST,
	SOUTH,
	EAST,
	DIR_NUM
};

class GridWorldAction : RLActionBase
{
public:
	GridWorldAction(int);
	virtual bool operator==(RLActionBase&) const override;
	virtual void Randomize() override;
	virtual int GetValue() override;
	
};

#endif