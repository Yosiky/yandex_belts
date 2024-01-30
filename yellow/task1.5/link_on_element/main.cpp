#include <iostream>
#include <stdexcept>
#include <map>

template <class Key, class Value>
Value &GetRefStrict(std::map<Key, Value> &m, const Key &k) {
	auto iter = m.find(k);
	if (iter == m.end()) {
		throw (std::runtime_error("Key doesn't exist"));
	}
	return (iter->second);
}

using namespace std;

int main(void) {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	return (0);
}
