#include <iostream>

#include <string>
#include <vector>
#include <set>


using namespace std;

template <typename ... Ts>
auto sum(Ts ... ts)
{
	return (ts + ... );
}

template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
	return (count(begin(range), end(range), ts) + ...);
}

template <typename T, typename ... Ts>
bool insert_all(T &set, Ts ... ts)
{
	return (set.insert(ts).second && ...);
}

template <typename T, typename ...Ts>
void insert_all(vector<T> &vec, Ts ...ts)
{
	(vec.push_back(ts), ...);
}




template <typename T, typename ... Ts>
bool within(T min, T max, Ts ... ts)
{
	return ((min <= ts && max >= ts) && ...);
}


void example_fold()
{
	int the_sum{ sum(1,2,3,4,5) };

	string a{"Hello " };
	string b{ "World " };
	cout << sum(a, b) << '\n';

	vector<int> v{ 1,2,3,4,5 };

	auto res1 = matches(v, 2, 5);
	auto res2 = matches(v, 100, 200);

	auto res3 = matches("abcdefg", 'x', 'y', 'z');
	auto res4 = matches("abcdefg", 'a', 'd', 'f');

	//---
	set<int> my_set{ 1,2,3, };
	auto res5 = insert_all(my_set, 4, 5, 6);
	auto res6 = insert_all(my_set, 7, 8, 2);
	
	set<int> my_set2{ 1,2,3, };
	auto res7 = insert_all(my_set2, 4, 2, 5);

	auto res8 = within(10, 20, 1, 15, 30);
	auto res9 = within(10, 20, 11, 12, 13);
	auto res10 = within(5.0, 5.5, 5.1, 5.2, 5.3);

	string aaa{ "aaa" };
	string bcd{ "bcd" };
	string def{ "def" };
	string zzz{ "zzz" };

	auto res11 = within(aaa, zzz, bcd, def);
	auto res12 = within(aaa, def, bcd, zzz);

	vector<int> vect{ 1,2,3 };
	insert_all(vect, 4, 5, 6);
}

