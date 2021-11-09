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

// Here ans[i] contains index j such that j < i and arr[j] >= arr[i]
void get_previous_max(int arr[], int size, int ans[]) {
    stack<int> st;
    for (auto i=size-1; i >=0; i--) {
        auto element = arr[i];
        while (!st.empty() && element >= arr[st.top()]) {
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



int main() {
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {

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