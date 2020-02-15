#include<iostream>
#include<string>
using namespace std;

class Driver {
private:
	string name;
	int age;
public:
	Driver() { cout << "here from Driver class default constructor\n"; }
	Driver(string _name, int _age) {
		name = _name;
		age = _age;
	}

	int get_mass() {
		return age;
	}
};

class Engine1 {
private: 
	int cylinders;
	int model;
public: 
	Engine1(int _cylinders, int _model) {
		cylinders = _cylinders;
		model = _model;
	}
	void display() {
		printf("%d %d ", cylinders, model);
	}
};


class Skoda: public Engine1 {
private: 
	string owner;
public: 
	Skoda(int _cylinders, int _model, string _owner) : Engine1(_cylinders, _model) {
		owner = _owner;
	}

	void display() {
		Engine1::display();
		cout << owner << endl;
	}
};


class Engine2 {
protected:
	int cylinders;
	int model;
};

class Mazda : public Engine2 {
private:
	string owner;
public:
	Mazda(int _cylinders, int _model, string _owner) {
		cylinders = _cylinders;
		model = _model;
		owner = _owner;
	}

	void display() {
		printf("%d %d %s\n", cylinders, model, owner.c_str());
	}
};


int main() {
	Driver d1;
	Driver d2("d2", 77);

	Skoda Skoda2020(777, 2020, "name");
	Skoda2020.display();

	Mazda mazda2020(777, 2020, "name");
	mazda2020.display();
	printf("\n");
	return 0;
}