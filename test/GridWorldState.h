#ifndef GRIDWORLDSTATE
#define GRIDWORLDSTATE

#include "RLStateBase.h"

using namespace RLENTITY_NMSPC;

class GridWorldState : public RLStateBase
{
public:
	GridWorldState(){};
	GridWorldState(int, int);
	void SetCoordinates(int, int);
	int GetX();
	int GetY();
	virtual bool operator==(RLStateBase&) const override;
	virtual bool operator<(RLStateBase&) const override;
	virtual bool operator<(const RLStateBase&) const override;
private:
	int x;
	int y;
};

#endif