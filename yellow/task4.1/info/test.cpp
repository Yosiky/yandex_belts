#include <iostream>
#include <iterator>
#include <algorithm>


int main(void) {
	auto it = std::istream_iterator<int>(std::cin);
	auto end = std::istream_iterator<int>();

	std::cout << *adjacent_find(it, end) << std::endl;
	return (0);
}
