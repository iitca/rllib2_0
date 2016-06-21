#ifndef ONEDIMACTION_H
#define ONEDIMACTION_H

#include "RLActionBase.h"
#include <iostream>
#include <sstream>

using namespace RLENTITY_NMSPC;

class OneDimAction : public RLActionBase
{
public:
	OneDimAction() : value(0){};
	OneDimAction(int _val) : value(_val){};
	OneDimAction(std::string);
	virtual bool operator==(RLActionBase&) const override;
	virtual bool operator<(const RLActionBase&) const override;
	virtual void Randomize() override;
	virtual int GetValue() const override;
	virtual void SetValue(int) override;
private:
	friend std::ostream& operator<<(std::ostream &os, const OneDimAction& action);
	unsigned char value;
};

#endif