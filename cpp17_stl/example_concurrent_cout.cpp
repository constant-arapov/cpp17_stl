#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <vector>

using namespace std;

struct pcout : public stringstream {
	static inline mutex cout_mutex;
	~pcout()
	{
		lock_guard <mutex> l{ cout_mutex };
		cout << rdbuf();
		cout.flush();
	}
};

static void print_cout()
{

}


void example_concurrent_cout()
{

}