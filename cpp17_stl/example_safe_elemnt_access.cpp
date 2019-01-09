#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void example_safe_element_access()
{
	const size_t container_size{ 1000 };
	vector<int> v(container_size, 123);

	/*
	cout << "Out of range element value: "
		<< v[container_size + 10];
		*/
	try
	{

		cout << "Out of range element value: "
			<< v.at(container_size + 10) << '\n';
	}
	catch (const out_of_range &e)
	{
		cout << "Out of range excpt" << e.what() << '\n';
	}

}

