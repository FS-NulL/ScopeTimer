#ifndef SCOPETIMER__3472893
#define SCOPETIMER__3472893

#include <iostream>
#include <chrono>

struct ScopeTimer
{
	std::chrono::high_resolution_clock::time_point start;
	const char* title;

	ScopeTimer()
	{
		title = nullptr;
		start = std::chrono::high_resolution_clock::now();
	}

	ScopeTimer(const char* title)
	{
		this->title = title;
		start = std::chrono::high_resolution_clock::now();
	}

	~ScopeTimer()
	{
		using std::chrono::duration_cast;
		using std::chrono::nanoseconds;
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(end - start);

		std::cout << (title ? title : "") << ": " << duration.count() << " ns\n";
	}
};

#endif