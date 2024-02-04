#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// template <class RandomIt, class OutputIt>
// void merge(RandomIt first1, RandomIt last1, RandomIt first2, RandomIt last2, OutputIt res) {
// 	while (first1 != last1 && first2 != last2) {
// 		if (*first1 < *first2)
// 			*(res++) = *first1++;
// 		else 
// 			*(res++) = *first2++;
// 	}
// 	while (first1 != last1) {
// 		*(res++) = *first1++;
// 	}
// 	while (first2 != last2) {
// 		*(res++) = *first2++;
// 	}
// }

// template <class T>
// void PrintArray(std::vector<T> elements) {
// 	std::cout << "Array: ";
// 	for (const auto &i : elements)
// 		std::cout << i << ' ';
// 	std::cout << std::endl;
// }

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	size_t size = std::distance(range_begin, range_end);

	if (size < 2)
		return ;

	// std::cout << "Size: " << size << std::endl;
	size /= 3;
	auto first_bound = range_begin + size;
	auto second_bound = first_bound + size;

	std::vector<typename RandomIt::value_type> v1(range_begin, first_bound);
	std::vector<typename RandomIt::value_type> v2(first_bound, second_bound);
	std::vector<typename RandomIt::value_type> v3(second_bound, range_end);

	MergeSort(std::begin(v1), std::end(v1));
	MergeSort(std::begin(v2), std::end(v2));
	MergeSort(std::begin(v3), std::end(v3));

	std::vector<typename RandomIt::value_type> time;
	// PrintArray(elements);
	std::merge(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2), std::back_inserter(time));
	// PrintArray(elements);
	std::merge(std::begin(time), std::end(time), std::begin(v3), std::end(v3), range_begin);
	// PrintArray(elements);
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  // vector<int> v = {6, 4, 7};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
