#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream iofile("data.txt", ios_base::in | ios_base::app);
    if (!iofile)
    {
        cerr << "Oops! Unable to open file!" << endl;
    }else
    {
        iofile << "andy " << 10 << " " << 7 << endl;
        cout << "_____________________" << endl;
        string usr_name;
        int num_tries = 0;
        int num_rights = 0;

        // 由于ios_base::app的原因，开始读取之前，将文件重新定位到起始处
        iofile.seekg(0);
        iofile >> usr_name >> num_tries >> num_rights;
        cout << "name: " << usr_name << endl;
        cout << "tot: " << num_tries << endl;
        cout << "right: " << num_rights << endl;
    }
    return 0;
}