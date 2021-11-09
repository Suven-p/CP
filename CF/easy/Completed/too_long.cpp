// https://codeforces.com/problemset/problem/71/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        string word, new_word;
        cin >> word;
        if (word.size() <= 10) {
            new_word = word;
        }
        else {
            new_word = word[0] + to_string(word.substr(1, word.size()-2).size()) + word[word.size()-1];
        }
        cout << new_word << endl;
    }
    return 0;
}