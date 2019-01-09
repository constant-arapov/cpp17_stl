#include <vector>


using namespace std;


template <typename T>
class addable
{

	T val;

	public :
		addable(T v) : val{ v } {}
		
	
		template <typename U>
		T add (U x) const{
			if constexpr (is_same_v<T, vector<U>>) {
				auto copy(val);
				for (auto &n : copy) {
					n += x;
				}
				return copy;
			}
			else {
				return val + x;
			}
		
		}


};





void example_const_expr()
{
	auto res1 = addable<int>{1}.add(2);
	auto res2 = addable<float>{ 1.0 }.add(2);
	auto res3 = addable<string>{ "aa" }.add("bb");

	vector<int> v{ 1,2,3 };
	auto res4 = addable<vector<int>>{v}.add(10);

	vector<string> sv{ "a","b","c" };
	auto res5 = addable<vector<string>>{ sv }.add(string{ "z" });



}