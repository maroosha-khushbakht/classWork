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

    vector<int> triples;   

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
                seats[i][j+1] == 0 &&
                seats[i][j+2] == 0)
            {
                triples.push_back(i + 1); 
                triples.push_back(j + 1); 
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
         << (triples.size() > 0 ? "YES" : "NO") << endl;

    if (triples.size() > 0)
    {
        cout << "Rows with three consecutive empty seats:" << endl;

        for (int i = 0; i < triples.size(); i += 2)
        {
            int row = triples[i];
            int col = triples[i + 1];

            cout << "Row " << row
                 << ", Seats " << col << ", " << col + 1 << ", " << col + 2 
                 << endl;
        }
    }

    cout << "Total usable seats: " << uS << endl;

    return 0;
}
