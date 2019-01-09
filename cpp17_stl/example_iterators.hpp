#ifndef  _EXAMPLE_ITERATORS_
#define  _EXAMPLE_ITERATORS_



void example_custom_iterator();
void example_iterator_adapter();

class num_iterator
{
	int i;
public :
	explicit  num_iterator(int position = 0) : i{ position } {}
	
	int operator*() const { return i; }

	num_iterator& operator++()
	{
		++i;
		return *this;
	}

	bool operator!=(const num_iterator &other) const
	{
		return i != other.i;
	}

	bool operator == (const num_iterator &other) const
	{
		return !(*this != other);

	}



};



//note: need for g++, no need for VC++ 
namespace std {
template <>
struct iterator_traits <num_iterator>
{
	using iterator_category = std::forward_iterator_tag;
	using value_type = int;


};


}




class num_range
{
	int a;
	int b;

public:
	num_range (int from, int to)
		:a{from}, b{to}
	{}
	num_iterator begin() const { return num_iterator{ a }; }
	num_iterator end() const { return num_iterator{ b }; }

};


#endif // ! _EXAMPLE_ITERATORS_