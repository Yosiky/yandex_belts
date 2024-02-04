#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// enum class Gender {
//   FEMALE,
//   MALE
// };

// struct Person {
//   int age;  // возраст
//   Gender gender;  // пол
//   bool is_employed;  // имеет ли работу
// };

// // Это пример функции, его не нужно отправлять вместе с функцией PrintStats
// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//   if (range_begin == range_end) {
//     return 0;
//   }
//   vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//   auto middle = begin(range_copy) + range_copy.size() / 2;
//   nth_element(
//       begin(range_copy), middle, end(range_copy),
//       [](const Person& lhs, const Person& rhs) {
//         return lhs.age < rhs.age;
//       }
//   );
//   return middle->age;
// }

void PrintStats(vector<Person> persons) {

	int median_age, all_females, 
		all_males, employed_females, 
		unemployed_females, employed_males, 
		unemployed_males;

	median_age = ComputeMedianAge(std::begin(persons), std::end(persons));

	auto start_males = std::partition(persons.begin(), persons.end(), [](const Person &a) { return (a.gender == Gender::FEMALE); });
	all_females = ComputeMedianAge(std::begin(persons), start_males);
	all_males = ComputeMedianAge(start_males, std::end(persons));

	auto start_unemployed_females = std::partition(persons.begin(), start_males, [](const Person &a) { return (a.is_employed); });
	auto start_unemployed_males = std::partition(start_males, persons.end(), [](const Person &a) { return (a.is_employed); });
	employed_females = ComputeMedianAge(persons.begin(), start_unemployed_females);
	unemployed_females = ComputeMedianAge(start_unemployed_females, start_males);
	employed_males = ComputeMedianAge(start_males, start_unemployed_males);
	unemployed_males = ComputeMedianAge(start_unemployed_males, persons.end());

	std::cout << "Median age = " << median_age << std::endl;
	std::cout << "Median age for females = " << all_females << std::endl;
	std::cout << "Median age for males = " << all_males << std::endl;
	std::cout << "Median age for employed females = " << employed_females << std::endl;
	std::cout << "Median age for unemployed females = " << unemployed_females << std::endl;
	std::cout << "Median age for employed males = " << employed_males << std::endl;
	std::cout << "Median age for unemployed males = " << unemployed_males << std::endl;
}

// int main() {
//   vector<Person> persons = {
//       {31, Gender::MALE, false},
//       {40, Gender::FEMALE, true},
//       {24, Gender::MALE, true},
//       {20, Gender::FEMALE, true},
//       {80, Gender::FEMALE, false},
//       {78, Gender::MALE, false},
//       {10, Gender::FEMALE, false},
//       {55, Gender::MALE, true},
//   };
//   PrintStats(persons);
//   return 0;
// }

