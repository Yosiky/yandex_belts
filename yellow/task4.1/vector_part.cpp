#include <iostream>
#include <vector>
#include <algorithm>

void PrintVectorPart(const std::vector<int>& numbers) {
	auto it = std::find_if(std::begin(numbers), std::end(numbers), 
				   [](int i) {
				       return (i < 0);
				   });
	while (it != begin(numbers)) {
		--it;
		std::cout << *it << ' ';
	}
}

// using namespace std;

// int main() {
//   PrintVectorPart({6, 1, 8, -5, 4});
//   cout << endl;
//   PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
//   cout << endl;
//   PrintVectorPart({6, 1, 8, 5, 4});
//   cout << endl;
//   return 0;
// }
