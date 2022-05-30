#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


int main()
{
    const int seq_size = 6;
    int elem_seq[seq_size] = {1, 2, 3, 2, 5, 12};
    
    vector<int> fibonacci(elem_seq, elem_seq+3);
    vector<int> pell(elem_seq+3, elem_seq+6);
    vector<int> fib_plus_pell(3);

    transform(fibonacci.begin(), fibonacci.end(), pell.begin(), fib_plus_pell.begin(), plus<int>());
    for (int index = 0; index < fib_plus_pell.size(); index++)
        cout << fib_plus_pell[index] << " ";
    cout << endl;    
    return 0;
}