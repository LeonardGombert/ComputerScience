#pragma once
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
typedef std::chrono::steady_clock Time;

class SequenceDirector
{
private:
	SequenceDirector(const double); // constructors and destructors are private
	~SequenceDirector();

	static SequenceDirector* instance;
	double sequenceDuration = 0;

	Time::time_point start;
	Time::time_point end;
	std::chrono::duration<double> currentTime;
	double timeMarker;

public:
	static void LazyInititalizeSingleton(const double x) { instance = new SequenceDirector(x); }
	static SequenceDirector* getinstance() { return instance; }

	void StartSequence() { start = Time::now(); }
	bool MoveTime();
};
