using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {

    bool dp[num.size()][sum+1];

    for (int i=0; i < num.size(); i++)
      dp[i][0] = true;
    for (int i=1; i<=sum; i++)
      dp[0][i] = (num[0] == i);


    for (int i=1; i < num.size(); i++) {
      for (int j=1; j <= sum; j++) {
        dp[i][j] = dp[i-1][j];
        if (!dp[i][j] && num[i] <= j) {
          dp[i][j] = dp[i][j] || dp[i-1][j-num[i]];
        }
      }
      if (dp[i][sum]) return true;
    }
    return dp[num.size() - 1][sum];
  }
};

int main() {
    vector<int>input = {1, 3, 4, 8};
    int sum = 6;
    SubsetSum s;
    auto result = s.canPartition(input, sum);
    if (result) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}