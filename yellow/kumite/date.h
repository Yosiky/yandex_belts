#ifndef DATE_H
# define DATE_H

# include <iomanip>
# include <sstream>
# include <iostream>

class Date {

	int year;
	int month;
	int day;

public:

	Date(void) = delete;
	Date(int year, int month, int day);
	Date(const Date &date) = default;
	~Date(void) = default;

	// void setDate(int year, int month, int day);
	int getYear(void) const;
	int getMonth(void) const;
	int getDay(void) const;

};

Date ParseDate(std::istringstream &is);
std::ostream &operator<<(std::ostream &out, const Date &date);

// NOTE:	logical operation
bool operator<(const Date &lft, const Date &rht);
bool operator<=(const Date &lft, const Date &rht);
bool operator>(const Date &lft, const Date &rht);
bool operator>=(const Date &lft, const Date &rht);
bool operator==(const Date &lft, const Date &rht);
bool operator!=(const Date &lft, const Date &rht);

#endif
