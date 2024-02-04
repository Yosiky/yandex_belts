#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto it = std::upper_bound(begin(elements), end(elements), border);
	vector<T> ans;

	while (it != elements.end()) {
		ans.push_back(*it);
		++it;
	}
	return (ans);
}

// int main() {
//   for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
//     cout << x << " ";
//   }
//   cout << endl;
//   
//   string to_find = "Python";
//   cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
//   return 0;
// }
