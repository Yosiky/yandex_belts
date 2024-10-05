#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time
#define UPDATE_FIELD(ticket, field, values)																		\
	do {																																				\
		auto it = values.find(#field);																						\
		if (it != values.end()) {																									\
			std::istringstream is(it->second);																			\
			is >> ticket.field;																											\
		}																																					\
	} while (0);

bool operator==(const Date &lft, const Date &rht) {
	return (lft.year == rht.year && lft.month == rht.month && lft.day == rht.day);
}

bool operator==(const Time &lft, const Time &rht) {
	return (lft.hours == rht.hours && lft.minutes == rht.minutes);
}

std::ostream &operator<<(std::ostream &out, const Time &t) {
	out << t.hours << ' ' << t.minutes;
	return (out);
}

std::istream &operator>>(std::istream &in, Time &t) {
	in >> t.hours;
	in.ignore(1);
	in >> t.minutes;
	return (in);
}

std::ostream &operator<<(std::ostream &out, const Date &d) {
	out << d.year << ' ' << d.month << ' ' << d.day;
	return (out);
}

std::istream &operator>>(std::istream &in, Date &d) {
	in >> d.year;
	in.ignore(1);
	in >> d.month;
	in.ignore(1);
	in >> d.day;
	return (in);
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
