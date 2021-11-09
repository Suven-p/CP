#include <bits/stdc++.h>
// This passes both tests.
using namespace std;

auto logit(long double x)
{
    long double constant = 1.0;
    return log(x / (constant - x));
}

long double sigmoid(long double x)
{
    long double constant = 1.0;
    return constant / (constant + exp(-x));
}

int main()
{
    int T, P;
    cin >> T >> P;
    for (int nT = 0; nT < T; nT++)
    {
        vector<string> answerData(100, "");
        vector<int> correctness(100, 0);    // correctness[i]=number of correct answers given by player i
        vector<float> easiness(10000, 0);
        vector<long double> difficultyGrading(10000, 0);
        vector<long double> skillGrading(100, 0);
        vector<int> suspects;
        int cheater = -1;

        // input data
        for (int i = 0; i < 100; i++)
        {
            cin >> answerData[i];
            for (auto c : answerData[i])
            {
                if (c == '1')
                {
                    correctness[i]++;
                }
            }
            skillGrading[i] = logit(correctness[i]/10000.0);
        }

        // exclude anyone with score less than 5000 or half
        for (int i = 0; i < 100; i++)
        {
            if (correctness[i] > 5000)
            {
                suspects.push_back(i);
            }
        }

        // calculate easiness  based on how many people have the correct answer
        for (int i = 0; i < 10000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (answerData[j][i] == '1')
                {
                    easiness[i]++;
                }
            }
            difficultyGrading[i] = logit(easiness[i]/100.0);
        }

        long double max = -1;
        for (int k = 0; k < suspects.size(); k++)
        {
            int i = suspects[k];
            int c = correctness[i];
            if (c >= 9975)
            {
                cheater = i + 1;
                break;
            }
            long double probability = 0;

            if (probability > max)
            {
                max = probability;
                cheater = i + 1;
            }
        }
        cout << "Case #" << nT + 1 << ": " << cheater << endl;
    }
}