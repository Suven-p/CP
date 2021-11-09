#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int numTest = 1; numTest<=T; numTest++) {
        int N;
        string result = "", prefix="", suffix="", mid="";
        int first=-1, last=-1;
        bool possible = true;
        cin >> N;
        vector<string> patterns;
        for (int i=0; i < N; i++) {
            string pattern;
            cin >> pattern;
            patterns.push_back(pattern);
        }

        sort(patterns.begin(), patterns.end(), [](string a, string b){return a.size() > b.size();});

        for (auto pattern:patterns) {
            first = -1;
            last = -1;
            for (int i=0; i < pattern.size(); i++) {
                if (pattern[i] != '*') {
                    if (i < prefix.size()) {
                        if (pattern[i] != prefix[i]) {
                            possible = false;
                            break;
                        }
                    } else {
                        prefix = prefix + pattern[i];
                    }
                } else {
                    first = max(first, i);
                    break;
                }
            }
            for (int j=0, size=pattern.size(); j < size; j++) {
                int i = size-j-1;
                if (pattern[i] != '*') {
                    if (j < suffix.size()) {
                        if (pattern[i] != suffix[suffix.size()-j-1]) {
                            possible = false;
                            break;
                        }
                    } else {
                        suffix = pattern[i] + suffix;
                    }
                } else {
                    last = min(last, i);
                    break;
                }
            }
            if (first != last) {
                for (int i=first+1; i < last; i++) {
                    if (pattern[i] != '*') {
                        mid += pattern[i];
                    }
                }
            }
            if (!possible) {
                break;
            }
        }
        if (possible) {
            result = prefix + mid + suffix;
        } else {
            result = "*";
        }
        cout << "Case #" << numTest << ": " << result << endl;
    }
}