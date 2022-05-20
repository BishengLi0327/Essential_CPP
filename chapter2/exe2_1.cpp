#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool is_size_ok(int pos);
void display(const vector<int> &vec, ostream &os=cout);
const vector<int> *pentagonal_seq(int pos);

int main()
{
    int pos;
    int elem;
    cout << "Please enter a postion: \n";
    cin >> pos;

    const vector<int> *pseq = pentagonal_seq(pos);
    if (! pseq)
    {
        cout << "Oops, could not calculate element # " << pos << endl;
    }else
    {
        elem = (*pseq)[pos-1];
        cout << "the pentagonal elem on pos " << pos << " is: \n";
        cout << elem << endl;
        display(*pseq);
    }
    return 0;
}

bool is_size_ok(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        return false;
    }
    return true;
}

void display(const vector<int> &vec, ostream &os)
{
    os << "The elements in Pentagonal Sequence are: \n";
    for (int index = 0; index < vec.size(); index++)
    {
        os << vec[index] << " ";
    }
    os << endl;
}

const vector<int> *pentagonal_seq(int pos)
{
    static vector<int> elems;
    if (! is_size_ok(pos))
    {
        return 0;
    }
    for (int index = elems.size(); index < pos; index++)
    {
        int elem;
        elem = (index+1) * (3*(index+1)-1) / 2;
        elems.push_back(elem);
    }
    return &elems;
}
