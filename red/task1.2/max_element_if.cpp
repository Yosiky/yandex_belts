#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>
#include <iterator>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
	first = std::find_if(first, last, pred);
	auto ans = first;
	
	for (auto i = first; i != last; i = std::next(i)) {
		if (pred(*i) && *ans < *i)
			ans = i;
	}
	return (ans);
}