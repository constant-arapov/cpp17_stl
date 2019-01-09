#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <tuple>
#include <iterator>
#include <algorithm>
#include <random>

using namespace std;


namespace std {
	ostream & operator << (ostream & os, const pair <int, string> &p)
	{
		return os << "(" << p.first << ", " << p.second << " )";
	}


}



void example_copy_containers()
{
	vector <pair <int, string>> v{
		{1,"one"}, {2,"two"}, {3,"three"},
		{4,"four"}, {5,"five"} 
	};
	map <int, string> m;
	copy_n(begin(v), 3, inserter(m, begin(m)));

	auto shell_it(ostream_iterator<pair<int, string>>{cout, ","});
	copy(begin(m), end(m), shell_it);
	cout << '\n';
	m.clear();
	move(begin(v), end(v), inserter(m, begin(m)));

	copy(begin(m), end(m), shell_it);
	cout << '\n';
	copy(begin(v), end(v), shell_it);
	cout << '\n';

}


static void print(const vector<int> &v)
{
	copy(begin(v), end(v), ostream_iterator<int> {cout, ", "});
	cout << '\n';

}


void example_sort()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	random_device rd;
	mt19937 g{ rd() };
	cout << is_sorted(begin(v), end(v)) << '\n';
	
	shuffle(begin(v), end(v), g);
	cout << is_sorted(begin(v), end(v)) << '\n';
	sort(begin(v), end(v));
	cout << is_sorted(begin(v), end(v)) << '\n';
	print(v);
	
	shuffle(begin(v), end(v), g);
	print(v);
	partition(begin(v), end(v), [](int i) {return i < 5; });
	print(v);

	shuffle(begin(v), end(v), g);
	auto middle(next(begin(v), int(v.size()) / 2));
	partial_sort(begin(v), middle, end(v));
	print(v);

}


void example_transform()
{

	vector < int> v{1, 2, 3, 4, 5 };
	transform(begin(v), end(v), ostream_iterator<int>{cout, ","},
				[](int i) {return i * i; });

}

struct city {
	string name;
	unsigned population;
};


bool operator == (const city &a, const city &b) {
	return a.name == b.name && a.population == b.population;
}


ostream &operator <<(ostream & os, const city &city) {
	return os << "{" << city.name << ", "
		<< city.population << "}";
}


template <typename C>
static auto opt_print(const C & container)
{
	return [en_it (end(container)) ](const auto & item){
		
		if (item != en_it) {
			cout << *item << '\n';
		}
		else {
			cout << "<end>\n";
		}
		
		

	
	
	};


}




void example_find()
{
	const vector <city> c{
		{"Aachen", 246000},
		{"Berlin", 3502000},
		{"Braunschweig", 251000},
		{"Cologne", 1060000}

	};

	auto print_city(opt_print(c));
	/*
	auto found_cologne(find(begin(c), end(c),
			city{ "Cologne", 1060000 }));
			*/

	
	auto found_cologne (find_if (begin(c), end(c),
		[](const auto &item) {
		return item.name == "Cologne";
	}
	));
	print_city(found_cologne);


	auto population_more_than([](unsigned i) {
		return [=](const city &item)
		{
			return item.population > i;
		};
	}	
	
	);

	auto found_large(find_if(begin(c), end(c), population_more_than(2000000)));
	print_city(found_large);


}

void example_binary_search()
{
	const vector <int> v{ 1,2,3,4,5,6,7,8,9,10 };
	auto print_int(opt_print(v));
	auto contains_7{ binary_search(begin(v),end(v),7) };
	cout << contains_7 << '\n';
	auto[lower_it, upper_it](equal_range(begin(v), end(v), 7));
	print_int(lower_it);
	print_int(upper_it);


}


