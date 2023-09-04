#include "Mino.h"

const std::array<std::array<uint8_t, 4>, 4>& Mino::GetMino()
{
    return mino;
}

void Mino::SetMino(size_t width, size_t height, int8_t value)
{
    mino[height][width] = value;
}
