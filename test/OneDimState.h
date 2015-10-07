#ifndef ONEDIMSTATE_H
#define ONEDIMSTATE_H

#include "RLStateBase.h"
#include <sstream>
#include <iostream>

using namespace RLENTITY_NMSPC;

class OneDimState : RLStateBase
{
public:
	OneDimState(){};
	OneDimState(int);
	OneDimState(std::string);
	int Get() const;
	void Set(int);
	virtual bool operator==(RLStateBase&) const override;
	virtual bool operator<(const RLStateBase&) const override;
private:
	friend std::ostream& operator<<(std::ostream &os, const OneDimState& state);
	int val;

};

#endif