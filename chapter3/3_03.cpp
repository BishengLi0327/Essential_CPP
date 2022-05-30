#include <iostream>
#include <vector>
using namespace std;

template <typename elem_type>
inline elem_type * begin(vector<elem_type> &vec)
{
    return vec.empty() ? 0: &vec[0];
}

template <typename elem_type>
inline elem_type * end(vector<elem_type> &vec)
{
    return vec.empty() ? 0: &vec[vec.size()];
}

template <typename elem_type>
elem_type * find(elem_type *first, elem_type *last, elem_type value);

int main()
{   
    int arr[5] = {1,3,5,7,9};
    vector<int> vec = {1, 3, 5, 7, 9, 11};
    int elem;
    cout << "Please enter the element you want to find in the array or in the vector: " << endl;
    cin >> elem;
    int * res_arr = find(arr, arr+5, elem);
    int * res_vec = find(begin(vec), end(vec), elem);
    if (res_arr)
        cout << "Good, found the elem " << *res_arr << " in the array." << endl;
    else
        cout << "Oops, couldn't find the elem " << elem << "." << endl;
    if (res_vec)
        cout << "Good, found the elem " << *res_vec << " in the vector." << endl;
    else
        cout << "Oops, couldn't find the elem " << elem << "." << endl;
    return 0;
}

// template <typename elem_type>
// elem_type * find(elem_type * array, int size, elem_type value)
// {
//     if (! array || size < 1)
//         return 0;
//     for (int index = 0; index < size; index++)
//     {
//         if (array[index]==value)
//         {
//             return &array[index];
//         }
//     }
//     return 0;
// }

template <typename elem_type>
elem_type * find(elem_type *first, elem_type *last, elem_type value)
{
    if (! first || ! last)
        return 0;
    for ( ; first != last; first++)
    {
        if (*first == value)
        {
            return first;
        }
    }
    return 0;
}