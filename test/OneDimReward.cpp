#include "OneDimReward.h"

OneDimReward::OneDimReward()
{
}

OneDimReward::OneDimReward(double value)
{
	this->value = value;
}

double OneDimReward::GetValue()
{
	return this->value;
}

void OneDimReward::SetValue(double value)
{
	this->value = value;
}