#pragma once
#include "IEngine.h"

class TestStand
{
public:
	static float GetTimeToOverheating(IEngine & engine, float Tenv, float SamStepT);
};

