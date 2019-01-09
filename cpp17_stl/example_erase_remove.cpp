#include <iostream>
#include <vector>
#include <algorithm>

#include "example_erease_remove.hpp"

using namespace std;


void example_erase_remove()
{
	vector<int> v{ 1, 2, 3, 2, 5, 2, 6, 2, 4, 8 };

	//--
	//first remove 2 (but  having "garbage" after 8)
	const auto new_end(remove(begin(v), end(v), 2));
	//do erease garbage after 8
	v.erase(new_end, end(v));
	//----
	for (auto i : v)
	{
		cout << i << ", ";
	}

	cout << '\n';

	//--
	const auto odd([](int i) {return i % 2 != 0; });
	v.erase(remove_if(begin(v), end(v), odd), end(v));
	//--
	//... but vector's capacity it still 10
	v.shrink_to_fit();

	for (auto i : v)
	{
		cout << i << ", ";
	}

	cout << '\n';


}