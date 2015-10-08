#include "OneDimState.h"

OneDimState::OneDimState(int _val)
{
	this->val = _val;
}

OneDimState::OneDimState(std::string line)
{
	int actionStart = line.find("state(") + 6;
	int actionEnd = 0;
	if (actionStart != std::string::npos){
		actionEnd = line.find(")", actionStart);
		if (actionEnd != std::string::npos){
			//all the needed tokens found
			std::string _val = line.substr(actionStart, actionEnd - actionStart);
			//set value
			std::istringstream(_val) >> this->val;
		}
	}
}

int OneDimState::Get() const
{
	return this->val;
}

void OneDimState::Set(int _val)
{
	this->val = _val;
}

bool OneDimState::operator==(RLStateBase& state) const
{
	return (this->val == ((OneDimState&)state).val);
}

bool OneDimState::operator==(const RLStateBase& state) const
{
	return (this->val == ((OneDimState&)state).val);
}

bool OneDimState::operator<(const RLStateBase& state) const
{
	return this->val < ((OneDimState&)state).val;
}

std::ostream& operator<<(std::ostream &os, const OneDimState& state)
{
	return os << "state(" << state.Get() << ")";
}
