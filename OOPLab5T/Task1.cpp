#include "Task1.h"

#include <iostream>

class Pair
{
public:
    int first;
    int second;

    Pair(int val1, int val2)
    {
        first = val1;
        second = val2;
    }

    void setFirst(int val)
    {
        first = val;
    }

    void setSecond(int val)
    {
        second = val;
    }

    bool isGreaterThan(const Pair &other) const
    {
       return (first > other.first) || (first == other.first && second > other.second);
    }
};

class Fraction : public Pair
{
    public:
    Fraction(int whole, int fraction) : Pair(whole, fraction){}

    bool operator>(const Fraction &other) const
    {
        return isGreaterThan(other);
    }

    bool operator<(const Fraction &other) const
    {
        return other.isGreaterThan(*this);
    }

    bool operator>=(const Fraction &other) const
    {
        return isGreaterThan(other) || !other.isGreaterThan(*this);
    }

    bool operator<=(const Fraction &other) const
    {
        return other.isGreaterThan(*this) || !isGreaterThan(other);
    }

    bool operator==(const Fraction &other) const
    {
        return !isGreaterThan(other) || !other.isGreaterThan(*this);
    }

    void print()
    {
        std::cout << first << "." << second << std::endl;
    }
};

void task1()
{
    Fraction f1 = Fraction(1, 0);
    Fraction f2 = Fraction(1, 5);

    f1.print();
    f2.print();

    std::cout << "f1 > f2: " << (f1 > f2) << std::endl;
    std::cout << "f2 > f1: " << (f2 > f1) << std::endl;
    std::cout << "f2 >= f1: " << (f2 >= f1) << std::endl;
    std::cout << "f1 >= f2: " << (f1 >= f2) << std::endl;

    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;

    std::cout << "f1 < f2: " << (f1 < f2) << std::endl;
    std::cout << "f2 < f1: " << (f2 < f1) << std::endl;
    std::cout << "f1 <= f2: " << (f1 <= f2) << std::endl;
    std::cout << "f2 <= f1: " << (f2 <= f1) << std::endl;
}