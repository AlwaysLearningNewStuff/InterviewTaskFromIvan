#pragma once
#include <chrono>

namespace Clocks
{
	class StopWatch
	{
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
	public:
		StopWatch() : 
			start{std::chrono::milliseconds::zero()}, 
			end{std::chrono::milliseconds::zero()} 
		{}
		void Start();
		void Stop();
		void Reset();
		double ElapsedTime() const;
	};
}