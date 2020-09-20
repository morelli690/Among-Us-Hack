#pragma once
#include <string>
struct Vector2 {
	public:
		Vector2(float x, float y);
		std::string ToString();
		float x;
		float y;
};