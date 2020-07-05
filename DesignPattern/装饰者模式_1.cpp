#include <iostream>
using namespace std;


class Car {
public:
    virtual void show() = 0;
};

class RunCar : public Car {
public:
    virtual void show() {
        cout << "可以跑" << endl;
    }
};

class SwimCarDirector : public Car {
public:
    SwimCarDirector(Car *car) {
        m_car = car;
    }
    void swim() {
        cout << "可以游" << endl;
    }
    virtual void show() {
        m_car->show();
        swim();
    }
private:
    Car *m_car;
};

class FlyCarDirector : public Car {
public:
    FlyCarDirector(Car *car) {
        m_car = car;
    }
    void fly() {
        cout << "可以飞" << endl;
    }
    virtual void show() {
        m_car->show();
        fly();
    }
private:
    Car *m_car;
};


int main() {

    Car *mycar = NULL;

    mycar = new RunCar;
    printf("-----\n");
    mycar->show();
    printf("-----\n");
    
    FlyCarDirector *flycar = new FlyCarDirector(mycar);
    flycar->show();
    printf("-----\n");
    
    SwimCarDirector *swimcar = new SwimCarDirector(flycar);
    swimcar->show();
    
    delete swimcar;
    delete flycar;
    delete mycar;
    
    system("pause");
    return 0;
}