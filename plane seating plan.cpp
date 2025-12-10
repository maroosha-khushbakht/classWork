#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int seats[12][6] = 
    {
        {0,1,1,1,0,1},
        {1,1,0,0,1,1},
        {2,0,0,0,1,1},
        {1,1,1,0,0,1},
        {1,0,2,1,1,1},
        {0,1,1,1,1,1},
        {0,1,0,1,1,0},
        {1,1,0,2,2,1},
        {0,1,1,1,1,1},
        {1,2,1,0,1,0},
        {1,0,0,0,1,0},
        {1,1,1,0,1,0}
    };

    int eS = 0;
    int max = 0;
    int uS = 0;

    vector<int> t;   

    for (int i = 0; i < 12; i++) 
    {
        int eC = 0;

        for (int j = 0; j < 6; j++) 
        {
            if (seats[i][j] == 0)
                eC++;

            if (seats[i][j] == 0 || seats[i][j] == 1)
                uS++;

            if (seats[i][j] == 0 &&
                seats[i][j+1] == 0 &&
                seats[i][j+2] == 0)
            {
                t.push_back(i + 1);
                t.push_back(j + 1); 
            }
        }

        if (eC > eS) 
        {
            eS = eC;
            max = i + 1;
        }
    }

    cout << "Row with highest empty seats: " << max << endl;

    cout << "Three consecutive empty seats: "
         << (t.size() > 0 ? "YES" : "NO") << endl;

    if (t.size() > 0)
    {
        cout << "Rows with three consecutive empty seats:" << endl;

        for (int i = 0; i < t.size(); i += 2)
        {
            int r = t[i];      
            int c = t[i + 1];  

            cout << "Row " << r
                 << ", Seats " << c << ", " << c + 1 << ", " << c + 2 
                 << endl;
        }
    }

    cout << "Total usable seats: " << uS << endl;

    return 0;
}
