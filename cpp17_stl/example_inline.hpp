#include <string>

void example_inline();


using namespace std;


class process_monitor {
public:
	inline static const string standard_string
		{"some static globally available string" };


};
inline process_monitor global_process_monitor;
