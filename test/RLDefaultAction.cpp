#include "RLDefaultAction.h"
#include <stdlib.h>
#include <time.h>

using namespace RLENTITY_NMSPC;


bool RLDefaultAction::operator==(RLActionBase& action) const
{
	return this->value == ((RLDefaultAction&)action).GetValue();
}

bool RLDefaultAction::operator<(const RLActionBase& action) const
{
	return (this->value < ((RLDefaultAction&)action).GetValue());
}

void RLDefaultAction::Randomize()
{
	srand(time(NULL));
	this -> value = (int)rand() % this->maxVal;
}

int RLDefaultAction::GetValue() const
{
	return this->value;
}

void RLDefaultAction::SetValue(int val)
{
	this->value = val;
}