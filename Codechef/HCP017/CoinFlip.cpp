#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int G;
        cin >> G;
        int I, N, Q;
        for (int game = 1; game <= G; game++) {
            cin >> I >> N >> Q;
            int num_flipped = (N+1)/2;
            int num_same_side = N - num_flipped;
            cout << ((I == Q)? num_same_side:num_flipped) << endl;
        }
    }

    return 0;
}