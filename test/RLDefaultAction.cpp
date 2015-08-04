#include "RLDefaultAction.h"
#include <stdlib.h>
#include <time.h>

using namespace RLENTITY_NMSPC;


bool RLDefaultAction::operator==(RLActionBase& action) const
{
	return this->value == action.GetValue();
}

void RLDefaultAction::Randomize()
{
	srand(time(NULL));
	//what to return here?
	//double r = (int)rand() /  this ->maxVal;
	//
	this->value = 0;
}

int RLDefaultAction::GetValue()
{
	return this->value;
}