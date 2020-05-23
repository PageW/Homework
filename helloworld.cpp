#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main()
{
    for (int x = 1; x < 16; x++)
    {

        int diff = x & (-x);
        cout << x << " " << diff << endl;
    }

    return 0;
}