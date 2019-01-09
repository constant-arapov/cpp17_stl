#include <iostream>
#include <functional>
#include <list>
#include <map>
#include <string>


using namespace std;


struct billionaire {
	string name;
	double dollars;
	string country;
};

void example_insert_std_map()
{
	list <billionaire> billionaires
	{
		{"Bill Gates", 86.0, "USA"},
		{"Warren Buffet", 75.6, "USA"},
		{"Jeff Bezos", 72.8, "USA"},
		{"Amancio Ortega", 71.3, "Spain"},
		{"Mark Zuckerberg", 56.0, "USA"},
		{"Carlos Slim", 54.5, "Mexico"},
		{"Bernard Arnault", 41.5, "France"},
		{"Liliance Bettercourt", 39.5, "France"},
		{"Wang Jianlin", 31.3, "China"},
		{"Li Ka-shing", 31.2, "Hong Kong" }

	};

	map<string, pair<const billionaire, size_t>>m;

	for (auto &b : billionaires)
	{
		auto[iterator,success] = m.try_emplace(b.country, b, 1);
			
		if (!success)		
			iterator->second.second++;	
	}

	for (const auto &[key, value] : m)
	{
		const auto&[b, count] = value;

		cout << b.country << ": " << count
			<< " billinoaries. Richest is "
			<< b.name << " with " << b.dollars
			<< " B$\n";
	}

}

void example_insert_map_hint()
{
	map<string, size_t> m{ {"b",1}, {"c",2}, {"d",3} };
	auto insert_it(end(m));

	for (const auto &s : { "z","y","x","w" })
	{
		insert_it = m.insert(insert_it, { s,1 });
	}

	//don't use - for testing only
	m.insert(end(m), { "a",1 });
	

}


