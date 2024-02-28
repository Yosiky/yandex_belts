#include <iostream>
#include <deque>
#include <string>


int main(void) {
	std::deque<std::string> ans;
	int value;
	std::string sign;
	int n;
	bool type_sign = false;

	std::cin >> value;
	std::cin >> n;
	ans.push_back(std::to_string(value));
	for (int i = 0; i < n; ++i) {
		std::cin >> sign >> value;

		if (type_sign && (sign == "*" || sign == "/")) {
			ans.push_back(")");
			ans.push_front("(");
		}
		ans.push_back(" " + sign + " " + std::to_string(value));
		type_sign = sign == "-" || sign == "+";
	}
	for (const auto &i: ans)
		std::cout << i;
	return (0);
}
