#include "OneDimAction.h"

OneDimAction::OneDimAction(std::string line)
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
	unsigned int iR = (unsigned int)dR;
	this->value = iR % (sizeof(unsigned int) * 8);
}

int OneDimAction::GetValue() const
{
	return this->value;
}

void OneDimAction::SetValue(int _val)
{
	this->value = _val;
}

std::ostream& operator<<(std::ostream &os, const OneDimAction& action)
{
	return os << "action(" << action.GetValue() << ")";
}