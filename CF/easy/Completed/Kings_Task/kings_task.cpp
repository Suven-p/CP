#include <bits/stdc++.h>
using namespace std;

int index_after_n_operations(int current_index, int num_operations, int n)
{
    if (num_operations == 0)
        return current_index;
    int result = 0;
    if (current_index % 2 == 0)
    {
        if (num_operations % 2 == 0)
        {
            result = current_index + ((int(num_operations / 2) * n) - int(num_operations / 2));
        }
        else
        {
            result = current_index + ((int((num_operations + 1) / 2) * n) - int((num_operations + 1) / 2)) + 1;
        }
    }
    else
    {
        if (num_operations % 2 == 0)
        {
            result = current_index + ((int(num_operations / 2) * n) + int(num_operations / 2));
        }
        else
        {
            result = current_index + ((int((num_operations + 1) / 2) * n) + int((num_operations + 1) / 2)) - 1;
        }
    }
    return result % (2 * n);
}

int solve(vector<int> arr, vector<int> &first, vector<int> &second)
{
    if (is_sorted(arr.begin(), arr.end()))
    {
        return 0;
    }
    if (first.size() % 2 == 0)
    {
        // For sub-array of even size, only possible states are original, flip first and second, adjacent-flipped, both
        vector<int> temp1(arr.size(), 0), temp2(arr.size(), 0);
        temp2 = second; // flip first and second
        temp2.insert(temp2.end(), first.begin(), first.end());
        if (is_sorted(temp2.begin(), temp2.end()))
        {
            return 1;
        }
        // temp1 contains array when adjacent positions are flipped
        // temp2 contains array when adjacent positions are flipped and first and second are interchanged
        for (int i = 0; i < first.size(); i += 2)
        {
            temp1[i] = first[i + 1];
            temp1[i + 1] = first[i];
            temp2[i] = second[i + 1];
            temp2[i + 1] = second[i];
        }
        for (int i = 0; i < second.size(); i += 2)
        {
            temp1[first.size() + i] = second[i + 1];
            temp1[first.size() + i + 1] = second[i];
            temp2[first.size() + i] = first[i + 1];
            temp2[first.size() + i + 1] = first[i];
        }

        if (is_sorted(temp1.begin(), temp1.end()))
        {
            return 1;
        }
        else if (is_sorted(temp2.begin(), temp2.end()))
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int first_elem = arr[0];
        size_t num_operations = 0;
        bool is_valid = true;
        while (num_operations <= arr.size())
        {
            if (index_after_n_operations(0, num_operations, int(arr.size() / 2)) == first_elem - 1)
            {
                break;
            }
            else
            {
                num_operations++;
            }
        }
        if (num_operations >= arr.size())
        {
            return -1;
        }
        else
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (index_after_n_operations(i, num_operations, int(arr.size() / 2)) != arr[i] - 1)
                {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid)
            {
                return min(num_operations, arr.size() - num_operations);
            }
            else
            {
                return -1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t N;
    cin >> N;
    int ans = 0;
    vector<int> arr, first, second;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        first.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        second.push_back(temp);
    }
    ans = solve(arr, first, second);

    cout << ans << endl;
    return 0;
}