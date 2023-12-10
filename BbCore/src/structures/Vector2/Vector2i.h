#pragma once

#include "../../core/Macros.h"

namespace Bb {

	struct CORE Vector2i {

		Vector2i(int x = 0.f, int y = 0.f);
		Vector2i(const Vector2i& other);
		Vector2i(Vector2i&& other) = delete;

		int x, y;

		// ASSIGNMENT

		bool operator==(const Vector2i& other);
		Vector2i operator=(const Vector2i& other);

		// BINARY ARITHMETIC

		Vector2i operator+(const Vector2i& other);
		Vector2i operator-(const Vector2i& other);
		Vector2i operator*(const Vector2i& other);
		Vector2i operator/(const Vector2i& other);

		// ARITHMETIC/ASSIGNMENT

		Vector2i operator+=(const Vector2i& other);
		Vector2i operator-=(const Vector2i& other);
		Vector2i operator*=(const Vector2i& other);
		Vector2i operator/=(const Vector2i& other);

	};

}