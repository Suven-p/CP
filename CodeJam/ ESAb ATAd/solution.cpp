#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

bool guess(string &data, int &queries);
pair<bool, bool> handleFluctuation(string &data, int &numQueries, int spIndex, int dpIndex);

char getData(int index)
{
    cout << index << endl;
    char data;
    cin >> data;
    return data;
}

string compliment(const string &s)
{
    string data(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            data[i] = '1';
        }
        else if (s[i] == '1')
        {
            data[i] = '0';
        }
    }
    return data;
}

struct guess
{
    string data;
};

char checkAnswer(const string &s)
{
    cerr << "Checking answer " << s << endl;
    cout << s << endl;
    char c;
    cin >> c;
    if (c == 'Y')
        return c;
    // contestant input 10001101010111111001, but answer is 10011101010111010001
    // string reversedData = s;
    // std::reverse(reversedData.begin(), reversedData.end());
    // cout << reversedData << endl;
    // cin >> c;
    // if (c == 'Y') return c;

    // string complimentedData = compliment(s);
    // cout << complimentedData << endl;
    // cin >> c;
    // if (c == 'Y') return c;

    // string complAndReverse = complimentedData;
    // std::reverse(complAndReverse.begin(), complAndReverse.end())
    // cout << complAndReverse << endl;
    // cin >> c;
    // if (c == 'Y') return c;

    // string reverseAndcompl = compliment(reversedData);
    // cout << reverseAndcompl << endl;
    // cin >> c;
    // if (c == 'Y') return c;

    return 'N';
}

int main()
{
    int T, B, tries;
    cin >> T >> B;
    cerr << "Received values: " << T << " and " << B << endl;
    for (int numTest = 0; numTest < T; numTest++)
    {
        cerr << "Starting test " << numTest + 1 << endl;
        string data(B, 'x');
        int queries = 0;
        tries = 0;
        auto correct = guess(data, queries);
        cerr << "\n\n"
             << endl;
    }

    return 0;
}

bool guess(string &data, int &queries)
{
    char correct = 'N';
    int spIndex = -1;
    int dpIndex = -1;
    int B = data.size();
    if (B >= 150)
    {
        cerr << "B is greater than 150" << endl;
    }
    string temp(data);

    for (int i = 0; i < int(B / 2); i++)
    {
        if (queries >= 150)
        {
            return false;
        }
        if (data[i] == '0' || data[i] == '1')
        {
            continue;
        }

        cerr << "Asking for character " << i + 1 << endl;
        char c = getData(i + 1);
        queries++;
        cerr << "Obtained character1 " << c << " Numqueries: " << queries << endl;
        pair<bool, bool> result = handleFluctuation(data, queries, spIndex, dpIndex);
        data[i] = c;
        cout << "Data is:\t " << setw(25) << data << endl << endl;

        cerr << "Asking for character " << B - i << endl;
        char nc = getData(B - i);
        queries++;
        cerr << "Obtained character2 " << nc <<  " Numqueries: " << queries << endl;
        auto [isComplimented, isReversed] = handleFluctuation(data, queries, spIndex, dpIndex);
        data[B - i - 1] = nc;
        cout << "Data is:\t " << setw(25) << data << endl << endl;

        if (spIndex == -1 && c == nc)
        {
            spIndex = i;
        }
        if (dpIndex == -1 && c != nc)
        {
            dpIndex = i;
        }
    }

    if (B % 2 != 0)
    {
        char c = getData(int(B / 2) + 1);
        queries++;
        handleFluctuation(data, queries, spIndex, dpIndex);
        cout << "Last data " << int(B / 2) + 1 << " " << c << " Numqueries: " << queries << endl;
        data[int(B) / 2] = c;
    }

    correct = checkAnswer(data);
    return correct;
}

pair<bool, bool> handleFluctuation(string &data, int &numQueries, int spIndex, int dpIndex)
{
    if (numQueries <= 1 || numQueries % 10 != 1)
    {
        return {false, false};
    }
    cerr << "Begin fluctuation handler " << spIndex << " " << dpIndex << endl;
    bool samePairFlip = false, differentPairFlip = false, isComplimented = false, isReversed = false;
    if (spIndex != -1)
    {
        cerr << "Asking for character " << spIndex + 1 << endl;
        char oldData = data[spIndex], ch = getData(spIndex + 1);
        samePairFlip = (ch != oldData);
        cerr << " Obtained characterf1 " << ch << " Data is:\t " << setw(25) << data << " Numqueries: " << numQueries << endl;
        numQueries++;
    }
    if (dpIndex != -1)
    {
        cerr << "Asking for character " << dpIndex + 1 << endl;
        char oldData = data[dpIndex], ch = getData(dpIndex + 1);
        differentPairFlip = (ch != oldData);
        cerr << " Obtained characterf2 " << ch << " Data is:\t " << setw(25) << data << " Numqueries: " << numQueries << endl;
        numQueries++;
    }
    if (samePairFlip)
    {
        data = compliment(data);
        cerr << "Complimenting data to " << data << endl;
        isComplimented = true;
    }
    if (differentPairFlip)
    {
        if (!samePairFlip)
        {
            std::reverse(data.begin(), data.end());
            cerr << "Reversing data to " << data << endl;
            isReversed = true;
        }
    }
    else
    {
        if (samePairFlip)
        {
            std::reverse(data.begin(), data.end());
            cerr << "Reversing data to " << data << endl;
            isReversed = true;
        }
    }
    cerr << "End fluctuation handler" << endl;
    return {isComplimented, isReversed};
}