#pragma once
class IEngine
{
public:
	void virtual SetTeng(float Teng) = 0;
	float virtual GetTeng() = 0;
	float virtual GetTmax() = 0;

	float virtual GetTadd(float V) = 0;
	float virtual GetTsub(float Tenv) = 0;
	float virtual GetAcceleration(float V) = 0;
};

