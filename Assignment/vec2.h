#pragma once

class vec2
{
protected:

public:
	float x;
	float y;

	vec2(int x, int y);
	~vec2();

	void setX(float xPos);
	float getX();
	void setY(float yPos);
	float getY();

	vec2& operator +=(const vec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2& operator -=(const vec2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	vec2& operator *=(const vec2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	

	

};