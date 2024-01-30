#include <iostream>
#include <vector>

int main(void) {
	int n, r;
	unsigned long long weight = 0;
	unsigned long long w, h, d;

	std::cin >> n >> r;
	for (int i = 0; i < n; ++i) {
		std::cin >> w >> h >> d;
		weight += w * h * d * r;
	}
	std::cout << weight << std::endl;
	return (0);
}
