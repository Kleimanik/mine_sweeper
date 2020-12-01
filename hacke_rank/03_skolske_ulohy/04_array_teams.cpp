#include <iostream>

using namespace std;

int main()
{
    int n_teams;
    cout << "Zadaj pocet teamov: ";
    cin >> n_teams;
    int team_points[n_teams] = {}, vip=0;
    string mena[n_teams];
    for(int i=0; i<n_teams; i++)
    {
        cout << "Zadaj nazov teamu: ";
        cin >> mena[i];
        cout << "Zadaj body " << i+1 << ". teamu: ";
        cin >> team_points[i];
        if (team_points[i]>10)
        {
            vip++;
        }
    }
    cout << "Pocet vip teamov: " << vip << endl;
    int repeat = 1;
    while(repeat!=0)
    {
        cout << "1 - vypis teamov" << endl;
        cout << "2 - priemerny pocet bodov" << endl;
        cout << "3 - najlepsi team bude prvy v poradi" << endl;
        cout << "0 - vypis teamov" << endl;
        cin >> repeat;
        if (repeat=1)
        {
            for (int i=0; i<n_teams; i++)
            {
                cout << i+1 << ". Team " << mena[i] << ": " << team_points[i] <<endl;
            }
        }
        else
        {
            if (repeat=2)
            {
                for (int i=0; i<n_teams; i++)
                {
                    int avg;
                    avg += team_points[i];
                }
                double avg=avg/n_teams;
                cout << "Priemer bodov je " << avg << endl;
            }
            else
            {
                //if (repeat=3)
            }
            
        }
        
    }

    return 0;
}