#pragma once
#include <iostream>
#include <string>

class Vector2D {
public:
	int x, y;

	Vector2D();
	Vector2D(int x, int y);

	std::string toString();

	Vector2D& operator=(const Vector2D& right);
	bool operator==(Vector2D right);
	Vector2D operator+(Vector2D right);
	Vector2D operator*(int scale);

	friend std::ostream& operator<<(std::ostream& os, Vector2D vector);
	friend std::string& operator+=(std::string& str,  Vector2D vector);
};
