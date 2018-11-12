#include "Timer.h"



bool Timer::Steps(float mPalier)
{
	stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> t = stop - start;
	if (t.count() > mPalier) {
		start = std::chrono::high_resolution_clock::now();
		return true;
	}

	return false;
}

bool Timer::OneStep(float mPalier)
{
	stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> t = stop - start;
	if (t.count() > mPalier) {
		
		return true;
	}

	return false;
}

void Timer::StartChrono()
{
	start = std::chrono::high_resolution_clock::now();

}

void Timer::StopChrono()
{

}

Timer::Timer()
{
}


Timer::~Timer()
{
}
