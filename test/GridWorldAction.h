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


class GridWorldAction : public RLActionBase
{
public:
	GridWorldAction(){};
	GridWorldAction(int _val) : value(_val){};
	virtual bool operator==(RLActionBase&) const override;
	virtual bool operator<(const RLActionBase&) const override;
	virtual void Randomize() override;
	virtual int GetValue() override;
	virtual void SetValue(int) override;
private:
	int value;
};



#endif