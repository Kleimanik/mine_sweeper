#include <iostream>

using namespace std;

int main()
{
    int poc_z;
    double avg , avg_z ;
    cout << "Zadaj pocet ziakov: ";
    cin >> poc_z;
    int znamky[poc_z];
    for (int i=0 ; i<poc_z ; i++)
    {
        cout << i << ". Ziak ma priemer: ";
        cin >> znamky[i];
    }

    int tem , i;
    cout << "Zadaj cislo milasika ";
    cin >> i;
    tem = znamky[0];
    znamky[0] = znamky[i];
    znamky[i] = tem;

    for (int i=0 ; i<poc_z ; i++)
    {
        cout << znamky[i];
        avg += znamky[i];
        if (avg_z>3.5)
        {
            avg_z=3;
        }
        if (avg_z<=1.5)
        {
            cout << "Prirmer " << i << " ziaka je " << avg_z << " co je vyborny." << endl;
        }
        else
        {
            if(avg_z<=2.5)
            {
                cout << "Prirmer " << i << " ziaka je " << avg_z << " co je chvalitebny." << endl;
            }
            else
            {
                if(avg_z<=3.5)
                {
                    cout << "Prirmer " << i << " ziaka je " << avg_z << " co je dobry." << endl;
                }
                else
                {
                    if(avg_z<=4.5)
                    {
                        cout << "Prirmer " << i << " ziaka je " << avg_z << " co je dostatocny." << endl;
                    }
                    else
                    {
                        cout << "Prirmer " << i << " ziaka je " << avg_z << " co je nedostatocny." << endl;
                    }
                }
            }
        }
    }
    avg = avg/poc_z;
    cout << "Priemer celej triedy je " << avg << endl;    
}