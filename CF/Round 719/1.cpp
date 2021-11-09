#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

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
        ll N;
        string str;
        cin >> N >> str;
        assert(N == str.size());
        set<char> seen;
        bool no_repitition = true;
        for(int i=0; i<N; i++) {
            char c = str[i];
            if (seen.find(c) != seen.end()) {
                no_repitition = false;
                break;
            }
            while(str[i+1] == c) {
                i++;
            }
            seen.insert(c);
        }
        
        cout << ((no_repitition)?"YES":"NO") << endl;
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