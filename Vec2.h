#pragma once
struct Vec2
{
public:
	float x;
	float y;
public:
	Vec2();
	Vec2(float x, float y);
	float Length() const; // ベクトルの長さを計算する const メンバ関数
	float LengthSquare()const; // ベクトルの長さの二乗
	float Dot(const Vec2& other) const; // もう一方のベクトルとの内積
	float DistanceFrom(const Vec2& other) const;    // もう一方のベクトルとの距離
	Vec2 Normalized() const; // 正規化（長さを１にした）ベクトル
	bool isZero() const; // ゼロベクトルであるか

//単項演算子オーバーロード
	Vec2 operator+()const;
	Vec2 operator-()const;

	//代入演算子オーバーロード
	Vec2& operator+=(const Vec2& v);
	Vec2& operator-=(const Vec2& v);
	Vec2& operator*=(float s);
	Vec2& operator*=(const Vec2& v);
	Vec2& operator/=(float s);
	Vec2& operator/=(const Vec2& v);
	bool operator>(const Vec2& v);
	bool operator<(const Vec2& v);
};

//2項演算子
const Vec2 operator+(const Vec2& v1, const Vec2& v2);
const Vec2 operator-(const Vec2& v1, const Vec2& v2);
const Vec2 operator*(const Vec2& v, float s);
const Vec2 operator*(float s, const Vec2& v);
const Vec2 operator/(const Vec2& v, float s);