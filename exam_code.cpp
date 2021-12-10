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
class MNO :virtual public ABC
{
private:
    int m;

public:
    MNO(int value1,int value2):ABC(value1)
    {
        m = value2;
        cout << "The value of m = " << value2 << endl;
    }
};

// class PQR with private member variable p and public member function construtor
class PQR :virtual public ABC
{
private:
    int p;

public:
    PQR(int value1,int value3):ABC(value1)
    {
        p = value3;
        cout << "The value of p = " << value3 << endl;
    }
};

// class XYZ with private member variable x and public member function construtor
class XYZ: public MNO, public PQR
{
private:
    int x;

public:
    XYZ(int value1,int value2,int value3,int value4):ABC(value1),MNO(value1,value2),PQR(value1,value3)
    {
        x = value4;
        cout << "The value of x = " << value4 << endl;
    }
};


int main()
{
    // Creating an object of the class XYZ and calling using constructor
    // by passing the values.
    XYZ obj_1(1,2,3,4);
    return 0;
}
