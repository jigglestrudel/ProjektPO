#pragma once
#include "Vector2D.h"

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

std::string Vector2D::toString()
{
	return std::string("(") + std::to_string(this->x) + std::string(", ") + std::to_string(this->y) + std::string(")");
}

Vector2D& Vector2D::operator=(const Vector2D& right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}

bool Vector2D::operator==(Vector2D right)
{
	return this->x == right.x && this->y == right.y;
}

Vector2D Vector2D::operator+(Vector2D right)
{
	return Vector2D(this->x + right.x, this->y + right.y);
}

Vector2D Vector2D::operator*(int scale)
{
	return Vector2D(this->x * scale, this->y * scale);
}


std::ostream& operator<<(std::ostream& os, Vector2D vector)
{
	os << "(" << vector.x << ", " << vector.y << ")";
	return os;
}

std::string& operator+=(std::string& str, Vector2D vector)
{
	str += "(";
	str += vector.x;
	str += " ,";
	str += vector.y;
	str += ")";
	return str;
}
