#include "Task2.h"

#include <iostream>

class Wheel
{
    int radius;

public:
    Wheel(int r = 0)
    {
        radius = r;
    }

    int getRadius()
    {
        return radius;
    }
};

class Car
{
protected:
    Wheel wheels[4] = {};

    char* brand = {};
    double price = 0;

    public:
    Car(char* carBrand, double carPrice, int baseWheelRadius)
    {
        brand = carBrand;
        price = carPrice;

        for (int i = 0; i < 4; i++)
            wheels[i] = baseWheelRadius;
    }

    ~Car()
    {
        delete[] brand;
    }

    void print()
    {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Wheels:" << std::endl;
        for (int i = 0; i < 4; i++)
            std::cout << "Wheel " << i << " radius " << wheels[i].getRadius() << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

class Truck : public Car
{
    double cargoCapacity = 0;
    public:
    Truck(double cargoCap, char* carBrand, double carPrice, int baseWheelRadius)
    : Car(carBrand, carPrice, baseWheelRadius)
    {
        cargoCapacity = cargoCap;
    }

    void print()
    {
        Car::print();
        std::cout << "Cargo Capacity: " << cargoCapacity << std::endl;
    }
};

void task2()
{
    char brand[] = "BMW";
    Car c1 = Car(brand, 150000, 1);
    c1.print();

    char truckBrand[] = "MAN";
    Truck truck = Truck(10000, truckBrand, 5000000, 3);
    truck.print();
}