#include <iostream>
#define TALL 0
#define GRANDE 1
#define VENTI 2

class Beverage {
protected:
    char description[255];
    int size;
public:
    Beverage();
    virtual char* getDescription();
    virtual double cost();
    virtual int getSize();
};

class CodimentDecorator : public Beverage {

};

class DarkRoast : public Beverage {
private:
    Beverage* beverage;
public:
    DarkRoast(int size);
    double cost();
    void setSize(int size);
    int getSize();
};

class Decaf : public Beverage {
private:
    int size;
    Beverage* beverage;
public:
    Decaf(int size);
    double cost();
    void setSize(int size);
    int getSize();
};

class Espresso : public Beverage {
private:
    int size;
    Beverage* beverage;
public:
    Espresso(int size);
    double cost();
    void setSize(int size);
    int getSize();
};

class HouseBlend :public Beverage {
private:
    int size;
    Beverage* beverage;
public:
    HouseBlend(int size);
    double cost();
    void setSize(int size);
    int getSize();
};

class Milk :public CodimentDecorator {
private:
    Beverage* beverage;
public:
    Milk(Beverage* beverage);
    char* getDescription();
    double cost();
    int getSize();
};

class Mocha : public CodimentDecorator {
private:
    Beverage* beverage;
public:
    Mocha(Beverage* beverage);
    char* getDescription();
    double cost();
    int getSize();
};

class Soy : public CodimentDecorator {
private:
    Beverage* beverage;
public:
    Soy(Beverage* beverage);
    char* getDescription();
    double cost();
    int getSize();
};

class Whip :public CodimentDecorator {
private:
    Beverage* beverage;
public:
    Whip(Beverage* beverage);
    char* getDescription();
    double cost();
    int getSize();
};

Beverage::Beverage() {
    memset(description, 0, 225); //0으로 초기화
    strcpy(description, "제목 없음");
}

char* Beverage::getDescription() {
    return description;
}

double Beverage::cost() {
    return 0.0;
}

int Beverage::getSize() {
    return 0;
}

DarkRoast::DarkRoast(int size) {
    setSize(size);
    strcpy(description, "Dark Roast Coffee");
}

double DarkRoast::cost() {
    if (getSize() == TALL)
        return .99;
    else if (getSize() == GRANDE)
        return 1.49;
    else if (getSize() == VENTI)
        return 1.99;
}

void DarkRoast::setSize(int size) {
    this->size = size;
}

int DarkRoast::getSize() {
    return size;
}

Decaf::Decaf(int size) {
    setSize(size);
    strcpy(description, "Decaf Coffee");
}

double Decaf::cost() {
    if (getSize() == TALL)
        return 1.05;
    else if (getSize() == GRANDE)
        return 1.55;
    else if (getSize() == VENTI)
        return 2.05;
}

void Decaf::setSize(int size) {
    this->size = size;
}

int Decaf::getSize() {
    return size;
}

Espresso::Espresso(int size) {
    setSize(size);
    strcpy(description, "Espresso");
}

double Espresso::cost() {
    if (getSize() == TALL)
        return 1.99;
    else if (getSize() == GRANDE)
        return 2.49;
    else if (getSize() == VENTI)
        return 2.99;
}

void Espresso::setSize(int size) {
    this->size = size;
}

int Espresso::getSize() {
    return size;
}

HouseBlend::HouseBlend(int size) {
    setSize(size);
    strcpy(description, "House Blend Coffee");
}

double HouseBlend::cost() {
    if (getSize() == TALL)
        return .89;
    else if (getSize() == GRANDE)
        return 1.39;
    else if (getSize() == VENTI)
        return 1.89;
}

void HouseBlend::setSize(int size) {
    this->size = size;
}

int HouseBlend::getSize() {
    return size;
}


Milk::Milk(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}

char* Milk::getDescription() {
    return strcat(description, ", Milk");
}

double Milk::cost() {
    if (getSize() == TALL)
        return beverage->cost() + 0.20;
    else if (getSize() == GRANDE)
        return beverage->cost() + 0.25;
    else if (getSize() == VENTI)
        return beverage->cost() + 0.30;
}

int Milk::getSize() {
    return this->beverage->getSize();
}

Mocha::Mocha(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}

char* Mocha::getDescription() {
    return strcat(description, ", Mocha");
}

double Mocha::cost() {
    if (getSize() == TALL)
        return beverage->cost() + 0.10;
    else if (getSize() == GRANDE)
        return beverage->cost() + 0.15;
    else if (getSize() == VENTI)
        return beverage->cost() + 0.20;
}

int Mocha::getSize() {
    return this->beverage->getSize();
}

Soy::Soy(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}

char* Soy::getDescription() {
    return strcat(description, ", Soy");
}

double Soy::cost() {
    if (getSize() == TALL)
        return beverage->cost() + 0.12;
    else if (getSize() == GRANDE)
        return beverage->cost() + 0.18;
    else if (getSize() == VENTI)
        return beverage->cost() + 0.24;
}

int Soy::getSize() {
    return this->beverage->getSize();
}

Whip::Whip(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}

char* Whip::getDescription() {
    return strcat(description, ", Whip");
}

double Whip::cost() {
    if (getSize() == TALL)
        return beverage->cost() + 0.11;
    else if (getSize() == GRANDE)
        return beverage->cost() + 0.13;
    else if (getSize() == VENTI)
        return beverage->cost() + 0.15;
}

int Whip::getSize() {
    return this->beverage->getSize();
}

void display(Beverage* beverage) {
    printf("%s : $%.2f, <SIZE : %d(Tall : 0, Grande : 1, Venti : 2)>\n", beverage->getDescription(), beverage->cost(), beverage->getSize());
}

void main() {
    //에스프레소
    Beverage* beverage1 = new Espresso(GRANDE);
    display(beverage1);

    //다크로스트 커피 + 모카 + 모카 + 휘핑크림
    Beverage* beverage2 = new DarkRoast(TALL);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    display(beverage2);

    //하우스 블렌드 커피 + 두유 + 모카 + 휘핑크림
    Beverage* beverage3 = new HouseBlend(VENTI);
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    display(beverage3);

    Beverage* bever4 = new DarkRoast(TALL);
    bever4 = new Milk(bever4);
    bever4 = new Mocha(bever4);
    bever4 = new Milk(bever4);
    display(bever4);

    Beverage* bever5 = new Espresso(GRANDE);
    bever5 = new Milk(bever5);
    bever5 = new Milk(bever5);
    bever5 = new Milk(bever5);
    display(bever5);

    Beverage* bever6 = new HouseBlend(VENTI);
    bever6 = new Milk(bever6);
    bever6 = new Mocha(bever6);
    bever6 = new Soy(bever6);
    bever6 = new Whip(bever6);
    display(bever6);
}