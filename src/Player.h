#pragma once
#include "plugin.h"
#include "Config.h"
#include "Functions.h"

class Player : Functions
{
public:
	static void Initialise();
private:
	inline static std::vector<std::string> all_outfits;
	static void RandomizeOutfit (uint32_t modelId, const char *modelName,
				     uint32_t flags);
	static void GivePlayerRandomOutfit();
	static void RandomizeOutfitOnFade();
	static void ChangePlayerModel(const char* modelName);
};
