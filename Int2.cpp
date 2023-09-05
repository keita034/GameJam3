#include "Int2.h"

Int2::Int2()
{
	x = 0;
	y = 0;
}

Int2::Int2(int32_t x, int32_t y)
{
	this->x = x;
	this->y = y;
}

//�P�����Z�q�I�[�o�[���[�h
Int2 Int2::operator+() const
{
	return *this;
}

Int2 Int2::operator-() const
{
	return  Int2(-x, -y);
}

//������Z�q�I�[�o�[���[�h
Int2& Int2::operator+=(const Int2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Int2& Int2::operator-=(const Int2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Int2& Int2::operator*=(const Int2& v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}

Int2& Int2::operator/=(const Int2& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

bool Int2::operator>(const Int2& v)
{
	if (this->x > v.x && this->y > v.y)
	{
		return true;
	}

	return false;
}

bool Int2::operator<(const Int2& v)
{
	if (this->x < v.x && this->y < v.y)
	{
		return true;
	}
	return false;
}

bool Int2::operator==(const Int2& v)
{
	if (x == v.y && y == v.y)
	{
		return true;
	}
	return false;
}

bool Int2::operator!=(const Int2& v)
{
	if (x != v.y || y != v.y)
	{
		return true;
	}
	return false;
}

//Vec2 �N���X�ɑ����Ȃ��֐��Q
//�񍀉��Z�q
const Int2 operator+(const Int2& v1, const Int2& v2)
{
	Int2 temp(v1);
	return temp += v2;
}

const Int2 operator-(const Int2& v1, const Int2& v2)
{
	Int2 temp(v1);
	return temp -= v2;
}