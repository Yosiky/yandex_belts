#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

struct Comp
{
    bool operator()(char lft, const std::string &rht) const {
		return (lft < rht[0]); 
	}

    bool operator()(const std::string &lft, char rht) const {
		return (lft[0] < rht);
	}
};

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    	RandomIt range_begin, RandomIt range_end,
    	char prefix) {
	return (std::equal_range(range_begin, range_end, prefix, Comp{}));
}

int main() {
	const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
	
	const auto m_result =
	    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it) {
	  cout << *it << " ";
	}
	cout << endl;
	
	const auto p_result =
	    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " <<
	    (p_result.second - begin(sorted_strings)) << endl;
	
	const auto z_result =
	    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " <<
	    (z_result.second - begin(sorted_strings)) << endl;
	
	return 0;
}
