#pragma once
#include "Types.h"
#include "PlayerInfo.h"

class GameData {
	public:
		static GameData* GetInstance();
		PlayerInfo* GetHost();
		PlayerInfo* GetPlayerById(uint8_t Id);
};