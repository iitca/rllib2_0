#include "GridWorldState.h"

GridWorldState::GridWorldState(int x, int y)
{
	this->x = x;
	this->y = y;
}

GridWorldState::GridWorldState(std::string line)
{
	int stateStart = line.find("(")+1;
	int stateMiddle = 0;
	int stateEnd = 0;
	if(stateStart != std::string::npos){
		stateMiddle = line.find(",", stateStart);
		if (stateMiddle != std::string::npos){
			stateEnd = line.find(")", stateMiddle);
			if (stateEnd != std::string::npos){
				//all the needed tokens found
				std::string xStr = line.substr(stateStart, stateMiddle-stateStart);
				std::string yStr = line.substr(stateMiddle+1, stateEnd - stateMiddle-1);
				//set coordinates
				std::istringstream(xStr) >> this ->x;
				std::istringstream(yStr) >> this->y;
			}
		}
	}
}


int GridWorldState::GetX() const
{
	return this->x;
}

int GridWorldState::GetY() const
{
	return this->y;
}


bool GridWorldState::operator==(RLStateBase& state) const
{
	return (this->x == ((GridWorldState&)state).x) &&
		(this->y == ((GridWorldState&)state).y);
}

bool GridWorldState::operator==(const RLStateBase& state) const
{
	return (this->x == ((GridWorldState&)state).x) &&
		(this->y == ((GridWorldState&)state).y);
}

bool GridWorldState::operator<(const RLStateBase& state) const
{
	if (this->x < ((GridWorldState&)state).x) return true;
	else if (this->x == ((GridWorldState&)state).x)
		return this->y < ((GridWorldState&)state).y;
	else return false;
}

void GridWorldState::SetCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}

std::ostream& operator<<(std::ostream &os, const GridWorldState& state)
{
	return os << "state(" <<state.GetX() << ", " << state.GetY() << ")";
}
