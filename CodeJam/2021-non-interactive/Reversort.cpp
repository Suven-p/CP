#include <bits/stdc++.h>

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
            int min = array[i];
            for (int j = i; j < N; j++) {
                if (array[j] < array[min]) min = j;
            }
            reverse(array.begin()+i, array.end()-min);
            cout << "Array is: ";
            for (auto c: array) cout << c << ' ';
            cout << endl;
            Y += min-i+1;
        }


        cout << "Case #" << numTest + 1 << ": " << Y << endl;
    }

}