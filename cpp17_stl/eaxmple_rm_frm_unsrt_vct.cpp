#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



template <typename T>
void quick_remove_at(vector <T> &v, size_t idx)
{
	//check for overflow
	if (idx < v.size())
	{
		//move last element to with index
		v[idx] = move(v.back());
		//remove last element
		v.pop_back();

	}


}

template <typename T>
void quick_remove_at(vector <T> &v,
	typename vector<T>::iterator it)
{
	if (it != end(v))
	{
		*it = move(v.back());
		v.pop_back();


	}

}

void eaxmple_rm_frm_unsrt_vct()
{	
	vector<int> v{ 123, 456, 789, 100, 200 };

	quick_remove_at(v, 2);


	quick_remove_at(v, find(begin(v), end(v), 123));


	for (auto i : v)
	{
		cout << i << ", ";
	}

	cout << '\n';
	
}




