#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Comp {
    bool operator()(const std::string &lft, const std::string &rht) const {
		return (lft < rht);
	}
};

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const std::string& prefix) {
	// NOTE:	в их решении прост скопировали строку prefix и увеличили последний элемент

	return (std::make_pair(
				std::lower_bound(range_begin, range_end, prefix),
				std::upper_bound(range_begin, range_end, prefix,
					[](const std::string &lft, const std::string &rth) {
						auto s1 = lft.begin();
						auto s2 = rth.begin();

						while (s1 != lft.end() && s2 != rth.end()) {
							if (*s1 == *s2) {
								s1 = std::next(s1);
								s2 = std::next(s2);
							}
					 		else return (*s1 < *s2);
						}
					 	if (s1 == lft.end() || s2 == rth.end())
					 		return (false);
						return (true);
					}))); // NOTE:	нужно проверить лексиграфичесое сравнение строк.
}

int main() {
	vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

	std::sort(sorted_strings.begin(), sorted_strings.end());
	for (const auto &i : sorted_strings)
		std::cout << i << " ";
	std::cout << std::endl;
	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
	  cout << *it << " ";
	}
	cout << endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << endl;

	return 0;
}
