#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//test functions https://ru.cppreference.com/w/cpp/algorithm
void example_my_algos()
{
	//in examples auto is realy vector<int>::iterator

	vector <int> v_od = { 1,3,5 };
	vector<int> v_ev = { 2,4,6 };


	auto res1 = all_of(v_ev.begin(), v_ev.end(), [](int i) {return i % 2 == 0; });

	
	vector<int> v = { 1,7,2,4,3 };
	auto res2 = any_of(v.begin(), v.end(), [](int i) {return i % 2 == 0; });
	
	auto res3 = none_of(v_od.begin(), v_od.end(), [](int i) {return i % 2 == 0; });
	
	for_each(v.begin(), v.end(), [](int &n) {cout << n << ",";  });
	cout << endl;
	
	//is usefull for single el find
	auto count_of_2 = count(v.begin(), v.end(), 2);

	auto res4 = count_if(v.begin(), v.end(), [](const int &i) {return i % 2 == 0; });

	//---
	//is usefull for single el find
	auto res5 = find(v.begin(), v.end(), 4);
	auto res51 = find(v.begin(), v.end(), 10);
	if (res51 == v.end())
		cout << "no elements found" << endl;
	

	
	auto res6 = find_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; });

	vector<int> v_periodic = {1,5,7,9,1,2,4,1,5,7,4};
	vector<int> v_pattern1 = { 1,5,7 };
	
	
	auto res7 = find_end(v_periodic.begin(), v_periodic.end(), v_pattern1.begin(), v_pattern1.end());
	int num7 = distance(v_periodic.begin(), res7);
	cout << "num begin last entrance: " << num7 << endl;

	auto res8 = find_first_of(v_periodic.begin(), v_periodic.end(), v_pattern1.begin(), v_pattern1.end());	
	int num8 = distance(v_periodic.begin(), res8);
	cout << "num begin last entrance: " << num8 << endl;

	//---

	vector<int> v_dbls{ 7,3,1,1,2,2,3,4,5,6 };
	auto res9 = adjacent_find(v_dbls.begin(), v_dbls.end());
	cout << "first double at num " << distance(v_dbls.begin(), res9) << endl;

	//similar find first
	auto res10 = search(v_periodic.begin(), v_periodic.end(), v_pattern1.begin(), v_pattern1.end());

	auto res11 = search_n(v_dbls.begin(), v_dbls.end(), 2, 1);
	cout << "first double at num " << distance(v_dbls.begin(), res11) << endl;

	vector<int> to_vector(v_dbls.size());
	copy(v_dbls.begin()+1, v_dbls.end(), to_vector.begin());

	vector<int> to_vector_2(v_dbls.size());
	copy_if(v_dbls.begin(), v_dbls.end(), to_vector_2.begin(), [](int i) {return i == 1; });

	vector<int> to_vector_3(v_dbls.size());
	copy_n(v_dbls.begin()+1, 4, to_vector_3.begin());

	vector<int> vct_move { 1,2,3,4,5 };
	move(vct_move.begin(), vct_move.begin() + 2, vct_move.begin() + 3);
	
	vector<int> vct_fill(10);
	fill(vct_fill.begin(), vct_fill.begin()+2, 4);

	//----
	vector<int> vct_rmv{ 1,2,3,4,5 };
	vct_rmv.erase(remove(vct_rmv.begin(), vct_rmv.end(), 2), 
					vct_rmv.end());

	vector<int> vct_rmv_2{ 1,2,3,4,5 };

	vct_rmv_2.erase(
					remove_if(vct_rmv_2.begin(), 
								vct_rmv_2.end(), 
						[](int i) {return i > 3; }),
					vct_rmv_2.end()
					);
		

	//--

	//----
	vector<int> vct_rplc{ 1,7,3,8,5 };
	replace(vct_rplc.begin(), vct_rplc.end(),7,8);
	//-----

	//-----
	vector<int> vct_rplc2{ 1,7,3,8,5 };
	replace_if(vct_rplc2.begin(), vct_rplc2.end(), [](int i) {return i > 3; },0);
	//-----
	
	//---
	vector<int> a{ 1,2 };
	vector<int> b{ 3,4 };
	swap(a, b);
	//---
	vector<int> vct_swp{ 1,2,3 };
	iter_swap(vct_swp.begin(), vct_swp.end()-1);
	//--
	vector<int> vct_dblct{ 1,1,2,2,2,3,3,3,3 };
	vector<int> vct_outp(10);

	unique_copy(vct_dblct.begin(), vct_dblct.end(), vct_outp.begin());
	
	//--
	vector<int> vct_not_srted{ 1,7,3,8,5 };
	bool bSorted = is_sorted(vct_not_srted.begin(), vct_not_srted.end());
	
	vector<int> vct_srted{ 1,2,3,4,5 };
	bSorted = is_sorted(vct_srted.begin(), vct_srted.end());
	//--

	sort(vct_not_srted.begin(), vct_not_srted.end());
	vector<int> vct_not_srted_2{ 1,7,3,8,5 };
	sort(vct_not_srted_2.begin(), vct_not_srted_2.end(), [](int a, int  b) {return a < b; });
	//---
	vector<int> set_A {1,2,3,4,5 };
	vector<int> set_B{ 2,4 };
	vector<int> set_C{ 2,7 };
	bool bIncld = includes(set_A.begin(), set_A.end(), set_B.begin(), set_B.end());
	bIncld = includes(set_A.begin(), set_A.end(), set_C.begin(), set_C.end());
	//---

	auto mx = max_element(set_A.begin(), set_A.end());
	cout << "max=" << *mx << endl;
	//----
	
	
	int sum = accumulate(set_A.begin(), set_A.end(), 0);




}