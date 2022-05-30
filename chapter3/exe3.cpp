#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

typedef vector<string> vstring;
map<string,vstring> families;

void populate_map( ifstream &, map<string,vstring> & );
void display_map( const map<string,vstring> &, ostream & );
void query_map( const string &, const map<string,vstring> & );

int main()
{
    map<string,vstring> families;
    ifstream nameFile( "C:\\My Documents\\families.txt" );

    if ( !nameFile ){
        cerr << "Unable to find families.txt file. Bailing Out!\n";
        return -1;   // 英文原书未返回任何值，错误
    }
    populate_map( nameFile, families );

    string family_name;
    while ( 1 )
    {
        // 除非用户表示要离开，否则一直执行下去
        cout << "Please enter a family name or q to quit ";
        cin >> family_name;

        if ( family_name == "q" )
            break;
        query_map( family_name, families );
    }
    display_map( families, cout );     // 英文原书只有一个参数，错误
}

void populate_map( ifstream &nameFile, map<string,vstring> &families )
{
    string textline;
    while ( getline( nameFile, textline ) )
    // 此行无法通过Visual C++和Borland C++ Builder，只有GCC可接受
    {
        string fam_name;
        vector<string> child;
        string::size_type
            pos = 0, prev_pos = 0,
            text_size = textline.size();
        
        // ok：找出以空格为分隔开来的所有单字
        while ( ( pos = textline.find_first_of( ' ', pos ) ) != string::npos ){
            // 计算子字符串的终点
            string::size_type end_pos = pos - prev_pos;

            // 倘若prev_pos并未设置（或说其值为0），那么读到的单字就是
            // 家庭姓氏，否则我们就一一读取孩子们的名字......
            if ( !prev_pos )
                fam_name = textline.substr( prev_pos, end_pos );
            else
                child.push_back( textline.substr( prev_pos, end_pos ) );
            prev_pos = ++pos;
        }
        
        // 现在处理最后一个孩子的名字
        if ( prev_pos < text_size )
            child.push_back( textline.substr( prev_pos, pos-prev_pos ) );

        if ( !families.count( fam_name ) )
            families[ fam_name ] = child;
        else
            cerr << "Oops! We already have a " << fam_name 
                 << " family in our map!\n";
    }
}

void display_map( const map<string,vstring> &families, ostream &os )
{
    map<string,vstring>::const_iterator
                 it = families.begin(),
                 end_it = families.end();
    
    while ( it != end_it ){
        os << "The " << it->first << " family ";
        if ( it->second.empty() ){
            os << "has no children\n";
        }
        else{
            // 打印出vector内的小孩名字
            os << "has " << it->second.size() << " children: ";
            vector<string>::const_iterator iter = it->second.begin(),
                                           end_iter = it->second.end();
            while ( iter != end_iter ){
                os << *iter << " ";
                ++iter;
            }
            os << endl;
        }
        ++it;
    }
}

void query_map( const string &family, 
                const map<string,vstring> &families )
{
    map<string,vstring>::const_iterator it = families.find( family );

    if ( it == families.end() ){
        cout << "Sorry. The " << family 
             << " it not currently entered.\n";
        return;
    }
    
    cout << "The " << family;
    if ( !it->second.size() ){
        cout << "has no children\n";
    }
    else{
        // 打印出vector内的小孩名字
        cout << "has " << it->second.size() << " children: ";
        vector<string>::const_iterator 
               iter = it->second.begin(),
               end_iter = it->second.end();
        while ( iter != end_iter ){
            cout << *iter << " ";
            ++iter;
        }
        cout << endl;
    }
}
