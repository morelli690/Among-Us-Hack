#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

std::string Vector2::ToString()
{
	return std::string("X: ") + std::to_string(x) + std::string(" Y: ") + std::to_string(y);
}