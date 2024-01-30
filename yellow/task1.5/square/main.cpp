#include <iostream>
#include <map>
#include <vector>

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(const T &i);
template<typename Lhs, typename Rhs> std::pair<Lhs, Rhs> Sqr(const std::pair<Lhs, Rhs> &);
template<typename T> std::vector<T> Sqr(const std::vector<T> &);
template<typename Key, typename Value> std::map<Key, Value> Sqr(const std::map<Key, Value> &);

template<typename T>
T Sqr(const T &i) {
	return (i * i);
}

template <typename Lhs, typename Rhs>
std::pair<Lhs, Rhs> Sqr(std::pair<Lhs, Rhs> &p) {
	Lhs first = p.first * p.first;
	Rhs second = p.second * p.second;

	return (std::pair(first, second));
}

template <typename T>
std::vector<T> Sqr(const std::vector<T> &v) {
	std::vector<T> copy = v;

	for (auto &i : copy)
		i = Sqr(i);
	return (copy);
}

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value> &m) {
	std::map<Key, Value> copy = m;

	for (auto &[key, value] : copy) 
		value = Sqr(value);
	return (copy);
}

using namespace std;

int main(void) {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
		{4, {2, 2}},
		{7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
}
