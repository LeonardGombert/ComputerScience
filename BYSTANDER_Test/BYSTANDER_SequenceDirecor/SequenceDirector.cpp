#include "SequenceDirector.h"
#include <chrono>

SequenceDirector::SequenceDirector(const double length) : sequenceDuration{ length } {}

SequenceDirector::~SequenceDirector() {}

bool SequenceDirector::MoveTime()
{
	end = Time::now();
	currentTime = end - start;

	timeMarker = currentTime.count();

	if (currentTime.count() >= sequenceDuration) return false;
	else if (currentTime.count() <= 0) return false;
	return true;
}
