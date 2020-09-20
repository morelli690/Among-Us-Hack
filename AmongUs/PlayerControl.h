#pragma once
#include "PlayerPhysics.h"
#include "DeathReason.h"
#include "TextRenderer.h"
#include "List.h"
#include "Vector2.h"

class PlayerControl {
	public:
		static PlayerControl* GetLocalPlayer();
		static Il2CppArray* GetAllPlayers();
		static Vector2 GetTruePosition(PlayerControl* who);
		static bool RpcSendChat(Il2CppString* what);
		static bool SendChat(Il2CppString* what);
		PlayerPhysics* GetPhysics();
		void MurderPlayer(PlayerControl* who);
		Vector2 GetTruePosition();
		uint8_t GetPlayerId();
};