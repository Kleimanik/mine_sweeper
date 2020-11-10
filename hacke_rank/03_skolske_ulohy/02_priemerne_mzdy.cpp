#include <iostream>

using namespace std;

int main()
{
    int pocet_zamestnancov, mzdy[60], sum=0, i, minimum, min_mzda, median, vip[60], x=0;
    double avg=0;
    cout << "Zadaj po+cet zamestnancov: ";
    cin >> pocet_zamestnancov;
    for (i=0;i<pocet_zamestnancov;i++)
    {
        cout << "Zadaj mzdu " << i+1 << ". Zamestnanca: ";
        cin >> mzdy[i];
    }
    minimum=mzdy[1];
    for (i=0;i<pocet_zamestnancov;i++)
    {
        cout << mzdy[i] << endl;
        sum+=mzdy[i];
        if (minimum>mzdy[i])
        {
            minimum=mzdy[i];
            min_mzda=i;
        }
        if (mzdy[i]>500)
        {
            vip[x]=mzdy[i];
            x++;
        }
    }
    if (pocet_zamestnancov%2==1)
    {
        median=mzdy[pocet_zamestnancov/2];
    }
    else
    {
        median=(mzdy[pocet_zamestnancov/2+1]+mzdy[pocet_zamestnancov/2])/2;
    }
    
    cout << "Median je: " << median << endl;
    avg=sum/pocet_zamestnancov;
    cout << "priemerna mzda je " << avg << "." << endl;
    cout << "Najmensia mzda je " << minimum << " a ma ju " << min_mzda << ". zamestnanec." << endl;
    return 0;
}