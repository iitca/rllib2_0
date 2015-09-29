#ifndef GRIDWORLDACTION
#define GRIDWORLDACTION

#include "RLActionBase.h"
#include <iostream>
#include <sstream>

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
	GridWorldAction() : value(0){};
	GridWorldAction(int _val) : value(_val){};
	GridWorldAction(std::string);
	virtual bool operator==(RLActionBase&) const override;
	virtual bool operator<(const RLActionBase&) const override;
	virtual void Randomize() override;
	virtual int GetValue() const override;
	virtual void SetValue(int) override;;
private:
	friend std::ostream& operator<<(std::ostream &os, const GridWorldAction& action);
	int value;
};



#endif