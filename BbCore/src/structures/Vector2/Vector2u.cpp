#include "Vector2u.h"

namespace Bb {

	Vector2u::Vector2u(unsigned int x, unsigned int y)
	{

		this->x = x;
		this->y = y;

	}

	Vector2u::Vector2u(const Vector2u& other)
	{

		this->x = other.x;
		this->y = other.y;

	}

	// ASSIGNMENT OPERATORS

	bool Vector2u::operator==(const Vector2u& other) {

		return (x == other.x) && (y == other.y);

	}

	Vector2u Vector2u::operator=(const Vector2u& other)
	{

		x = other.x;
		y = other.y;

		return *this;
	
	}

	// BINARY ARITHMETIC OPERATORS

	Vector2u Vector2u::operator+(const Vector2u& other) {

		return Vector2u(x + other.x, y + other.y);

	}

	Vector2u Vector2u::operator-(const Vector2u& other) {

		return Vector2u(x - other.x, y - other.y);

	}

	Vector2u Vector2u::operator*(const Vector2u& other) {

		return Vector2u(x * other.x, y * other.y);

	}

	Vector2u Vector2u::operator/(const Vector2u& other) {

		return Vector2u(x / other.x, y / other.y);

	}

	// ARITHMETIC/ASSIGNMENT OPERATORS

	Vector2u Vector2u::operator+=(const Vector2u& other) {

		return Vector2u(x += other.x, y += other.y);

	}

	Vector2u Vector2u::operator-=(const Vector2u& other) {

		return Vector2u(x -= other.x, y -= other.y);

	}

	Vector2u Vector2u::operator*=(const Vector2u& other) {

		return Vector2u(x *= other.x, y *= other.y);

	}

	Vector2u Vector2u::operator/=(const Vector2u& other) {

		return Vector2u(x /= other.x, y /= other.y);

	}

}