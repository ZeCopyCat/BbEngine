#include "Vector2f.h"

namespace Bb {

	Vector2f::Vector2f(float x, float y)
	{

		this->x = x;
		this->y = y;

	}

	Vector2f::Vector2f(const Vector2f& other)
	{

		this->x = other.x;
		this->y = other.y;

	}

	// ASSIGNMENT OPERATORS

	bool Vector2f::operator==(const Vector2f& other) {

		return (x == other.x) && (y == other.y);

	}

	Vector2f Vector2f::operator=(const Vector2f& other)
	{

		x = other.x;
		y = other.y;

		return *this;

	}

	// BINARY ARITHMETIC OPERATORS

	Vector2f Vector2f::operator+(const Vector2f& other) {

		return Vector2f(x + other.x, y + other.y);

	}

	Vector2f Vector2f::operator-(const Vector2f& other) {

		return Vector2f(x - other.x, y - other.y);

	}

	Vector2f Vector2f::operator*(const Vector2f& other) {

		return Vector2f(x * other.x, y * other.y);

	}

	Vector2f Vector2f::operator/(const Vector2f& other) {

		return Vector2f(x / other.x, y / other.y);

	}

	// ARITHMETIC/ASSIGNMENT OPERATORS

	Vector2f Vector2f::operator+=(const Vector2f& other) {

		return Vector2f(x += other.x, y += other.y);

	}

	Vector2f Vector2f::operator-=(const Vector2f& other) {

		return Vector2f(x -= other.x, y -= other.y);

	}

	Vector2f Vector2f::operator*=(const Vector2f& other) {

		return Vector2f(x *= other.x, y *= other.y);

	}

	Vector2f Vector2f::operator/=(const Vector2f& other) {

		return Vector2f(x /= other.x, y /= other.y);

	}

}