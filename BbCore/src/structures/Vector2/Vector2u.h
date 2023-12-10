#pragma once

#include "../../core/Macros.h"

namespace Bb {

	struct CORE Vector2u {

		Vector2u(unsigned int x = 0.f, unsigned int y = 0.f);
		Vector2u(const Vector2u& other);
		Vector2u(Vector2u&& other) = delete;

		unsigned int x, y;

		// ASSIGNMENT

		bool operator==(const Vector2u& other);
		Vector2u operator=(const Vector2u& other);

		// BINARY ARITHMETIC

		Vector2u operator+(const Vector2u& other);
		Vector2u operator-(const Vector2u& other);
		Vector2u operator*(const Vector2u& other);
		Vector2u operator/(const Vector2u& other);

		// ARITHMETIC/ASSIGNMENT

		Vector2u operator+=(const Vector2u& other);
		Vector2u operator-=(const Vector2u& other);
		Vector2u operator*=(const Vector2u& other);
		Vector2u operator/=(const Vector2u& other);

	};

}