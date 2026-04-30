#include "task2.h"

#include <iostream>

class Wheel
{
    int radius = 0;

public:
    Wheel();
    Wheel(int r)
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
    Wheel* wheels;
    int wheelAmount;

    char* brand;
    double price;

    public:
    Car(char* carBrand, double carPrice, int baseWheelRadius, int wheelCount)
    {
        brand = carBrand;
        price = carPrice;

        wheelAmount = baseWheelRadius;
        wheels = new Wheel[wheelCount];
        for (int i = 0; i < wheelCount; i++)
            wheels[i] = Wheel(baseWheelRadius);
    }

    ~Car()
    {
        delete[] wheels;
        delete[] brand;
    }

    void print()
    {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Amount of wheels: " << wheelAmount << std::endl;
        std::cout << "Wheels:" << std::endl;
        for (int i = 0; i < wheelAmount; i++)
            std::cout << "Wheel[" << i << "] size: " << wheels[i].getRadius() << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

class Truck : public Car
{
    double cargoCapacity = 0;
    public:
    Truck(double cargoCap, char* carBrand, double carPrice, int baseWheelRadius, int wheelCount)
    : Car(carBrand, carPrice, baseWheelRadius, wheelCount)
    {
        cargoCapacity = cargoCap;
    }

    void print()
    {
        Car::print();
        std::cout << "Cargo Capacity: " << cargoCapacity << std::endl;
    }
};