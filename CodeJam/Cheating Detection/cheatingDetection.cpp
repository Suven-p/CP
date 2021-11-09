#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, P;
    cin >> T >> P;
    for (int nT = 0; nT < T; nT++) {
        vector<string> answerData(100, "");
        vector<int> correctness(100, 0);        // correctness[i]=number of correct answers given by player i
        vector<int> easiness(10000, 0);         // easiness[i]=number of students who answered question i
        vector<int> probability(100, 0);        // probability[i]=number of questions having <50% accuracy and answered by student
        vector<int> suspects;
        int cheater = -1;

        // input data
        for (int i=0; i< 100; i++) {
            cin >> answerData[i];
            for (auto c:answerData[i]) {
                if (c == '1') {
                    correctness[i]++;
                }
            }
        }

        // exclude anyone with score less than 5000 or half
        for (int i=0; i<100; i++) {
            if (correctness[i] > 5000) {
                suspects.push_back(i);
            }
        }

        // calculate easiness  based on how many people have the correct answer
        for(int i=0; i<10000; i++) {
            int cumulative = 0;
            for(int j=0; j < 100; j++) {
                if (answerData[j][i] == '1') {
                    cumulative++;
                }
            }
            easiness[i] = cumulative;
            // For every question a student has answered increase probability if question is solved by less than half of class
            if (cumulative <= 5) {
                for (int j=0; j < 100; j++) {
                    if (answerData[j][i] == '1') {
                        probability[j] += 6 - cumulative;
                    }
                }
            } else if (cumulative >= 95){
                // For every question a student has answered wrong decrease probability if question is solved by more than half of class
                for (int j=0; j < 100; j++) {
                    if (answerData[j][i] == '0') {
                        probability[j] += cumulative - 94;
                    }
                }
            }
        }

        auto customComparator = [correctness](int a, int b) {
            return correctness[a] > correctness[b];
        };
        sort(suspects.begin(), suspects.end(), customComparator);

        int max = 0;
        int diff = 0;
        for(int k=0;  k<suspects.size(); k++) {
            int i = suspects[k];
            int c = correctness[i], p = probability[i];
            if (c >= 9975) {
                cheater = i+1;
                break;
            }
            if (k==0) {
                diff = probability[suspects[k+1]];
            } else if (k== suspects.size() - 1) {
                diff = probability[suspects[k-1]];
            } else {
                diff = (probability[suspects[k+1]] + probability[suspects[k-1]])/2;
            }
            if (diff > max) {
                max = diff;
                cheater = i+1;
            }
        }

        cout << "Case #" << nT + 1 << ": " << cheater << endl;
    }
}