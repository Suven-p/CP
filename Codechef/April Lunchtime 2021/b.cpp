#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int main() {
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll N, A, B;
        cin >> N >> A >> B;
        ll points[2] = {0, 0};
        set<char> req = {'E', 'Q', 'U', 'I', 'N', 'O', 'X'};
        string temp;
        for (ll i=0; i < N; i++) {
            cin >> temp;
            auto first = temp[0];
            if (req.find(first) != req.end()) {
                points[0] += A;
            }
            else {
                points[1] += B;
            }
        }
        if (points[0] > points[1]) {
            cout << "SARTHAK" << endl;
        }
        else if (points[1] > points[0]) {
            cout << "ANURADHA" << endl;
        }
        else {
            cout << "DRAW" << endl;
        }
    }

    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
    #endif
    return 0;
}