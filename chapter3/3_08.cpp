#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;

// vector<int> filter(const vector<int> &vec, int val, less<int> &lt);

template <typename InputIterator, typename OutputIterator,
            typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at,
                        const ElemType &val, Comp pred);

int main()
{
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3 ,7};
    vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    vector<int> ivec2;

    cout << "filtering integer array for values less than 8:\n";
    filter(ia, ia+elem_size, ia2, 8, less<int>());

    cout << "filtering integer vector for values greater than 8:\n";
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), 8, greater<int>());
    return 0;
}

template <typename InputIterator, typename OutputIterator,
            typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at,
                        const ElemType &val, Comp pred)
{
    while ((first=find_if(first, last, bind2nd(pred, val)))!=last)
    {
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}