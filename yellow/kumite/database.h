#ifndef DATABASE_HPP
# define DATABASE_HPP

# include <ostream>
# include <functional>
# include <map>
# include <deque>
# include <list>
# include "date.h"

class Database {

	std::map<Date, std::deque<std::string>> um;

public:

	void Add(const Date &date, const std::string &event);
	void Print(std::ostream &out) const;
	int RemoveIf(std::function<bool (const Date &, const std::string &)> func);
	std::list<std::pair<Date, std::string>> FindIf(std::function<bool (const Date &, const std::string &)> func);
	const std::string Last(const Date &date);

};

template <class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &event) {
	out << event.first << ' ' << event.second;
	return (out);
}

#endif
