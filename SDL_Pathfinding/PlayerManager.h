#pragma once
#include "Agent.h"

#define PLAYER PlayerManager::Instance()

class PlayerManager
{
private:
	Agent *player;
	bool hasGun;

	PlayerManager() = default;

	~PlayerManager() {}
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator =(const PlayerManager&) = delete;

public:
	inline static PlayerManager& Instance()
	{
		static PlayerManager manager;
		return manager;
	}

	inline Agent *GetPlayer() { return player; }
	inline bool GetHasGun() { return hasGun; }
	inline void SetPlayer(Agent* _player) { player = _player; }
};

