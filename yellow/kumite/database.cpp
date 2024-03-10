#include "database.h"

void Database::Add(const Date &date, const std::string &event) {
	if (um.count(date)) {
		auto &list = um[date];
		auto it = std::find(list.begin(), list.end(), event);
		
		if (it != list.end())
			return ;
	}
	um[date].push_back(event);
}

void Database::Print(std::ostream &out) const  {
	for (const auto &[key, list]: um) {
		for (const auto &i : list) {
			out << key << " " << i << std::endl;
		}
	}
}

int Database::RemoveIf(std::function<bool (const Date &, const std::string &)> func) {
	int count_delete = 0;
	std::list<const Date> l;

	for (auto &[key, deq] : um) {
		auto it_new_end = std::remove_if(deq.begin(), deq.end(), 
			[&count_delete, &key, func](const std::string &str) {
				if (func(key, str)) {
					++count_delete;
					return (true);
				}
				return (false);
			});
		deq.erase(it_new_end, deq.end());
		if (deq.size() == 0)
			l.push_back(key);
	}
	for (const auto &i : l)
		um.erase(i);
	return (count_delete);
}

std::list<std::pair<Date, std::string>> Database::FindIf(std::function<bool (const Date &, const std::string &)> func) {
	std::list<std::pair<Date, std::string>> answer;

	for (auto &[key, deq] : um) {
		for (auto &i : deq) {
			if (func(key, i))
				answer.push_back({key, i});
		}
	}
	return (answer);
}

const std::string Database::Last(const Date &date) {
	std::ostringstream answer;
	auto it = um.upper_bound(date);

	if (it != um.begin()) {
		it = std::prev(it);
		auto it_last_elem = it->second.end();

		if (it_last_elem != it->second.begin()) {
			it_last_elem = std::prev(it_last_elem);
			answer << it->first << ' ' << *it_last_elem;
		}
		else 
			answer << "No entries";
	}
	else
		answer << "No entries";

	return (answer.str());
}


