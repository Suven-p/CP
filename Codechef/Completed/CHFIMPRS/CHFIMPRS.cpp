#include <bits/stdc++.h>

using namespace std;

inline bool is_odd(int N) { return (N % 2 == 1); }
inline bool is_even(int N) { return (N % 2 == 0); }

auto is_possible(const vector<vector<int>> &arr, map<int, int> &frequency, int num_rows, int num_cols)
{
    int row = 0, col = 0;
    if (num_cols == 0 || num_cols == 1)
        return make_pair(true, arr);
    std::vector<std::vector<int>> new_array(num_rows, vector<int>(num_cols, 0));
    vector<int> remaining_positions;
    vector<int> remaining_elements;
    for (auto &[key, value] : frequency)
    {
        if (is_odd(value) && is_even(num_cols))
            return make_pair(false, new_array);

        while (value > 1)
        {
            if (col < num_cols / 2)
            {
                new_array[row][col] = key;
                new_array[row][num_cols - col - 1] = key;
                col++;
                value -= 2;
            }
            else
            {
                if (row < num_rows - 1)
                {
                    row++;
                    col = 0;
                }
                else
                    break;
            }
        }
    }
    if (row != num_rows - 1 || col != (num_cols / 2))
        return make_pair(false, new_array);
    if (is_even(num_cols))
        return make_pair(true, new_array);
    row = 0;
    for (auto it = frequency.begin(); it != frequency.end();)
    {
        if (it->second == 0)
            it = frequency.erase(it);
        else
            ++it;
    }
    for (auto &[key, value] : frequency)
    {
        while (value)
        {
            if (row == num_rows)
                return make_pair(false, new_array);
            new_array[row][num_cols / 2] = key;
            value--;
            row++;
        }
    }
    if (row != num_rows)
        return make_pair(false, new_array);
    return make_pair(true, new_array);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N, M;
        cin >> N >> M;
        int array[N][M];
        std::vector<std::vector<int>> data(N, vector<int>(M, 0));
        map<int, int> frequency;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> data[i][j];
                frequency[data[i][j]] += 1;
            }
        }
        auto result = is_possible(data, frequency, N, M);
        if (result.first)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    cout << (result.second)[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}