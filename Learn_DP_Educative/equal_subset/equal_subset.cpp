using namespace std;


#include <iostream>
#include <vector>
#include <list>
#include <numeric>

class PartitionSet {
public:
  bool canPartition(const vector<int> &num, size_t currentIndex=0) {
    //TODO: Write - Your - Code
    auto total = accumulate(num.begin(), num.end(), 0);
    if (total % 2 == 1) return false;
    else {
        list<int> temp = list<int>(num.begin(), num.end());
        return (canSum(temp, total/2));
    }
  }

  int canSum(list<int> &num, int sum) {
    if (sum == 0) return true;
    if (sum < 0 || num.empty()) return false;
    auto total = accumulate(num.begin(), num.end(), 0);
    if (total < sum) return false;
    if (total == sum) return true;
    for (auto it = num.begin(); it != num.end();) {
      int data = *it;
      it = num.erase(it);
      auto result = canSum(num, sum-data);
      if (result)
        return true;
      num.insert(it, data);
    }
    return false;
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    PartitionSet p1;
    vector<int> input = {1,1,3,4,7};
    auto result = p1.canPartition(input);
    cout << ((result)?"True":"False") << endl;

    return 0;
}