#pragma once
struct Vec2
{
public:
	float x;
	float y;
public:
	Vec2();
	Vec2(float x, float y);
	float Length() const; // �x�N�g���̒������v�Z���� const �����o�֐�
	float LengthSquare()const; // �x�N�g���̒����̓��
	float Dot(const Vec2& other) const; // ��������̃x�N�g���Ƃ̓���
	float DistanceFrom(const Vec2& other) const;    // ��������̃x�N�g���Ƃ̋���
	Vec2 Normalized() const; // ���K���i�������P�ɂ����j�x�N�g��
	bool isZero() const; // �[���x�N�g���ł��邩

//�P�����Z�q�I�[�o�[���[�h
	Vec2 operator+()const;
	Vec2 operator-()const;

	//������Z�q�I�[�o�[���[�h
	Vec2& operator+=(const Vec2& v);
	Vec2& operator-=(const Vec2& v);
	Vec2& operator*=(float s);
	Vec2& operator*=(const Vec2& v);
	Vec2& operator/=(float s);
	Vec2& operator/=(const Vec2& v);
	bool operator>(const Vec2& v);
	bool operator<(const Vec2& v);
};

//2�����Z�q
const Vec2 operator+(const Vec2& v1, const Vec2& v2);
const Vec2 operator-(const Vec2& v1, const Vec2& v2);
const Vec2 operator*(const Vec2& v, float s);
const Vec2 operator*(float s, const Vec2& v);
const Vec2 operator/(const Vec2& v, float s);