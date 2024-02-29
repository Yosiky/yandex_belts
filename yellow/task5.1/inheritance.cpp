#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код
	Animal(const string &s) : Name(s) { }

    const string Name;
};


class Dog: public Animal {
public:
	Dog(const string &s) : Animal(s) { }
    // ваш код

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
