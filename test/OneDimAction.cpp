#include "OneDimAction.h"

OneDimAction::OneDimAction(std::string line, int _maxVal)
{
	int actionStart = line.find("action(") + 7;
	int actionEnd = 0;
	if (actionStart != std::string::npos){
		actionEnd = line.find(")", actionStart);
		if (actionEnd != std::string::npos){
			//all the needed tokens found
			std::string val = line.substr(actionStart, actionEnd - actionStart);
			//set value
			std::istringstream(val) >> this->value;
		}
	}
	this->maxVal = _maxVal;
}

bool OneDimAction::operator==(RLActionBase& action) const
{
	return this->value == ((OneDimAction&)action).value;
}

bool OneDimAction::operator<(const RLActionBase& action) const
{
	return (this->value < ((OneDimAction&)action).GetValue());
}

void OneDimAction::Randomize()
{
	double dR = rand();
	int iR = ((int)dR);
	this->value = iR % this->maxVal;
}

int OneDimAction::GetValue() const
{
	return this->value;
}

void OneDimAction::SetValue(int _val)
{
	this->value = _val;
}