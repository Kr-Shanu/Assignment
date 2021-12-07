// Implementing semaphore in bounded buffer problem:

#include <iostream>
#include <vector>
using namespace std;


class boundBuffer
{
public:
    int full, empty;
    vector<int> buffer;
    boundBuffer(int size_of_buffer)
    {
        empty = size_of_buffer;
        full = 0;
    }

    void producer();
    void consumer();
};

void boundBuffer ::producer()
{
    cout << "Checking the value of empty" << endl;
    cout<<endl;
    if (empty > 0)
    {
        cout << "Empty is greater than 0, that means the buffer has space." << endl;
        cout<<""<<endl;
        cout << "You can proceed to fill in the buffer 😇" << endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout << "*********************Acquiring 🔐lock using wait function*********" << endl;
        cout<<""<<endl;
        cout << "Now consuer cannot enter and the producer is free to add values" << endl;
        cout<<""<<endl;
        int value;
        cout << "Enter the value here : ";
        cin >> value;
        buffer.push_back(value);
        empty--;
    }
    else
        cout << "Buffer is not empty, you cannot add aything 😔" << endl;
    
    cout<<" 🔐 Lock is being released again for others to access!"<<endl;
    full++;
}

void boundBuffer ::consumer()
{
    cout << "Checking the value of full" << endl;
    cout<<""<<endl;
    if (full > 0)
    {
        cout << "Full is greater than 0, that means the buffer is not empty." << endl;
        cout<<""<<endl;
        cout << "You can proceed to acquire data from the buffer 😇" << endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout << "*********************Acquiring 🔐lock using wait function*********" << endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout << "Now producer cannot enter and the consumer is free to take values" << endl;
        cout<<""<<endl;

        buffer.pop_back();
        full--;
    }
    else
        cout << "Buffer is  empty, you cannot take aything 😔" << endl;
    
    cout<<" 🔐 Lock is being released again for others to access!"<<endl;
    empty++;
}

int main()
{
    int n;
    cout<<"Enter the size of your buffer :"<<endl;;
    cin>>n;

    boundBuffer b(n);

    int cases;

    for (;;) // infinite loop
    {
        cout<<"Enter 1 if you are a producer:"<<endl;
        cout<<"Enter 2 if you are a consumer:"<<endl;
        cout<<"Enter 3 if you want to exit :"<<endl;
        cin>>cases;
        switch (cases)
        {
        case 1:
            b.producer();
            break;
        case 2:
            b.consumer();
            break;
        case 3:
            exit(1);
        default:
            cout<<"Invalid input:"<<endl;
            break;
        }
    }
    return 0;
}
