#include "GridWorldState.h"

GridWorldState::GridWorldState(int x, int y)
{
	this->x = x;
	this->y = y;
}

int GridWorldState::GetX()
{
	return this->x;
}

int GridWorldState::GetY()
{
	return this->y;
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