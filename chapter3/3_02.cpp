#include <iostream>
#include <vector>
using namespace std;

template <typename elem_type>
elem_type* find(vector<elem_type> &vec, elem_type value);

int main()
{
    vector<int> vec = {1, 3, 5, 7, 9};
    int elem;
    cout << "Please enter the element you want to find: " << endl;
    cin >> elem;
    int * res = find(vec, elem);
    if (res)
    {
        cout << "Good, found the elem " << *res << "." << endl;
    }else
    {
        cout << "Oops, couldn't find the elem " << elem << "." << endl;
    }
    return 0;
}

template <typename elem_type>
elem_type * find(vector<elem_type> &vec, elem_type value)
{
    for (int index = 0; index < vec.size(); index++)
    {
        if (vec[index]==value)
        {
            return &vec[index];
        }        
    }
    return 0;
}