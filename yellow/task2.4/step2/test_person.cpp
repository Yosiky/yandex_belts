#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};


void TestWithoutChanges(void) {
	{
		AssertEqual(Person().GetFullName(2000), "Incognito", "empty change != Incognito");
	}
	{
		Person person;

		person.ChangeLastName(2000, "Pro");
		AssertEqual(person.GetFullName(1000), "Incognito", "set '2000 LastName = Pro', call 1000 != Incognito");
	}
	{
		Person person;

		person.ChangeFirstName(2000, "Pro");
		AssertEqual(person.GetFullName(1000), "Incognito", "set '2000 FirstName = Pro', call 1000 != Incognito");
	}
	{
		Person person;

		person.ChangeFirstName(2000, "Pro");
		person.ChangeLastName(1000, "Pro");
		AssertEqual(person.GetFullName(0), "Incognito", "set '2000 FirstName Pro' set '1000 LastName = Pro', call 0 != Incognito");
	}
}

void TestChangeFirstName(void) {
	{
		Person person;

		person.ChangeFirstName(2000, "Pro");
		AssertEqual(person.GetFullName(1000), "Incognito", "set first name != 'Incognito'");
		AssertEqual(person.GetFullName(2000), "Pro with unknown last name", "set first name != 'Pro with unknown last name'");
		AssertEqual(person.GetFullName(3000), "Pro with unknown last name", "set first name != 'Pro with unknown last name'");
	}
}

void TestChangeSecondName(void) {
	{
		Person person;

		person.ChangeLastName(2000, "Pro");
		AssertEqual(person.GetFullName(1000), "Incognito", "set first name != 'Incognito'");
		AssertEqual(person.GetFullName(2000), "Pro with unknown first name", "set first name != 'Pro with unknown first name'");
		AssertEqual(person.GetFullName(3000), "Pro with unknown first name", "set first name != 'Pro with unknown first name'");
	}
}

void TestFullName(void) {
	{
		Person person;

		person.ChangeFirstName(5, "First");
		person.ChangeLastName(2, "Last");
		AssertEqual(person.GetFullName(1), "Incognito", "set '5 FirstName = First', '2 LastName = Last', call 1 != 'Incognito'");
		AssertEqual(person.GetFullName(3), "Last with unknown first name", "set '5 FirstName = First', '2 LastName = Last', call 3 != 'Last with unknown first name'");
		AssertEqual(person.GetFullName(6), "First Last", "set '5 FirstName = First', '2 LastName = Last', call 6 != 'First Last'");
	}
	{
		Person person;

		person.ChangeFirstName(2, "First");
		person.ChangeLastName(5, "Last");
		AssertEqual(person.GetFullName(1), "Incognito", "set '2 FirstName = First', '5 LastName = Last', call 1 != 'Incognito'");
		AssertEqual(person.GetFullName(3), "First with unknown last name", "set '5 FirstName = First', '2 LastName = Last', call 3 != 'First with unknown last name'");
		AssertEqual(person.GetFullName(6), "First Last", "set '2 FirstName = First', '5 LastName = Last', call 6 != 'First Last'");
	}
}

int main() {
  TestRunner runner;

	runner.RunTest(TestWithoutChanges, "TestWithoutChanges");
	runner.RunTest(TestChangeFirstName, "TestChangeFirstName");
	runner.RunTest(TestChangeSecondName, "TestChangeSecondName");
	runner.RunTest(TestFullName, "TestFullName");
  return 0;
}
