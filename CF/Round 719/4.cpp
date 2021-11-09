#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int solve(const vector<int> &data) {
    int differences[data.size()];
    int ans = 0;
    for (int i=1; i < data.size(); i++) {
        differences[i] = data[i]-data[0];
        if (differences[i] == i) {
            ans++;
        }
    }
    for (int i=1; i < data.size(); i++) {
        int diff = data[i] - data[i-1];
        for (int j=i+1; j < data.size(); j++) {
            differences[j] -= diff;
            if (differences[j] == j-i) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N;
        cin >> N;
        vector<int> data(N, 0);
        for (int i=0; i < N; i++) {
            cin >> data[i];
        }
        auto ans = solve(data);
        cout << ans << endl;
    }

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}