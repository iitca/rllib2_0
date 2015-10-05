#include "GridWorldAction.h"
#include <stdlib.h>
#include <time.h>

GridWorldAction::GridWorldAction(std::string line)
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

bool GridWorldAction::operator==(RLActionBase& action) const
{
	return this->value == ((GridWorldAction&)action).value;
}

bool GridWorldAction::operator<(const RLActionBase& action) const
{
	return (this->value < ((GridWorldAction&)action).GetValue());
}

void GridWorldAction::Randomize()
{
	double dR = rand();
	int iR = ((int)dR);// % Direction::DIR_NUM;
	this ->value = (Direction)(iR % Direction::DIR_NUM);
}

int GridWorldAction::GetValue() const
{
	return this->value;
}

void GridWorldAction::SetValue(int value)
{
	this->value = value;
}

std::ostream& operator<<(std::ostream &os, const GridWorldAction& action)
{
	return os << "action(" <<action.GetValue() << ")";
}
