#include <map>
#include <vector>
#include <tuple>

using namespace std;

// enum class Lang {
//   DE, FR, IT
// };

// struct Region {
//   string std_name;
//   string parent_std_name;
//   map<Lang, string> names;
//   int64_t population;
// };

bool operator<(const Region &lhs, const Region &rhs) {
	return (tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < 
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population));
}

int FindMaxRepetitionCount(const std::vector<Region>& regions) {
	std::map<Region, int> m;
	int max_count = 0;

	for (const auto &key : regions) {
		++m[key];
		max_count = std::max(max_count, m[key]);
	}
	return (max_count);
}
