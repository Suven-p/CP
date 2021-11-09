#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N, K;
        cin >> N >> K;
        vector<int> items(N, -1);
        bool possible = false;
        int num_even = 0;
        for (int i=0; i < N; i++) {
            cin >> items[i];
            if (items[i] % 2 == 0) {
                num_even++;
            }
        }
        possible = (K == 0) ? (num_even != N) : (num_even >= K);
        cout << ((possible)?"YES":"NO") << endl;
    }

    return 0;
}