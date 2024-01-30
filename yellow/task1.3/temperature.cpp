#include <iostream>
#include <vector>

int main(void) {
	std::vector<long long> arr;
	size_t k;
	long long avg = 0;

	std::cin >> k;
	arr.resize(k);
	for (auto &i : arr) {
		std::cin >> i;
		avg += i;
	}
	avg /= static_cast<long long>(arr.size());
	k = 0;
	for (auto &i : arr) {
		if (i > avg)
			++k;
	}
	std::cout << k << std::endl;
	for (size_t i = 0; i < arr.size(); ++i) {
		if (arr[i] > avg)
			std::cout << i << ' ';
	}
	return (0);
}
