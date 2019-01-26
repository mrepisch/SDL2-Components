#pragma once
#include "EvenSystemExport.h"
#include "IEvent.h"

#include <vector>
class SDL_EVENT_SYSTEM_API EvenSystemCore
{
public:
	EvenSystemCore();
	~EvenSystemCore();

	void update();

	void addEvent(IEvent* eventPtr);
private:
	std::vector<IEvent*>m_eventsToProcess;
};

