#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

class even_elem
{
    public:
    bool operator()(int elem)
        {return elem%2?true:false;}
};

int main()
{
    ofstream outfile_odd("outfile_odd.txt");
    ofstream outfile_even("outfile_even.txt");
    if (! outfile_odd || ! outfile_even)
    {
        cerr << "!! unable to open the necessary files.";
        return -1;
    }

    istream_iterator<int> is(cin);
    istream_iterator<int> eof;

    vector<int> nums;
    copy(is, eof, back_inserter(nums));

    vector<int>::iterator division = partition(nums.begin(), nums.end(), even_elem());

    ostream_iterator<int> os_odd(outfile_odd, " ");
    ostream_iterator<int> os_even(outfile_even, " ");
    copy(nums.begin(), division, os_odd);
    copy(division, nums.end(), os_even);
    
    return 0;
}