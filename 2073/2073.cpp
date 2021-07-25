#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

string comp_name, comp_date, str;

vector <string> vname;
vector <string> vdate;
vector <string> res;

void in()
{
    //ifstream cin("2073.in");
    cin >> n;
    getline(cin, comp_name);
    for (int i = 0; i < n; i++)
    {
        str.clear();
        int cnt, pos;
        /*getline(cin, comp_name);
        cout <<"COMP_NAME: " << comp_name << "\n";*/
        getline(cin, comp_name);
        while(comp_name.size() < 30)
        {
            comp_name+=' ';
        }
        cin >> comp_date;
        //cout <<"COMP_NAME: " << comp_name << "\nCOMP_DATE: " << comp_date << "\n";
        vname.push_back(comp_name);
        vdate.push_back(comp_date);
        cin >> cnt >> pos;
        //out << cnt << " " << pos << "\n";
        for (int j = 0; j < 13; j++)
        {
            if (j < cnt) str+='.';
            else         str+=' ';
        }
        for (int j = 0; j < pos; j++)
        {
            char let;
            string ver;
            cin >> let;
            getline(cin, ver);
            //cout << "LET_VER: " << let << " " <<ver << "\n";
            if (ver == " Accepted") {/*cout <<(int)let-(int)'A'<< "\n"; */str[(int)let-(int)'A'] = 'o';}
            else
            {
                if (str[(int)let-(int)'A'] != 'o') str[(int)let-(int)'A'] = 'x';
            }
        }
        if (pos == 0) getline(cin, comp_name);
        //cout <<"STR: " << str << "\n";
        res.push_back(str);
    }
}

void out()
{
    //ofstream cout("2073.out");
    cout << "+------------------------------+--------+-------------+\n|Contest name                  |Date    |ABCDEFGHIJKLM|\n+------------------------------+--------+-------------+\n";
    for (int i = 0; i < vname.size(); i++)
    {
        cout << "|" << vname[i] << "|" << vdate[i] << "|" << res[i] << "|\n";
        cout << "+------------------------------+--------+-------------+\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
