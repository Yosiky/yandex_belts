#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <cmath>

#define PI 3.14

using namespace std;

class Figure {
public:

	virtual std::string Name(void) const = 0;
	virtual double Perimeter(void) const = 0;
	virtual double Area(void) const = 0;

};

class Triangle : public Figure {
	double a, b, c;
public:

	Triangle(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	std::string Name(void) const override { return ("TRIANGLE"); }
	double Perimeter(void) const override { return (a + b + c); }
	double Area(void) const override { 
		double semi_perimeter = Perimeter() / 2;
		double ans = sqrt(semi_perimeter * (semi_perimeter - a) * (semi_perimeter - b) * (semi_perimeter - c));

		return (ans); 
	} 

};

class Rect : public Figure {
	double a, b;
public:

	Rect(int a, int b) {
		this->a = a;
		this->b = b;
	}

	std::string Name(void) const override { return ("RECT"); }
	double Perimeter(void) const override { return ((a + b) * 2); }
	double Area(void) const override { return (a * b); }

};

class Circle : public Figure { 
	double r;
public:

	Circle(int r) {
		this->r = r;
	}

	std::string Name(void) const override { return ("CIRCLE"); }
	double Perimeter(void) const override { return (2 * r * PI); }
	double Area(void) const override { return (r * r * PI); }
};

std::shared_ptr<Figure> CreateFigure(std::istringstream &is) {
	std::string figure_name;
	std::shared_ptr<Figure> sh_ptr;

	is >> figure_name;
	if (figure_name == "TRIANGLE") {
		int a, b, c;

		is >> a >> b >> c;
		sh_ptr = std::make_shared<Triangle>(a, b, c);
	}
	else if (figure_name == "RECT") {
		int a, b;
		
		is >> a >> b;
		sh_ptr = std::make_shared<Rect>(a, b);
	}
	else if (figure_name == "CIRCLE") {
		int r;

		is >> r;
		sh_ptr = std::make_shared<Circle>(r);
	}
	return (sh_ptr);
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					 << current_figure->Name() << " "
					 << current_figure->Perimeter() << " "
					 << current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
