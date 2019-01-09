#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <deque>


#include "example_iterators.hpp"

using namespace std;


void example_custom_iterator()
{
	for (int i : num_range{ 100,110 })
	{
		cout << i << ", ";
	}
	cout << '\n';


	num_range r { 100,110 };

	auto[min_it, max_it](minmax_element(begin(r), end(r)));

	cout << *min_it << " - " << *max_it << '\n';

}


void example_iterator_adapter()
{
	istream_iterator <int> it_cin{ cin };
	istream_iterator <int> end_cin;

	deque<int> v;
	copy(it_cin, end_cin, back_inserter(v));

	istringstream sstr("123 456 789");
	auto dequeue_middle(next(begin(v), static_cast<int>(v.size()) / 2));
	copy(istream_iterator<int>{sstr}, {}, inserter(v, dequeue_middle));

	initializer_list<int> il2{ -1,-2,-3 };
	copy(begin(il2), end(il2), front_inserter(v));
	copy(begin(v), end(v), ostream_iterator<int> {cout, ", "});
	cout << '\n';
}
