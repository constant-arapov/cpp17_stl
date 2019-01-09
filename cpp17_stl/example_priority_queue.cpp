#include <iostream>
#include <queue>
#include <tuple>
#include <string>


using  namespace std;



void example_priority_queue()
{
	using item_type = pair<int, string>;
	priority_queue<item_type> q;

	initializer_list<item_type> il
	{
		{1,"dishes"},
		{0,"watch tv"},
		{2, "do homework"},
		{0, "read comics"}

	};

	for (const auto &p : il)
	{
		q.push(p);
	}


	while (!q.empty())
	{
		cout << q.top().first << " : " << q.top().second << '\n';
		q.pop();
	}

	cout << '\n';
}