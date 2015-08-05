#include "GridWorldAction.h"
#include <stdlib.h>


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
	this ->value = (Direction)(rand() % Direction::DIR_NUM);
}

int GridWorldAction::GetValue()
{
	return this->value;
}

void GridWorldAction::SetValue(int value)
{
	this->value = value;
}