#pragma once
#include<stdint.h>

class Int2
{
public:
	int32_t x;
	int32_t y;

public:

	Int2();
	Int2(int32_t x, int32_t y);

//単項演算子オーバーロード
	Int2 operator+()const;
	Int2 operator-()const;

	//代入演算子オーバーロード
	Int2& operator+=(const Int2& v);
	Int2& operator-=(const Int2& v);
	Int2& operator*=(const Int2& v);
	Int2& operator/=(const Int2& v);
	bool operator>(const Int2& v);
	bool operator<(const Int2& v);
};

//2項演算子
const Int2 operator+(const Int2& v1, const Int2& v2);
const Int2 operator-(const Int2& v1, const Int2& v2);