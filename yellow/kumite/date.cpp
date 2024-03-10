#include "date.h"

Date::Date(int y, int m, int d)
	:	year(y), month(m), day(d) { }

int Date::getYear(void) const {
	return (year);
}

int Date::getMonth(void) const {
	return (month);
}

int Date::getDay(void) const {
	return (day);
}

Date ParseDate(std::istringstream &is) {
	int year, month, day;
	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;

	return (Date(year, month, day));
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
	out << std::setw(4) << std::setfill('0') 
		<< date.getYear();
	out << "-" << std::setw(2) << std::setfill('0') 
		<< date.getMonth();
	out << "-" << std::setw(2) << std::setfill('0')
		<< date.getDay();
	return (out);
}

// NOTE:	implementation logical opeartions
bool operator<(const Date &lft, const Date &rht) {
	if (lft.getYear() == rht.getYear()) {
		if (lft.getMonth() == rht.getMonth()) {
			return (lft.getDay() < rht.getDay());
		}
		return (lft.getMonth() < rht.getMonth());
	}
	return (lft.getYear() < rht.getYear());
}

bool operator<=(const Date &lft, const Date &rht) {
	return (!std::greater<Date>{}(lft, rht));
}

bool operator>(const Date &lft, const Date &rht) {
	if (lft.getYear() == rht.getYear()) {
		if (lft.getMonth() == rht.getMonth()) {
			return (lft.getDay() > rht.getDay());
		}
		return (lft.getMonth() > rht.getMonth());
	}
	return (lft.getYear() > rht.getYear());
}

bool operator>=(const Date &lft, const Date &rht) { 
	return (!std::less<Date>{}(lft, rht));
}

bool operator==(const Date &lft, const Date &rht) {
	return (lft.getYear() == rht.getYear() &&
			lft.getMonth() == rht.getMonth() &&
			lft.getDay() == rht.getDay());
}

bool operator!=(const Date &lft, const Date &rht) {
	return (!std::equal_to<Date>{}(lft, rht));
}

