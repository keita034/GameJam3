#include "Vec2.h"
#include <math.h>

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vec2::Length() const // �x�N�g���̒������v�Z���� const �����o�֐�
{
	return sqrtf(x * x + y * y);
}

float Vec2::LengthSquare() const // �x�N�g���̒����̓��
{
	return x * x + y * y;
}

float Vec2::Dot(const Vec2& other) const // ��������̃x�N�g���Ƃ̓���
{
	return x * other.x + y * other.y;
}

float Vec2::DistanceFrom(const Vec2& other) const    // ��������̃x�N�g���Ƃ̋���
{
	return sqrtf((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

Vec2 Vec2::Normalized() const // ���K���i�������P�ɂ����j�x�N�g��
{
	return{ x / Length() , y / Length() };
}

bool Vec2::isZero() const // �[���x�N�g���ł��邩
{
	return x == 0.0 && y == 0.0;
}

//�P�����Z�q�I�[�o�[���[�h
Vec2 Vec2::operator+() const
{
	return *this;
}

Vec2 Vec2::operator-() const
{
	return  Vec2(-x, -y);
}

//������Z�q�I�[�o�[���[�h
Vec2& Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vec2& Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vec2& Vec2::operator*=(float s)
{
	x *= s;
	y *= s;

	return *this;
}

Vec2& Vec2::operator*=(const Vec2& v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}

Vec2& Vec2::operator/=(float s)
{
	x /= s;
	y /= s;

	return *this;
}

Vec2& Vec2::operator/=(const Vec2& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

bool Vec2::operator>(const Vec2& v)
{
	if (this->x > v.x && this->y > v.y)
	{
		return true;
	}

	return false;
}

bool Vec2::operator<(const Vec2& v)
{
	if (this->x < v.x && this->y < v.y)
	{
		return true;
	}
	return false;
}

//Vec2 �N���X�ɑ����Ȃ��֐��Q
//�񍀉��Z�q
const Vec2 operator+(const Vec2& v1, const Vec2& v2)
{
	Vec2 temp(v1);
	return temp += v2;
}

const Vec2 operator-(const Vec2& v1, const Vec2& v2)
{
	Vec2 temp(v1);
	return temp -= v2;
}

const Vec2 operator*(const Vec2& v, float s)
{
	Vec2 temp(v);
	return temp *= s;
}

const Vec2 operator*(float s, const Vec2& v)
{
	return v * s;
}

const Vec2 operator/(const Vec2& v, float s)
{
	Vec2 temp(v);
	return temp /= s;
}