#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Person {

	std::map<int, std::pair<std::string, std::string>> m;


public:
	void ChangeFirstName(int year, const string& first_name) {
		m[year].first = first_name;
  	}

  	void ChangeLastName(int year, const string& last_name) {
		m[year].second = last_name;
  	}

	pair<std::string *, std::string *> findString(int year) {
		auto it = m.upper_bound(year);
		std::string *ptr_name = nullptr;
		std::string *ptr_surname = nullptr;

		if (it == m.begin())
			return (std::make_pair(ptr_name, ptr_surname));

		do {
			it = std::prev(it);
			if (ptr_name == nullptr && it->second.first != "") {
				ptr_name = &it->second.first; 
			}
			if (ptr_surname == nullptr && it->second.second != "") {
				ptr_surname = &it->second.second;
			}
		} while (m.begin() != it && (ptr_name == nullptr || ptr_surname == nullptr));
		return (std::make_pair(ptr_name, ptr_surname));
	}


	string GetFullName(int year) {
		auto it = findString(year);
		if (it.first == nullptr && it.second == nullptr)
			return ("Incognito");
		else if (it.first == nullptr && it.second != nullptr)
			return (*it.second + " with unknown first name");
		else if (it.first != nullptr && it.second == nullptr) 
			return (*it.first + " with unknown last name");
		else
			return (*it.first + " " + *it.second);
			// получить имя и фамилию по состоянию на конец года year
			// с помощью двоичного поиска
  	}
};


int main() {
	Person person;
	
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
	  cout << person.GetFullName(year) << endl;
	}
	
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
	  cout << person.GetFullName(year) << endl;
	}
	
	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
	  cout << person.GetFullName(year) << endl;
	}
	
	return 0;
}
