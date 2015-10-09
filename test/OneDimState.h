#ifndef ONEDIMSTATE_H
#define ONEDIMSTATE_H

#include "RLStateBase.h"
#include <sstream>
#include <iostream>

using namespace RLENTITY_NMSPC;

class OneDimState : public RLStateBase
{
public:
	OneDimState(){};
	OneDimState(unsigned char);
	OneDimState(std::string);
	unsigned char Get() const;
	void Set(unsigned char);
	virtual bool operator==(RLStateBase&) const override;
	virtual bool operator==(const RLStateBase&) const;
	virtual bool operator<(const RLStateBase&) const override;
private:
	friend std::ostream& operator<<(std::ostream &os, const OneDimState& state);
	unsigned char val;

};

#endif