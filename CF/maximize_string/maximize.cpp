#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef std::vector<std::pair<char, std::vector<list<char>::iterator>>> histogram;
// typedef std::map<char, std::vector<int>> histogram;

string solve(const list<char> &str)
{
    histogram hstr = getHistogram(str);
    if (!hstr.size())
    {
        return str;
    }
    int index = 0;
    auto element = hstr.front();
    while (element.second.size() < 2)
        element = hstr[++index];

    string answer = "";
    int changeIndex = -1;
    for (auto saved : element.second)
    {
    }
    for (int i = numProcessed + 1; i < hstr.size(); i++)
    {
        auto &elem = hstr[i];
        for (auto &pos : elem.second)
        {
            if (pos > changeIndex)
                pos--;
        }
    }
    return solve(answer, hstr, ++numProcessed);
}

histogram getHistogram(list<char> str)
{
    histogram hstr;
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        auto c = *iter;
        auto it = std::find_if(hstr.begin(), hstr.end(), [c](auto elem) { return elem.first == c; });
        if (iter == hstr.end())
        {
            hstr.push_back(std::pair<char, vector<int>>(c, {i}));
        }
        else
        {
            it->second.push_back(i);
        }
    }
    return hstr;
}

int main()
{
    int nt;
    cin >> nt;
    for (int i = 1; i <= nt; ++i)
    {
        std::string data;
        cin >> data;
        histogram ret = getHistogram(data);
        auto result = solve(data, ret);
        cout << result << endl;
    }
    return 0;
}