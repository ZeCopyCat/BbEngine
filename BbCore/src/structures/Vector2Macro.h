#pragma once

#include "../core/Macros.h"

// HEADER MACRO

#define NEWVECTOR2HEADER(name, type, zero) \
\
namespace Bb { \
\
	struct CORE name { \
\
		name(type x = zero, type y = zero); \
		name(const name& other); \
		name(name&& other) = delete; \
\
		type x, y; \
\
		/* ASSIGNMENT */ \
\
		bool operator==(const name& other); \
		name operator=(const name& other); \
\
		/* BINARY ARITHMETIC */ \
\
		name operator+(const name& other); \
		name operator-(const name& other); \
		name operator*(const name& other); \
		name operator/(const name& other); \
\
		/* ARITHMETIC ASSIGNMENT */ \
\
		name operator+=(const name& other); \
		name operator-=(const name& other); \
		name operator*=(const name& other); \
		name operator/=(const name& other); \
\
	}; \
\
}


// CPP MACRO


#define NEWVECTOR2CPP(name, type) \
\
namespace Bb { \
\
	name::name(type x, type y) { \
\
		this->x = x; \
		this->y = y; \
\
	} \
\
	name::name(const name& other) { \
\
		this->x = other.x; \
		this->y = other.y; \
\
	} \
\
	/* ASSIGNMENT OPERATORS */ \
\
	bool name::operator==(const name& other) { \
\
		return (x == other.x) && (y == other.y); \
\
	}\
\
	name name::operator=(const name& other) { \
\
		x = other.x; \
		y = other.y; \
\
		return *this; \
\
	} \
\
	/* BINARY ARITHMETIC OPERATORS */ \
\
	name name::operator+(const name& other) { \
\
		return name(x + other.x, y + other.y); \
\
	} \
\
	name name::operator-(const name& other) { \
\
		return name(x - other.x, y - other.y); \
\
	} \
\
	name name::operator*(const name& other) { \
\
		return name(x * other.x, y * other.y); \
\
	} \
\
	name name::operator/(const name& other) { \
\
		return name(x / other.x, y / other.y); \
\
	} \
\
	/* ARITHMETIC  ASSIGNMENT OPERATORS */ \
\
	name name::operator+=(const name& other) { \
\
		return name(x += other.x, y += other.y); \
\
	} \
\
	name name::operator-=(const name& other) { \
\
		return name(x -= other.x, y -= other.y); \
\
	} \
\
	name name::operator*=(const name& other) { \
\
		return name(x *= other.x, y *= other.y); \
\
	} \
\
	name name::operator/=(const name& other) { \
\
		return name(x /= other.x, y /= other.y); \
\
	} \
\
}