#include <iostream>
#include <stdexcept>
#include <map>

template <class Key, class Value>
Value &GetRefStrict(std::map<Key, Value> &m, const Key &k) {
	if (auto iter = m.find(k); iter != m.end()) {
		return (iter->second);
	}
	throw (std::runtime_error("Key doesn't exist"));
}

using namespace std;

int main(void) {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	return (0);
}
