#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename iterator_type, typename elem_type>
iterator_type find(iterator_type first, iterator_type last, const elem_type &value);

int main()
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *pia = find(ia, ia+asize, 3);
    if (pia != ia+asize)
    {
        cout << "Found the element " << *pia << endl;
    }

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 5);
    if (it != ivec.end())
    {
        cout << "Found the element " << *it << endl;
    }

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 8);
    if (iter != ilist.end())
    {
         cout << "Found the element " << *iter << endl;
    }
    
    return 0;
}

template <typename iterator_type, typename elem_type>
iterator_type find(iterator_type first, iterator_type last, const elem_type &value)
{
    for ( ; first != last; first++)
    {
        if (*first == value)
        {
            return first;
        }
    }
    return last;    
}