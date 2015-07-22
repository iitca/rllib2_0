#include "GridWorldReward.h"

GridWorldReward::GridWorldReward()
{
}

GridWorldReward::GridWorldReward(double value)
{
	this->value = value;
}

double GridWorldReward::GetValue()
{
	return this->value;
}

void GridWorldReward::SetValue(double value)
{
	this->value = value;
}