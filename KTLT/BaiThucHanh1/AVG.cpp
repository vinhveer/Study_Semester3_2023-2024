#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    float sum = 0;
    for (int i = 1 ; i < argc; i++)
    {
        float temp = atoi(argv[i]);
        sum += temp;
    }

    printf("Average of Array: %.3f\n", sum / (argc - 1));

    return 0;
}