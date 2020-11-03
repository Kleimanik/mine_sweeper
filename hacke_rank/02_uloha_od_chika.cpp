#include <iostream>
using namespace std;
int main()
{
    int cislo, pocitadlo;
    cin >> cislo;
    for (pocitadlo=1;pocitadlo<=10;pocitadlo++)
    {
        cout << "Vase "<< pocitadlo << ". cislo: " << cislo << "*" << pocitadlo << "=" << cislo*pocitadlo << endl;
    }
}