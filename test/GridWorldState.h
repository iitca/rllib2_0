#ifndef GRIDWORLDSTATE
#define GRIDWORLDSTATE

#include "RLStateBase.h"
#include <sstream>
#include <iostream>

using namespace RLENTITY_NMSPC;

class GridWorldState : public RLStateBase
{
public:
	GridWorldState(){};
	GridWorldState(int, int);
	GridWorldState(std::string);
	void SetCoordinates(int, int);
	int GetX() const;
	int GetY() const;
	virtual bool operator==(RLStateBase&) const override;
	virtual bool operator==(const RLStateBase&) const ;
	virtual bool operator<(const RLStateBase&) const override;
private:
	friend std::ostream& operator<<(std::ostream &os, const GridWorldState& state);
	int x;
	int y;
};

#endif