#include <iostream>

class Beverage {
protected:
	char description[255];
public:
	Beverage();
	virtual char* getDescription();
	virtual double cost();
};

class CodimentDecorator : public Beverage {

};

class DarkRoast : public Beverage {
public:
	DarkRoast();
	double cost();
};

class Decaf : public Beverage {
public:
	Decaf();
	double cost();
};

class Espresso : public Beverage {
public:
	Espresso();
	double cost();
};

class HouseBlend :public Beverage {
public:
	HouseBlend();
	double cost();
};

class Milk :public CodimentDecorator {
private:
	Beverage* beverage;
public:
	Milk(Beverage* beverage);
	char* getDescription();
	double cost();
};

class Mocha : public CodimentDecorator {
private:
	Beverage* beverage;
public:
	Mocha(Beverage* beverage);
	char* getDescription();
	double cost();
};

class Soy : public CodimentDecorator {
private:
	Beverage* beverage;
public:
	Soy(Beverage* beverage);
	char* getDescription();
	double cost();
};

class Whip :public CodimentDecorator {
private:
	Beverage* beverage;
public:
	Whip(Beverage* beverage);
	char* getDescription();
	double cost();
};

Beverage::Beverage() {
	memset(description, 0, 225);
	strcpy(description, "제목 없음");
}

char* Beverage::getDescription() {
	return description;
}

double Beverage::cost() {
	return 0.0;
}

DarkRoast::DarkRoast() {
	strcpy(description, "Dark Roast Coffee");
}

double DarkRoast::cost() {
	return .99;
}

Decaf::Decaf() {
	strcpy(description, "Decaf Coffee");
}

double Decaf::cost() {
	return 1.05;
}

Espresso::Espresso() {
	strcpy(description, "Espresso");
}

double Espresso::cost() {
	return 1.99;
}

HouseBlend::HouseBlend() {
	strcpy(description, "House Blend Coffee");
}

double HouseBlend::cost() {
	return .89;
}

Milk::Milk(Beverage* beverage) {
	this->beverage = beverage;
	strcpy(description, this->beverage->getDescription());
}

char* Milk::getDescription() {
	return strcat(description, ", Milk");
}

double Milk::cost() {
	return .10 + beverage->cost();
}

Mocha::Mocha(Beverage* beverage) {
	this->beverage = beverage;
	strcpy(description, this->beverage->getDescription());
}

char* Mocha::getDescription() {
	return strcat(description, ", Mocha");
}

double Mocha::cost() {
	return .20 + beverage->cost();
}

Soy::Soy(Beverage* beverage) {
	this->beverage = beverage;
	strcpy(description, this->beverage->getDescription());
}

char* Soy::getDescription() {
	return strcat(description, ", Soy");
}

double Soy::cost() {
	return .15 + beverage->cost();
}

Whip::Whip(Beverage* beverage) {
	this->beverage = beverage;
	strcpy(description, this->beverage->getDescription());
}

char* Whip::getDescription() {
	return strcat(description, ", Whip");
}

double Whip::cost() {
	return .10 + beverage->cost();
}

void display(Beverage* beverage) {
	printf("%s : $%.2f\n", beverage->getDescription(), beverage->cost());
}

void main() {
	Beverage* beverage1 = new Espresso();
	display(beverage1);

	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	display(beverage2);

	Beverage* beverage3 = new HouseBlend();
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	display(beverage3);

}