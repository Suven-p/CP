#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

// Here ans[i] contains index, j such that j>i and arr[j]>=arr[i]
void get_next_max(int arr[], int size, int ans[]) {
    stack<int> st;
    for (int i=0; i < size; i++) {
        auto element = arr[i];
        while(!st.empty() && element >= arr[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }
    return;
}

auto solve0(int heights[], int N)
{
    vector<int> ans(N, 0);
    int cur_i = 0;
    while (cur_i < N - 1)
    {
        int temp = cur_i + 1;
        while (heights[temp] <= heights[cur_i])
        {
            if (heights[temp] == heights[cur_i])
            {
                ans[cur_i]++;
                ans[temp]++;
            }
            temp++;
        }
        cur_i++;
    }
    return ans;
}
auto solve1(int heights[], int N) {
    int next_max[N];
    vector<int> ans(N, -1);
    get_next_max(heights, N, next_max);
    for (int i=0; i < N; i++) {
        if (ans[i] != -1) {
            continue;
        }
        auto next_max_index = next_max[i];
        if (next_max_index == -1 || heights[next_max_index] > heights[i]) {
            ans[i] = 0;
            continue;
        }

        queue<int> to_process;
        int first = i, second = next_max[first];
        while (second != -1 && heights[first] == heights[second]) {
            to_process.push(first);
            first = second;
            second = next_max[first];
        }
        to_process.push(first);

        int sz = to_process.size() - 1;
        while(!to_process.empty()) {
            int index = to_process.front();
            ans[index] = sz;
            to_process.pop();
        }

    }
    return ans;
}

int main()
{
#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll N;
        cin >> N;
        int heights[N];
        for (ll i = 0; i < N; i++)
        {
            cin >> heights[i];
        }
        auto ans = solve1(heights, N);

        for (ll i=0; i < N; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}