#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <typename elem_type>
void display_message(const string &msg, const vector<elem_type> &vec, ostream &os = cout);

int main()
{
    string msg = "The elements in the vector are: \n\t";
    int nums1[] = {1, 2, 3, 4, 5, 6};
    double nums2[] = {1.2, 3.2, 4.0, 7.8, 6.4};
    string strs[] = {"abc", "fsh", "dshd"};
    vector<int> vec1(nums1, nums1+6);
    vector<double> vec2(nums2, nums2+5);
    vector<string> vec3(strs, strs+3);
    display_message(msg, vec1);
    display_message(msg, vec2);
    display_message(msg, vec3);
    return 0;
}

template <typename elem_type>
void display_message(const string &msg, const vector<elem_type> &vec, ostream &os)
{
    os << msg;
    for (int i = 0; i < vec.size(); i++)
    {
        elem_type num = vec[i];
        os << num << " ";
    }
    os << endl;
}