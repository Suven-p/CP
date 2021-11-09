#include <bits/stdc++.h>

using namespace std;

int getMedian(int i1, int i2, int i3)
{
    cout << i1 << " " << i2 << " " << i3 << endl;
    int median;
    std::cin >> median;
    return median;
}

int insert(vector<int> &array, int element, int startIndex, int endIndex)
{
    int windowSize = endIndex - startIndex + 1;
    switch (windowSize)
    {
    case 0:
        [[fallthrough]];
    case 1:
    {
        array.insert(array.begin() + startIndex, element);
        return startIndex;
    }
    case 2:
        [[fallthrough]];
    case 3:
        {
            int first = array[startIndex], second = array[startIndex + 1];
            int med = getMedian(first, element, second);
            if (med == first)
            {
                array.insert(array.begin() + startIndex, element);
                return startIndex;
            }
            else if (med == element)
            {
                array.insert(array.begin() + startIndex + 1, element);
                return startIndex + 1;
            }
            else if (med == second)
            {
                if ((endIndex == array.size() - 1) && windowSize == 3)
                {
                    return insert(array, element, startIndex + 1, endIndex);
                }
                array.insert(array.begin() + startIndex + 2, element);
                return startIndex + 2;
            }
            else
            {
                return -1;
            }
        }
    default:
        break;
    }
    int mid1Index = (endIndex + (2 * startIndex)) / 3;
    int mid2Index = ((2 * endIndex) + startIndex) / 3;
    int mid1 = array[mid1Index];
    int mid2 = array[mid2Index];
    int med = getMedian(mid1, element, mid2);
    if (med == mid1)
    {
        return insert(array, element, startIndex, mid1Index);
    }
    else if (med == mid2)
    {
        return insert(array, element, mid2Index, endIndex);
    }
    else if (med == element)
    {
        if (mid2Index == mid1Index + 1) {
            array.insert(array.begin() + mid2Index, element);
            return mid2Index;
        }
        return insert(array, element, mid1Index, mid2Index);
    }
    else
    {
        return -1;
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
            if (result == -1)
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