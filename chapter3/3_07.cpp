#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// vector<int> filter(const vector<int> &vec, int val, less<int> &lt);

template <typename InputIterator, typename OutputIterator,
            typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at,
                        const ElemType &val, Comp pred);

int main(void)
{
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    vector<int> ivec2(elem_size);

    cout << "filtering integer array for values greater than 8:\n";
    filter(ia, ia+elem_size, ia2, 8, greater<int>());

    cout << "filtering integer vector for values less than 8:\n";
    filter(ivec.begin(), ivec.end(), ivec2.begin(), 8, less<int>());
    return 0;
}

// vector<int> filter(const vector<int> &vec, int val, less<int> &lt)
// {
//     vector<int> nvec;
//     vector<int>::const_iterator iter = vec.begin();

//     while ((iter=find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end())
//     {
//         nvec.push_back(*iter);
//         iter++;
//     }
//     return nvec;
// }

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