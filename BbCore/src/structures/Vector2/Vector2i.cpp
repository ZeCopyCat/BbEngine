#include "Vector2i.h"

namespace Bb {

	Vector2i::Vector2i(int x, int y)
	{

		this->x = x;
		this->y = y;

	}

	Vector2i::Vector2i(const Vector2i& other)
	{

		this->x = other.x;
		this->y = other.y;

	}

	// ASSIGNMENT OPERATORS

	bool Vector2i::operator==(const Vector2i& other) {

		return (x == other.x) && (y == other.y);

	}

	Vector2i Vector2i::operator=(const Vector2i& other) {

		return Vector2i(other);

	}

	// BINARY ARITHMETIC OPERATORS

	Vector2i Vector2i::operator+(const Vector2i& other) {

		return Vector2i(x + other.x, y + other.y);

	}

	Vector2i Vector2i::operator-(const Vector2i& other) {

		return Vector2i(x - other.x, y - other.y);

	}

	Vector2i Vector2i::operator*(const Vector2i& other) {

		return Vector2i(x * other.x, y * other.y);

	}

	Vector2i Vector2i::operator/(const Vector2i& other) {

		return Vector2i(x / other.x, y / other.y);

	}

	// ARITHMETIC/ASSIGNMENT OPERATORS

	Vector2i Vector2i::operator+=(const Vector2i& other) {

		return Vector2i(x += other.x, y += other.y);

	}

	Vector2i Vector2i::operator-=(const Vector2i& other) {

		return Vector2i(x -= other.x, y -= other.y);

	}

	Vector2i Vector2i::operator*=(const Vector2i& other) {

		return Vector2i(x *= other.x, y *= other.y);

	}

	Vector2i Vector2i::operator/=(const Vector2i& other) {

		return Vector2i(x /= other.x, y /= other.y);

	}

}