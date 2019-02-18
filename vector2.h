#pragma once
#ifndef VECTOR_2_H
#define VECTOR_2_H
class Vector2 {
public:
	int X, Y;

	Vector2() {

	}

	Vector2(int _x, int _y) {
		this->X = _x;
		this->Y = _y;
	}

	static Vector2* Zero() {
		return new Vector2(0, 0);
	}
	static Vector2* Right() {
		return new Vector2(1, 0);
	}
	static Vector2* Left() {
		return new Vector2(-1, 0);
	}
	static Vector2* Up() {
		return new Vector2(0, 1);
	}
	static Vector2* Down() {
		return new Vector2(0, -1);
	}
	/* Projects a float value onto this vector and returns it */
	/*inline Vector2& Project(float projectionValue) {
		Vector2 toReturn = Vector2(X*projectionValue, Y*projectionValue);
		return *toReturn;
	}*/

	friend Vector2 operator+(Vector2 const &v1, Vector2 const &v2) {
		return Vector2(v1.X + v2.X, v1.Y + v2.Y);
	}

	/*friend Vector2 operator+=(Vector2 const &lhs, Vector2 const &rhs) {

	}*/

	friend Vector2 operator-(Vector2 const &v1, Vector2 const &v2) {
		return Vector2(v1.X - v2.X, v1.Y - v2.Y);
	}

	bool operator==(const Vector2& other) {
		return (this->X == other.X) && (this->Y == other.Y);
	}
};

#endif
