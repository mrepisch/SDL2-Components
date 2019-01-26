#include "EvenSystemCore.h"



EvenSystemCore::EvenSystemCore()
{
}


EvenSystemCore::~EvenSystemCore()
{
}

void EvenSystemCore::update()
{
	for (auto event : m_eventsToProcess)
	{
		if (event != nullptr)
		{
			event->handleEvent();
			delete event;
			event = nullptr;
		}
	}
	m_eventsToProcess.clear();

}

void EvenSystemCore::addEvent(IEvent * eventPtr)
{
	if (eventPtr)
	{
		m_eventsToProcess.push_back(eventPtr);
	}
}

