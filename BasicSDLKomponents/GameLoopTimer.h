#pragma once

#include <cstddef>
#include <stdint.h>
class GameLoopTimer
{
public:
	GameLoopTimer();
	~GameLoopTimer();
	void start();
	void pause();
	void unpause();
	void stop();
	uint32_t getTicks();

private:
	uint32_t mStartTicks;

	uint32_t mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;
};

