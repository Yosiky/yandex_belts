#include "phone_number.h"
#include <iostream>


int main(void) {
	std::string value;

	std::cin >> value;
	PhoneNumber my(value);
	std::cout << "Contry: " << my.GetCountryCode() << std::endl;
	std::cout << "City: " << my.GetCityCode() << std::endl;
	std::cout << "Local: " << my.GetLocalNumber() << std::endl;
	std::cout << "International: " << my.GetInternationalNumber() << std::endl;
	return (0);
}
