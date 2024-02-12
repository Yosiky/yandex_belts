#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers,
    int border) {
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел
	std::set<int>::const_iterator ans = numbers.upper_bound(border);
	int cmp = 0;
	
	if (ans != std::begin(numbers)) {
		auto left = prev(ans);
		cmp = abs(border - *left) - abs(border - *ans);
		if (cmp <= 0)
			ans = left;
	}
	return (ans);
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
