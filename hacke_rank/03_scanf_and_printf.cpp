#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
    int i;
    long l;
    char c;
    float f;
    double d;
    scanf ("%d %ld %c %f %lf", &i, &l, &c, &f, &d);
    printf ("%d \n%ld \n%c \n%2f \n%5lf", i, l, c, f, d); //\n- is printing in new line command, %2f- number 2 is number of decimals counted from 0
    return 0;
}