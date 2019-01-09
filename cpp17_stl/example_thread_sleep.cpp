#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono_literals;


void example_thread_sleep()
{

	cout << "Going to sleep fro 5 seconds"
			" and 300 milli seconds .\n";

	this_thread::sleep_for(5s + 300ms);
	cout << "Going to sleep for anthoer 3 seconds .\n";;
	this_thread::sleep_until(chrono::high_resolution_clock::now() + 3s);
	cout << "That's it";

}


