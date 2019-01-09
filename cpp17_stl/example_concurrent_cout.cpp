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

static void print_cout(int id)
{
	this_thread::sleep_for(1ms);
	cout << "count hello from" << id << '\n';
}


static void print_pcout(int id)
{
	this_thread::sleep_for(1ms);
	pcout{} << "pcout hello from" << id << '\n';
}

void example_concurrent_cout()
{
	vector<thread> v;
	for (int i{ 0 }; i < 10; ++i)
	{
		v.emplace_back(print_cout, i);
	}


	for (auto &t : v) { t.join(); }

	cout << "=======" << endl;
	v.clear();

	for (int i{ 0 }; i < 10; ++i) {
		v.emplace_back(print_pcout, i);
	}

	for (auto &t : v) { t.join(); }



}