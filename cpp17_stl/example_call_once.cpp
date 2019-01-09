#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


using namespace std;

once_flag callflag;

static void once_print()
{
	cout << '!';
}

static void print(size_t x)
{
	call_once(callflag, once_print);
	cout << x;

}
void example_call_once()
{
	vector <thread> v;

	for (int i{ 0 }; i < 10; ++i) {
		v.emplace_back(print, i);
	}

	for (auto &t : v) { t.join(); }
	cout << '\n';

}




