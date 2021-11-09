#include <bits/stdc++.h>

using namespace std;

pair<bool, vector<int>> generateArray(int N, int C) {
    if (C < N-1 || C > ((N*(N+1))/2) - 1) {
        return {false, {}};
    }
    vector<int> array(N, 0);
    for (int i=0; i < N; i++) {
        array[i] = i+1;
    }
    if (C == N-1) {
        return {true, array};
    }
    int minSwaps = N-1;
    int extraSwaps = C - minSwaps;
    if (extraSwaps >= 0 && extraSwaps < N) {
        array[extraSwaps] = 1;
        for (int i=1; extraSwaps-i >= 0;i++) {
            array[extraSwaps-i] = i+1;
        }
        for (int i = extraSwaps+1; i < N; i++) {
            array[i] = i+1;
        }
        return {true, array};
    }
    else {
        int currentCount = 0;
        array[N-1] = 1;
        currentCount += N;
        auto [found, newArray] = generateArray(N-1, C-currentCount);
        if (found) {
            for (int i=0; i<(N-1); i++) {
                newArray[i]++;
            }
            reverse(newArray.begin(), newArray.end());
            for (int i=0; i<(N-1); i++) {
                array[i] = newArray[i];
            }
            return {found, array};
        }
        else {
            return {found, {}};
        }
    }

}

int main() {
    int T;
    cin >> T;
    for (int numTest = 0; numTest < T; numTest++) {
        int N, C;
        cin >> N >> C;
        // bool possible = true;
        // vector<int> array(N, 0);

        auto [possible, array] = generateArray(N, C);

        if (!possible) {
            cout << "Case #" << numTest + 1 << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << numTest + 1 << ": ";
            for (auto c:array) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
}