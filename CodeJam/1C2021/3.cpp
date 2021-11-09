#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair


int solve(string S, string E, int count = 0) {
    if (S == E) {
        return count;
    }
    bool found_1 = false;
    auto begin = E.find_first_of('1');
    if (begin == E.npos) {
        return -1;
    }
    string temp = E.substr(begin);
    if (temp.back() == '1') {
        for (auto &c:temp) {
            if (c=='0') c = '1';
            else c = '0';
        }
        int ans = solve(S, temp, count+1);
        return ans;
    }
    else if (temp.back() == '0') {
        auto end = E.find_last_of('1');
        for(ll i=end; i < temp.size(); i++) {
            string temp2 = E.substr(0, i+1);
            int ans = solve(S, temp2, count+1);
            if (ans != -1)
                return ans;
        }
    }
    return -1;
}

int main() {
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        string S, E;
        cin >> S >> E;
        auto ans = solve(S, E);
        cout << (ans==-1)?"IMPOSSIBLE":ans << endl;
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