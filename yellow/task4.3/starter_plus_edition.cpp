#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class Date {
// NOTE: класс описывает точку во вренмени. Точность дни.

	uint32_t convert_day;

public:

	uint32_t get_day(void) const {
		return (convert_day);
	}

	void set_date(size_t year, size_t month, size_t day) {
		int a = (14 - month) / 12;
		int y = year + 4800 - a;
		int m = month + 12 * a - 3;

		convert_day = day + (153 * m + 2) / 5 + 365 * y + y / 4 + y / 400 - y / 100 - 32045;
	}

};

struct Enter {
	Date date;
	double income;
};

bool operator<(const Date &date1, const Date &date2) {
	// NOTE: сравниваем даты.
	return (date1.get_day() < date2.get_day());
}

bool operator<(const Enter &date1, const Enter &date2) {
	// NOTE: сравниваем даты.
	return (date1.date.get_day() < date2.date.get_day());
}

bool operator<(const Enter &date1, const Date &date2) {
	// NOTE: сравниваем даты.
	return (date1.date.get_day() < date2.get_day());
}

bool operator<(const Date &date1, const Enter &date2) {
	// NOTE: сравниваем даты.
	return (date1.get_day() < date2.date.get_day());
}

std::istream &operator>>(std::istream &in, Date &obj) {
	char split;
	size_t year, month, day;

	in >> year >> split;
	in >> month >> split;
	in >> day;

	obj.set_date(year, month, day);

	return (in);
}

std::ostream &operator<<(std::ostream &out, const Date &obj) {
	out << "{ Date: " << obj.get_day() << " }";
	return (out);
}

int main(void) {
	std::vector<Enter> v;
	Enter enter;
	Date date1, date2;
	size_t n;
	double income;

	std::cout.precision(25);
	std::cin >> n;
	v.resize(n + 1);
	v[0].income = 0;
	v[0].date.set_date(1000, 1, 1);
	for (size_t i = 1; i <= n; ++i) {
		std::cin >> v[i].date >> v[i].income;
	}
	std::cin >> n;
	// std::partial_sum(std::input_iterator(std::cin), std::input_iterator(), 
	// 				 std::output_iterator(std::cout), 
	// 				 []() {
	// 	})
	std::sort(std::begin(v), std::end(v));
	for (size_t i = 1; i <= v.size(); ++i) {
		v[i].income += v[i - 1].income;
	}
	for (size_t i = 0; i < n; ++i) {
		income = 0;
		std::cin >> date1 >> date2;

		auto start = std::lower_bound(std::begin(v), std::end(v), date1) - 1;
		auto finish = std::upper_bound(std::begin(v), std::end(v), date2) - 1;
		
		std::cout << finish->income - start->income << std::endl;
	}

	return (0);
}
