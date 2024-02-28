#include <iostream>
#include <deque>
#include <string>


int main(void) {
	std::deque<std::string> ans;
	int value;
	std::string sign;
	int n;

	std::cin >> value;
	std::cin >> n;
	ans.push_back(std::to_string(value));
	for (int i = 0; i < n; ++i) {
		std::cin >> sign >> value;
		ans.push_back(") " + sign + " " + std::to_string(value));
		ans.push_front("(");
	}
	for (const auto &i: ans)
		std::cout << i;
	return (0);
}
