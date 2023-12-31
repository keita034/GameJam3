#include "Field.h"

#include<DxLib.h>
#include"Util.h"
#include<cassert>

void Field::Init()
{
	LoadMino();

	Reset();

	int i = 1;
	while (i * 5 + FRAME_WIDTH <= MAP_WIDTH)
	{
		Int2 temp(i * 5 + FRAME_WIDTH, 5);
		appearancePoint.push_back(temp);
		i++;
	}
	int32_t randNum = GetRand(minoFileNames.size() - 1);
	mino_ = minos_[minoFileNames[randNum]].get();
	randNum = GetRand(appearancePoint.size() - 1);
	mino_->Init(appearancePoint[randNum], static_cast<MinoColorType>(GetRand(MINOCOLORTYPE_COUNT)), GetRand(4));
}

void Field::Update()
{
	FieldReset();

	MinoAppearance();

	if (mino_)
	{
		MinoAdjustmenDown();

		mino_->Update();

		SetMino(mino_);
	}

	LineDestroy();
}

void Field::Draw()
{
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			if (field_[i].line[j] == FieldBlockIndex::WALL || field_[i].line[j] == FieldBlockIndex::CEILING)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(100, 100, 100), true);
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(255, 255, 255), false);
			}
			else if (field_[i].line[j] == FieldBlockIndex::GREEN_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(0, 255, 0), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::RED_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(255, 0, 0), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::BLUE_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(0, 0, 255), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::GHOST_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(255, 255, 255), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::ORANGE_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, 0xfd7e00, true);
			}
		}
	}

	if (mino_)
	{
		mino_->Draw();
	}
}

void Field::Reset()
{
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			if (i < FRAME_HEIGHT || i >= FIELD_HEIGHT - FRAME_HEIGHT || j < FRAME_WIDTH || j >= FIELD_WIDTH - FRAME_WIDTH)
			{
				if (i < FRAME_HEIGHT)
				{
					field_[i].line[j] = FieldBlockIndex::CEILING;
				}
				else
				{
					field_[i].line[j] = FieldBlockIndex::WALL;
				}

			}
			else
			{
				field_[i].line[j] = FieldBlockIndex::NONE;
			}
		}
	}
}

void Field::FieldReset()
{
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			if (i < FRAME_HEIGHT || i >= FIELD_HEIGHT - FRAME_HEIGHT || j < FRAME_WIDTH || j >= FIELD_WIDTH - FRAME_WIDTH)
			{
				if (i < FRAME_HEIGHT)
				{
					field_[i].line[j] = FieldBlockIndex::CEILING;
				}
				else
				{
					field_[i].line[j] = FieldBlockIndex::WALL;
				}
			}
			else
			{
				if (GetMaptChipData(j, i) == FieldBlockIndex::GHOST_BLOCK)
				{
					field_[i].line[j] = FieldBlockIndex::NONE;
				}
			}
		}
	}
}

void Field::RightPush()
{
	if (mino_)
	{
		int32_t pushNum = 0;
		bool isBreak = false;

		for (int32_t k = 1; k < 3; k++)
		{
			for (size_t i = 0; i < MINO_SIZE; i++)
			{
				for (size_t j = 0; j < MINO_SIZE; j++)
				{
					if (mino_->GetMino(j, i) == Mino::BlockIndex::BLOCK)
					{
						Int2 index = mino_->GetPosIndex(j, i);

						if (field_[index.y].line[index.x + k] != FieldBlockIndex::NONE &&
							field_[index.y].line[index.x + k] != FieldBlockIndex::GHOST_BLOCK)
						{
							pushNum = k - 1;
							isBreak = true;
							break;
						}
					}
				}
				if (isBreak)break;
			}
			if (isBreak)break;

		}

		if (!isBreak)pushNum = 2;

		if (pushNum > 0)
		{
			mino_->Push(pushNum);
		}
	}
}

void Field::LeftPush()
{
	if (mino_)
	{
		int32_t pushNum = 0;
		bool isBreak = false;

		for (int32_t k = 1; k < 3; k++)
		{
			for (size_t i = 0; i < MINO_SIZE; i++)
			{
				for (size_t j = 0; j < MINO_SIZE; j++)
				{
					if (mino_->GetMino(j, i) == Mino::BlockIndex::BLOCK)
					{
						Int2 index = mino_->GetPosIndex(j, i);

						if (field_[index.y].line[index.x - k] != FieldBlockIndex::NONE &&
							field_[index.y].line[index.x - k] != FieldBlockIndex::GHOST_BLOCK)
						{
							pushNum = -(k - 1);
							isBreak = true;
							break;
						}
					}
				}
				if (isBreak)break;
			}
			if (isBreak)break;

		}

		if (!isBreak)pushNum = -2;

		if (pushNum < 0)
		{
			mino_->Push(pushNum);
		}
	}
}

int8_t Field::GetChipData(size_t width, size_t height)
{
	return field_[height + FRAME_HEIGHT].line[width + FRAME_WIDTH];
}

int8_t Field::GetMaptChipData(size_t width, size_t height)
{
	return field_[height].line[width];
}

void Field::SetMino(Mino* mino)
{
	if (mino->IsValid())
	{
		for (size_t i = 0; i < MINO_SIZE; i++)
		{
			for (size_t j = 0; j < MINO_SIZE; j++)
			{
				if (mino->GetMino(j, i) == Mino::BlockIndex::BLOCK)
				{
					Int2 index = mino->GetPosIndex(j, i);
					field_[index.y].line[index.x] = FieldBlockIndex::GHOST_BLOCK;

					if (field_[index.y + 1].line[index.x] != FieldBlockIndex::NONE &&
						field_[index.y + 1].line[index.x] != FieldBlockIndex::GHOST_BLOCK &&
						field_[index.y + 1].line[index.x] != FieldBlockIndex::CEILING)
					{
						mino->InvalidateFall();
					}
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < MINO_SIZE; i++)
		{
			for (size_t j = 0; j < MINO_SIZE; j++)
			{
				if (mino->GetMino(j, i) == Mino::BlockIndex::BLOCK)
				{
					Int2 index = mino->GetPosIndex(j, i);
					field_[index.y].blockCount++;
					switch (mino->GetMinoColor())
					{
					case BLUE:
						field_[index.y].line[index.x] = FieldBlockIndex::BLUE_BLOCK;
						break;
					case RED:
						field_[index.y].line[index.x] = FieldBlockIndex::RED_BLOCK;
						break;
					case GREEN:
						field_[index.y].line[index.x] = FieldBlockIndex::GREEN_BLOCK;
						break;
					case ORANGE:
						field_[index.y].line[index.x] = FieldBlockIndex::ORANGE_BLOCK;

						break;
					default:
						break;
					}

				}
			}
		}

		mino_ = nullptr;
	}

}

void Field::LoadMino()
{
	std::vector<std::string>patrsFilePaths = GetFileNames("Parts");

	for (size_t i = 0; i < patrsFilePaths.size(); i++)
	{
		//データ
		std::stringstream data;
		//1行分も文字列を入れる変数
		std::string line;
		std::ifstream file(patrsFilePaths[i].c_str());
		std::unique_ptr<Mino> mino = std::make_unique<Mino>();
		std::string patrsFileName;

		assert(file.is_open());

		//ファイルの内容を文字列をストリームにコピー
		data << file.rdbuf();

		//ファイルを閉じる
		file.close();

		getline(data, line, '\n');
		{
			for (size_t i = 0; i < MINO_SIZE; i++)
			{
				std::istringstream lineStream(line);

				for (size_t j = 0; j < MINO_SIZE; j++)
				{
					std::string num;

					std::getline(lineStream, num, ',');

					int8_t v = static_cast<int8_t>(std::atoi(num.c_str()));
					mino->SetMino(i, j, v);
				}

				getline(data, line, '\n');
			}

			patrsFileName = GetFileName(patrsFilePaths[i]);

			minos_[patrsFileName] = std::move(mino);
			minoFileNames.push_back(patrsFileName);
		}
	}
}

void Field::MinoAppearance()
{
	if (mino_)
	{
		if (!nextMino_)
		{
			int32_t randNum = GetRand(minoFileNames.size() - 1);
			nextMino_ = minos_[minoFileNames[randNum]].get();
			randNum = GetRand(appearancePoint.size() - 1);
			nextMino_->Init(appearancePoint[randNum], static_cast<MinoColorType>(GetRand(MINOCOLORTYPE_COUNT - 1)), GetRand(4));
		}

	}
	else
	{
		if (nextMino_)
		{
			mino_ = nextMino_;
			nextMino_ = nullptr;
		}
		else
		{
			int32_t randNum = GetRand(minoFileNames.size() - 1);
			mino_ = minos_[minoFileNames[randNum]].get();
			randNum = GetRand(appearancePoint.size() - 1);
			mino_->Init(appearancePoint[randNum], static_cast<MinoColorType>(GetRand(MINOCOLORTYPE_COUNT - 1)), GetRand(4));
		}
	}
}

void Field::MinoAdjustmenDown()
{
	if (!mino_->IsFall())
	{
		bool isBreak = false;

		for (size_t i = 0; i < MINO_SIZE; i++)
		{
			for (size_t j = 0; j < MINO_SIZE; j++)
			{
				if (mino_->GetMino(i, j) == Mino::BlockIndex::BLOCK)
				{
					Int2 index = mino_->GetPosIndex(i, j);

					if (field_[index.y + 1].line[index.x] != FieldBlockIndex::NONE)
					{
						isBreak = true;
						break;
					}
				}

			}
		}

		if (!isBreak)
		{
			mino_->Down();
		}
	}
}

void Field::LineDestroy()
{
	size_t destroyLine = 0;

	for (size_t i = FRAME_HEIGHT; i < MAP_HEIGHT + FRAME_HEIGHT; i++)
	{
		if (field_[i].blockCount >= LINE_DESTROY_NUM)
		{
			for (size_t j = FRAME_WIDTH; j < MAP_WIDTH + FRAME_WIDTH; j++)
			{
				field_[i].line[j] = 0;
				field_[i].blockCount = 0;
			}

			destroyLine = i;

			Line tmp = field_[destroyLine];

			for (size_t j = destroyLine; j >= FRAME_HEIGHT; j--)
			{
				field_[j] = field_[j - 1];
			}

			field_[FRAME_HEIGHT] = tmp;

			break;
		}
	}


}
