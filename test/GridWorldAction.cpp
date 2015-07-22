#include "GridWorldAction.h"
#include <stdlib.h>


bool GridWorldAction::operator==(RLActionBase& action) const
{
	return this->d == ((GridWorldAction&)action).d;
}

void GridWorldAction::Randomize()
{
	this ->d = (Direction)(rand() % Direction::DIR_NUM);
}