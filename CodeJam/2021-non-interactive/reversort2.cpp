#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int numTest = 0; numTest < T; numTest++) {
        int N;
        cin >> N;
        int Y = 0;
        vector<int> array(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> array[i];
        }
        for (int i=0; i<N-1; i++) {
            int min = i;
            for (int j = i; j < N; j++) {
                if (array[j] < array[min]) min = j;
            }
            std::reverse(array.begin()+i, array.begin()+min+1);
            Y += min-i+1;
        }
        cout << "Case #" << numTest + 1 << ": " << Y << endl;
    }

}