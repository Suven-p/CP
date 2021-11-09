#include <bits/stdc++.h>

using namespace std;

std::vector<tuple<int, int, int>> list;
int getMedian(int i1, int i2, int i3)
{
    cout << i1 << " " << i2 << " " << i3 << endl;

    int median;
    cin >> median;
    return median;
}

bool insert(vector<int> &array, int element, int startIndex, int endIndex)
{
    if (array.size() < 2)
    {
        array.push_back(element);
        return true;
    }
    auto midIndex = int((endIndex - startIndex + 1) / 2) + startIndex;
    int start = array[startIndex], end = array[endIndex], mid = array[midIndex];
    auto median = getMedian(start, element, mid);
    if (median == start)
    {
        array.insert(array.begin() + startIndex, element);
        return true;
    }
    else if (median == element)
    {
        if (endIndex == midIndex)
        {
            array.insert(array.begin() + midIndex, element);
            return true;
        }
        return insert(array, element, startIndex, midIndex);
    }
    else if (median == mid)
    {
        if (endIndex == midIndex)
        {
            {
                array.insert(array.begin() + midIndex + 1, element);
                return true;
            }
        }
        return insert(array, element, midIndex, endIndex);
    }
    else
    {
        return false;
    }
}

int main()
{
    int T, N, Q;
    cin >> T >> N >> Q;
    for (int nT = 0; nT < T; nT++)
    {
        vector<int> array;
        for (int i = 0; i < N; i++)
        {
            auto result = insert(array, i + 1, 0, array.size() - 1);
            if (!result)
            {
                break;
            }
        }

        for (auto it = array.begin(); it != array.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;

        int result;
        cin >> result;
        if (result == -1) {
            cerr << "Test " << nT + 1 << " failed." << endl;
        }
    }
    return 0;
}