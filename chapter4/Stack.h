#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Stack{
    public:
        bool push(const string&);
        bool pop(string &elem);
        bool peek(string &elem);

        bool empty();
        bool full();

        bool find(const string&);
        int count(const string&);

        int size() {return _stack.size();}
    
    private:
        vector<string> _stack;
};


bool Stack::empty()
{
    return _stack.empty();
}

bool Stack::pop(string &elem)
{
    if (empty())
    {
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::full()
{
    return (_stack.size()==_stack.max_size());
}

bool Stack::peek(string &elem)
{
    if (empty())
    {
        return false;
    }
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem)
{
    if (full())
    {
        return false;
    }
    _stack.push_back(elem);
    return true;
}

bool Stack::find(const string &elem)
{
    vector<string>::iterator begin = _stack.begin();
    vector<string>::iterator end = _stack.end();
    return ::find(begin, end, elem) == end;
}

int Stack::count(const string &elem)
{
    return ::count(_stack.begin(), _stack.end(), elem);
}