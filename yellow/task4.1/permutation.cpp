#include <iostream>
#include <vector>
#include <algorithm>


int main(void) {
	int n;

	std::cin >> n;
	std::vector<int> range(n, 0);
	for (int i = 1; i <= n; ++i) {
		range[n - i] = i;
		std::cout << n - i + 1 << ' ';
	}
	std::cout << std::endl;
	while (std::prev_permutation(std::begin(range), std::end(range))) {
		for (auto &i : range)
			std::cout << i << ' ';
		std::cout << std::endl;
	}
	return (0);
}
