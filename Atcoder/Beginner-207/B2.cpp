#include <iostream>

using namespace std;

int main()
{

    int cyan, red = 0;
    int count = 0;
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cyan = A;
    if (A == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (B >= C * D)
    {
        cout << -1 << endl;
    }
    else
    {
        while (cyan > D * red)
        {
            cyan += B;
            red += C;
            count++;
        }
        cout << count << endl;
    }

    return 0;
}