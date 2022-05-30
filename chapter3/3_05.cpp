#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool is_elem(vector<int> &vec, int elem);
extern bool grow_vec(vector<int> &vec, int elem);

int main()
{
    int elem = 19;
    vector<int> vec = {1,1,2,3,5,8,13,21};
    if (is_elem(vec, elem))
    {
        cout << "Find " << elem << " in the vector.";
    }else
    {
        cout << " No " << elem << " in this vector.";
    }
    return 0;
}


bool is_elem(vector<int> &vec, int elem)
{
    int max_value = vec.empty()? 0: vec[vec.size()-1];
    if (max_value < elem)
        return grow_vec(vec, elem);
    
    if (max_value == elem)
        return true;
    
    return binary_search(vec.begin(), vec.end(), elem);
}

bool grow_vec(vector<int> &vec, int elem)
{
    int vsize = vec.size();
    int vlast = vec[vsize-1];
    while (vlast < elem)
    {
        vec.push_back(vec[vec.size()-1]+vec[vec.size()-2]);
        vlast = vec[vec.size()-1];
    }
    if (vlast == elem)
        return true;
    else
        return false;
}