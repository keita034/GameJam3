#pragma once
#include<array>

#include"Config.h"

class Mino
{
public:

	Mino() = default;
	~Mino() = default;

	const std::array<std::array<uint8_t, 4>, 4>& GetMino();

	void SetMino(size_t width, size_t height, int8_t value);

private:

	std::array<std::array<uint8_t, 4>, 4>mino;
};

