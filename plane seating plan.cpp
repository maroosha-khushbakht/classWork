#include <iostream>
using namespace std;
int main() 
{
    int seats[12][6] = 
    {
        {0,1,1,1,0,1},
        {1,1,0,0,1,1},
        {2,0,0,1,0,1},
        {1,1,1,0,0,1},
        {1,0,2,1,1,1},
        {0,1,1,1,1,1},
        {0,1,0,1,1,0},
        {1,1,0,2,2,1},
        {0,1,1,1,1,1},
        {1,2,1,0,1,0},
        {1,0,1,0,1,0},
        {1,1,1,0,1,0}
    };

    int eS = 0;
    int max = 0;
    int uS = 0;
    bool found = false;

    for (int i = 0; i < 12; i++) 
    {
        int eC = 0;

        for (int j = 0; j < 6; j++) 
        {
            if (seats[i][j] == 0)
                eC++;

            if (seats[i][j] == 0 || seats[i][j] == 1)
                uS++;

            if (j <= 3 &&
                seats[i][j] == 0 &&
                seats[i][j + 1] == 0 &&
                seats[i][j + 2] == 0) {
                found = true;
            }
        }

        if (eC > eS) 
        {
            eS = eC;
            max = i + 1;
        }
    }

    cout << "Row with highest empty seats: " << max << endl;
    cout << "Three consecutive empty seats: " << (found ? "YES" : "NO") << endl;
    cout << "Total usable seats: " << uS << endl;

    return 0;
}
