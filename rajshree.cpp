#include <iostream>
using namespace std;

// class ABC with private member variable a and public member function construtor
class ABC
{
private:
    int a;

public:
    ABC(int value) // parametrized constructor.
    {
        a = value;
        cout << "Value of a = " << value << endl;
    }
};

// class MNO with private member variable m and public member function construtor
class MNO
{
private:
    int m;

public:
    MNO(int value2)
    {
        m = value2;
        cout << "The value of m = " << value2 << endl;
    }
};

// class PQR with private member variable p and public member function construtor
class PQR
{
private:
    int p;

public:
    PQR(int value3)
    {
        p = value3;
        cout << "The value of p = " << value3 << endl;
    }
};

// class XYZ with private member variable x and public member function construtor
class XYZ
{
private:
    int x;

public:
    XYZ(int value4)
    {
        x = value4;
        cout << "The value of x = " << value4 << endl;
    }
};

int main()
{
    // Creating an object of the class XYZ and calling using constructor
    // by passing the values.
    XYZ obj_1(5);
    return 0;
}