#include <iostream>
#include <cstdlib>
using namespace std;

bool fibon_elem(int pos, int & elem);
bool print_fibon(int pos);

int main()
{
    int pos;
    int elem;
    cout << "Please enter your position: " << endl;
    while (cin >> pos)
    {
        if (fibon_elem(pos, elem))
        {
            cout << "element # " << pos << ": " << elem << endl;
            print_fibon(pos);
        }else
        {
            cout << "Sorry, could not calculate element # " << pos << endl;
        }
        cout << "Please enter another position: " << endl;
    }

    return 0;
}


bool fibon_elem(int pos, int &elem)
{
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }
    elem = 1;
    int n1 = 1;
    int n2 = 1;
    for (int index = 3; index <= pos; index++)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}


bool print_fibon(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "Invalid position: " << pos << "--cannot handle request!" << endl;
        return false;
    }
    cout << "The Fibonacci Sequence for " << pos << " position:\n";
    switch (pos)
    {
        default:
        case 1:
            cout << "1 ";
        case 2:
            cout << "1 ";
            break;
    }
    int elem;
    int n1 = 1;
    int n2 = 1;
    for (int index = 3; index <= pos; index++)
    {
        elem = n1 + n2;
        n1 = n2;
        cout << elem << (!(index % 10)?"\n": " ");
        n2 = elem;
    }
    cout << endl;
    return true;
}