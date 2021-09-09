#include <iostream>
#include <map>
#include <utility>

using namespace std;
map<string, int> m;

int main()
{
    int n;
    string name;
    string in;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> in;
        if (m.find(name) == m.end())
        {
            m.insert(make_pair(name, in.compare("enter") ? 1 : 0));
        }
        else
        {
            m.erase(name);
        }
    }
    for (auto iter = --m.end(); iter != m.begin(); iter--)
    {
        cout << iter->first <<"\n";
    }
    cout << m.begin()->first << "\n";
}

// A
//     a
//         B
//             b

//                 A B a b
    //아스키 코드 기준!!