#pragma once
#include "plugin.h"
#include "Functions.h"
#include "Config.h"
#include "ModelInfo.h"
#include "CStreaming.h"
#include "CRunningScript.h"
#include "CTheScripts.h"
#include "CVehicleModelInfo.h"

class scm : Functions, ModelInfo
{
private:
	static void __fastcall ScriptVehicleRandomizer(CRunningScript* thisScript, void* edx, int* arg0, short count);
	static void __fastcall FixForcedPlayerVehicle(CRunningScript* thisScript, void* edx, int* arg0, short count);
	struct Pattern
	{
		int vehicle = 0;
		std::string gVehicle = "";
		std::vector<int> allowed = {};
		std::vector<int> denied = {};
		std::vector<std::string> allowedType = {};
		int coords[3] = { 0, 0, 0 };
		int move[3] = { 0, 0, 0 };
		std::string thread = "";
		int doors = 0;
		int chosen = 0; // Mainly used for moving specific vehicle types
	};
	static std::vector<int> ProcessVehicleTypes(Pattern pattern);
public:
	static void Initialise();
	static std::vector<Pattern> Patterns;
	static void InitialiseVehiclePatterns();
	static int GetIDBasedOnPattern(int origModel, int x, int y, int z, char* thread);
};