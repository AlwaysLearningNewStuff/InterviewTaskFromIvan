#include "Utilities.h"

void Clocks::StopWatch::Start()
{
	start = std::chrono::steady_clock::now();
}

void Clocks::StopWatch::Stop()
{
	end = std::chrono::steady_clock::now();
}

void Clocks::StopWatch::Reset()
{
	start = std::chrono::steady_clock::time_point{std::chrono::milliseconds::zero()};
	end = std::chrono::steady_clock::time_point{ std::chrono::milliseconds::zero() };
}

double Clocks::StopWatch::ElapsedTime() const
{
	using Duration = std::chrono::duration<double, std::milli>;
	return std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
}