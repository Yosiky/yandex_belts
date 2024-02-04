#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	size_t size = std::distance(range_begin, range_end);
	if (size < 2u)
		return ;
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	
	size /= 2;
	auto left = std::begin(elements);
	auto right = std::begin(elements) + size;
	MergeSort(left, right);
	MergeSort(right, std::end(elements));
	auto i = range_begin;
	while (left != std::begin(elements) + size && right != std::end(elements)) {
		if (*left < *right)
			*i = *left++;
		else 
			*i = *right++;
		++i;
	}
	while (left != std::begin(elements) + size) {
		*i = *left++;
		++i;
	}
	while (right != std::end(elements)) {
		*i = *right++;
		++i;
	}
}

// int main() {
//   vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
//   MergeSort(begin(v), end(v));
//   for (int x : v) {
//     cout << x << " ";
//   }
//   cout << endl;
//   return 0;
// }
