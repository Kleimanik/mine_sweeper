#include <iostream>

using namespace std;

int main()
{
    int pocet_znamok, i, znamky[20], sucet, oprava, min, poradie_min;
    double priemer;
    string meno_ziaka;
    cout << "Zadaj meno ziaka: ";
    cin >> meno_ziaka;
    cout << "zadaj pocet znamok: ";
    cin >> pocet_znamok;
    for (i=0;i<pocet_znamok;i++)
    {
        cout << "Zadaj " << i+1 << " znamku:";
        cin >> znamky[i];
        sucet=znamky[i]+sucet;
    }
    cout << "Vypis znamok:";
    for (i=0;i<pocet_znamok;i++)
    {
        cout << " " << znamky[i] << ",";
    }
    cout << "Zadaj poradove cislo znamky ktoru chces opravit, ak nechces zadaj nulu." << endl;
    cin >> oprava;
    if (oprava!=0)
    {
        cout << "Zadaj opravnu znamku:";
        cin >> znamky[oprava-1];
        min=znamky[0];
        for (i=0;i<pocet_znamok;i++)
        {
            sucet=znamky[i]+sucet;
            cout << " " << znamky[i] << ",";
            if (znamky[i]<min)
            {
                poradie_min=i+1;
                min=znamky[i];
            }
        }
    }
    priemer=sucet/pocet_znamok;
    cout << "Priemer vasich znamok je " << priemer << endl;
    return 0;
}