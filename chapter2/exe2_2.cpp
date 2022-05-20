#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b);
float max(float a, float b);
string max(string a, string b);
int max(vector<int> &vec);
float max(vector<float> &vec);
string max(vector<string> &vec);
int max(int arr[], int size);
float max(float arr[], int size);
string max(string arr[], int size);

int main()
{
    int int_a = 5, int_b = 3;
    int int_maximal = max(int_a, int_b);
    cout << "The maximal of a: " << int_a << " and b: " << int_b << " is: " << int_maximal << endl;
    float float_a = 2.4, float_b = 3.8;
    float float_maximal = max(float_a, float_b);
    cout << "The maximal of a: " << float_a << " and b: " << float_b << " is: " << float_maximal << endl;
    string str_a = "abd", str_b = "udi";
    string str_maximal = max(str_a, str_b);
    cout << "The maximal of a: " << str_a << " and b: " << str_b << " is: " << str_maximal << endl;
    vector<int> int_vec = {6, 2, 3, 4};
    int vec_max = max(int_vec);
    cout << "The maximal element in the vector is: " << vec_max << endl;
    vector<float> float_vec = {2.1, 3.2, 1.9, 3.8};
    float vec_max_2 = max(float_vec);
    cout << "The maximal element in the vector is: " << vec_max_2 << endl;
    vector<string> string_vec = {"abd", "uif", "bdi"};
    string vec_max_3 = max(string_vec);
    cout << "The maximal element in the vector is: " << vec_max_3 << endl;
    int a1[] = {1, 2, 3, 4};
    int max1 = max(a1, 4);
    cout << "The maximal element in the array is: " << max1 << endl;
    float a2[] = {1.3, 4.3, 5.2, 5.9};
    float max2 = max(a2, 4);
    cout << "The maximal element in the array is: " << max2 << endl;
    string a3[] = {"hfsj", "sjja", "dsbsj"};
    string max3 = max(a3, 3);
    cout << "The maximal element in the array is: " << max3 << endl;
    return 0;
}


int max(int a, int b)
{
    return (a >= b ? a: b);    
}

float max(float a, float b)
{
    return (a >= b ? a: b);
}

string max(string a, string b)
{
    return (a >= b ? a: b);
}

int max(vector<int> &vec)
{
    int maximal = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > maximal)
        {
            maximal = vec[i];
        }
    }
    return maximal;
}

float max(vector<float> &vec)
{
    float maximal = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > maximal)
        {
            maximal = vec[i];
        }
    }
    return maximal;
}

string max(vector<string> &vec)
{
    string maximal = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > maximal)
        {
            maximal = vec[i];
        }
    }
    return maximal;
}

int max(int arr[], int size)
{
    int maximal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximal)
        {
            maximal = arr[i];
        }
    }
    return maximal;
}

float max(float arr[], int size)
{
    float maximal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximal)
        {
            maximal = arr[i];
        }
    }
    return maximal;
}

string max(string arr[], int size)
{
    string maximal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximal)
        {
            maximal = arr[i];
        }
    }
    return maximal;
}