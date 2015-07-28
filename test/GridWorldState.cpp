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

bool GridWorldState::operator==(RLStateBase& state) const
{
	return (this->x == ((GridWorldState&)state).x) &&
		(this->y == ((GridWorldState&)state).y);
}

void GridWorldState::SetCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}