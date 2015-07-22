#ifndef GRIDWORLDSTATE
#define GRIDWORLDSTATE

#include "RLStateBase.h"

using namespace RLENTITY_NMSPC;

class GridWorldState : public RLStateBase
{
public:
	GridWorldState(int, int);
	void SetCoordinates(int, int);
	virtual bool operator==(RLStateBase&) const override;
private:
	int x;
	int y;
};

#endif