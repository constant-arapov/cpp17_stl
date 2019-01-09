#include <sstream>
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;



template <typename T>
auto map(T fn)
{
	return [=](auto reduce_fn) {
		return [=](auto accum, auto input) {
			return reduce_fn(accum, fn(input));
		};
	};
}

template <typename T>
auto filter(T predicate)
{
	return[=](auto map_fn){
		return [=](auto accum, auto input) {
			if (predicate(input)) {
				return map_fn(accum, input);
			}
			else {
				return accum;
			}
		};


	};
}

void example_lambda_transform()
{
	stringstream ss;
	ss << "1 2 3 4 5 6";
	istream_iterator<int> it{ ss };
	istream_iterator<int> end_it;

	auto even([] (int i) {return i % 2 == 0; });
	auto twice([](int i) {return i * 2; });

	auto copy_and_advance([](auto it, auto input) {
		*it = input;
		return  ++it;
	});
	
	accumulate(it, end_it,
		ostream_iterator<int>{cout, ", "},
		filter(even)(map(twice) (copy_and_advance)));
			
	

	
				
			

	

	//auto res = copy_and_advance(it, end_it);


	cout << '\n';
}
