#pragma once
#include <chrono>
#include <ctime>

class Timer
{
public: 
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point stop;
	bool Steps(float mPalier);
	bool OneStep(float mPalier);
	void StartChrono(); 
	void StopChrono(); 
public:
	Timer();
	~Timer();
};

