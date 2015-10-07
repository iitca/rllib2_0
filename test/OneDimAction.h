#ifndef ONEDIMACTION_H
#define ONEDIMACTION_H

#include "RLActionBase.h"
#include <iostream>
#include <sstream>

using namespace RLENTITY_NMSPC;

class OneDimAction : RLActionBase
{
public:
	OneDimAction() : value(0), maxVal(0){};
	OneDimAction(int _val, int _maxVal) : value(_val), maxVal(_maxVal){};
	OneDimAction(std::string, int _maxVal);
	virtual bool operator==(RLActionBase&) const override;
	virtual bool operator<(const RLActionBase&) const override;
	virtual void Randomize() override;
	virtual int GetValue() const override;
	virtual void SetValue(int) override;
private:
	friend std::ostream& operator<<(std::ostream &os, const OneDimAction& action);
	int value;
	int maxVal;
};

#endif