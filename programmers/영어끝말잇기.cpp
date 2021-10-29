#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
set <string> m;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int index = 0;
    int idx = 0;
    for (int i = 0; i < words.size(); i++)
    {
        idx = index % n;
        if (m.find(words[i]) == m.end())
        {
            // index++;
            if (words[i].length() < 2 || words[i].length() > 50)
            {
                // index++;
                break;
            }
            if (i != 0 && words[i-1][words[i-1].length()-1] != words[i][0])
            {
                // index++;
                break;
            }
            m.insert(words[i]);
            index++;
        }
        else
            break;
    }
    if (index == words.size())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    int temp = 0;
    temp = index / n;
    answer.push_back(idx + 1);
    answer.push_back(temp + 1);
    return answer;
}