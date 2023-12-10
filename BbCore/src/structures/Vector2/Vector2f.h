#pragma once

#include "../../core/Macros.h"

namespace Bb {

	struct CORE Vector2f {

		Vector2f(float x = 0.f, float y = 0.f);
		Vector2f(const Vector2f& other);
		Vector2f(Vector2f&& other) = delete;

		float x, y;

		// ASSIGNMENT

		bool operator==(const Vector2f& other);
		Vector2f operator=(const Vector2f& other);

		// BINARY ARITHMETIC

		Vector2f operator+(const Vector2f& other);
		Vector2f operator-(const Vector2f& other);
		Vector2f operator*(const Vector2f& other);
		Vector2f operator/(const Vector2f& other);

		// ARITHMETIC/ASSIGNMENT

		Vector2f operator+=(const Vector2f& other);
		Vector2f operator-=(const Vector2f& other);
		Vector2f operator*=(const Vector2f& other);
		Vector2f operator/=(const Vector2f& other);

	};

}