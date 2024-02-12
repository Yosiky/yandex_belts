#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

struct Date {
// NOTE: класс описывает точку во вренмени. Точность дни.

	size_t convert_day;

public:

	void set_date(size_t year, size_t month, size_t day) {
		int a = (14 - month) / 12;
		int y = year + 4800 - a;
		int m = month + 12 * a - 3;

		convert_day = day + (153 * m + 2) / 5 + 365 * y + y / 4 + y / 400 - y / 100 - 32045;
	}

	size_t get_day(void) const {
		return (convert_day);
	}
};

bool operator<(const Date &date1, const Date &date2) {
	// NOTE: сравниваем даты.
	return (date1.get_day() < date2.get_day());
}

bool operator<=(const Date &date1, const Date &date2) {
	// NOTE: сравниваем даты.
	return (date1.get_day() <= date2.get_day());
}

size_t operator-(const Date &date2, const Date &date1) {
	if (date1 <= date2)
		return (date2.get_day() - date1.get_day() + 1);
	throw std::runtime_error(std::string(__func__) + ": invalid dates");
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

struct Entry {
	Date point1;
	Date point2;
	double income;
};

int main(void) {
	size_t n;
	std::string command;
	Entry value;
	std::vector<Entry> array;
	int income = 0;

	std::cin >> n;
	std::cout.precision(25);
	for (size_t i = 0; i < n; ++i) {
		std::cin >> command >> value.point1 >> value.point2;

		if (command == "Earn") {
			std::cin >> income;
			value.income = static_cast<double>(income) / (value.point2 - value.point1);
			array.push_back(value);
		} else if (command == "ComputeIncome") {
			value.income = 0;
			// for (auto i = std::begin(array); i != std::end(array); ++i) {
			// 	if (!(i->point2 < value.point1 || value.point2 < i->point1)) {
			// 		value.income += static_cast<double>(std::min(value.point2, i->point2) - std::max(value.point1, i->point1)) * i->income;
			// 	}
			// }
			value.income = std::accumulate(array.begin(), array.end(), 0.0, [ value ](const double &a, const Entry &b) {
				if (!(b.point2 < value.point1 || value.point2 < b.point1))
					return (a + static_cast<double>(std::min(value.point2, b.point2) - std::max(value.point1, b.point1)) * b.income);
				return (a);
				});
			std::cout << value.income << std::endl;
		}
		// std::cout << value.point1 << " " << value.point2 << std::endl;
	}
	return (0);
}
