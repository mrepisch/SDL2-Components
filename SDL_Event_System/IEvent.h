#pragma once
#include "EvenSystemExport.h"
#include <string>
#include <map>

class SDL_EVENT_SYSTEM_API IEvent
{
public:

	virtual void setEventData(std::map<std::string, std::string>data) = 0;
	virtual void handleEvent() = 0;
};