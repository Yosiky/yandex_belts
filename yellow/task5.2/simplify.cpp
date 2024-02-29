#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:

	const string Type;
	const string Name;

public:

	Person(const string &name, const string &type) : Name(name), Type(type) { }

	virtual void Walk(const string &destination) const {
        cout << getType() << ": " << getName() << " walks to: " << destination << endl;
	}

	const string &getName(void) const {
		return (Name);
	}

	const string &getType(void) const {
		return (Type);
	}
};

class Student : public Person {
public:

    Student(const string &name, const string &favouriteSong)
		: Person(name, "Student"), FavouriteSong(favouriteSong) { }

    void Learn(void) const {
        cout << getType() << ": " << getName() << " learns" << endl;
    }

    void Walk(const string &destination) const override {
		Person::Walk(destination);
		SingSong();
    }

    void SingSong(void) const {
        cout << getType() << ": " << getName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string &name, const string &subject)
		: Person(name, "Teacher"), Subject(subject) { }

    void Teach(void) const {
        cout << getType() << ": " << getName() << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:

    Policeman(const string &name) : Person(name, "Policeman") { }

	void Check(const Person &person) const {
        cout << getType() << ": " << getName() << " checks " << person.getType() << ". " << person.getType() << "'s name is: " << person.getName() << endl;
	}

};

void VisitPlaces(const Person &t, const vector<string> &places) {
    for (const auto &p : places) {
        t.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
