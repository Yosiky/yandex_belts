#include "phone_number.h"
#include <stdexcept>
#include <iostream>
#include <cctype>

#define DEBUG_PRINT(value) std::cout << #value ": " << (value) << std::endl

PhoneNumber::PhoneNumber(const string &number) {
	if (number.size() == 0 || number[0] != '+')
		throw std::invalid_argument("Number = " + number + "\nIndex = " + std::to_string(0));
	int i = 1; 
	int last;
	for (i = 1; i < number.size() && number[i] != '-'; ++i) ; // contry code
	if (i == 1 || i >= number.size() || number[i] != '-' || (i - 1) > 3)
		throw std::invalid_argument("Number = " + number + "\nIndex = " + std::to_string(i));
	country_code_ = number.substr(1, i - 1);
	last = ++i;
	for (; i < number.size() && number[i] != '-'; ++i) ;		// city code
	if (i == last || i >= number.size() || number[i] != '-' || (i - last) > 3)
		throw std::invalid_argument("Number = " + number + "\nIndex = " + std::to_string(i));
	city_code_ = number.substr(last, i - last);
	last = ++i;
	i = number.size();
	local_number_ = number.substr(last, i - last);
}

string PhoneNumber::GetCountryCode() const {
	return (country_code_);
}

string PhoneNumber::GetCityCode() const {
	return (city_code_);
}

string PhoneNumber::GetLocalNumber() const {
	return (local_number_);
}

string PhoneNumber::GetInternationalNumber() const {
	return ("+" + country_code_ + "-" + city_code_  + "-" + local_number_);
}


