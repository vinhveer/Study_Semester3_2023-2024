#include <iostream>
using namespace std;

int x[100];
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == k)
            Print();
        else
            Try(i + 1);
    }
}