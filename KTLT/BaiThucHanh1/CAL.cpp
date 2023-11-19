#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 4)
        cout << "Sai cu phap. Cu phap dung la: CAL <tham so 1> <toan tu> <tham so 2> \n";
    else if (argv[2][0] == '+')
    {
        int thamso1 = atoi(argv[1]);
        int thamso2 = atoi(argv[3]);
        cout << thamso1 << " + " << thamso2 << " = " << thamso1 + thamso2 << endl;
    }
    else if (argv[2][0] == '-')
    {
        int thamso1 = atoi(argv[1]);
        int thamso2 = atoi(argv[3]);
        cout << thamso1 << " - " << thamso2 << " = " << thamso1 - thamso2 << endl;
    }
    else if (argv[2][0] == '*')
    {
        int thamso1 = atoi(argv[1]);
        int thamso2 = atoi(argv[3]);
        cout << thamso1 << " * " << thamso2 << " = " << thamso1 * thamso2 << endl;
    }
    else if (argv[2][0] == '/')
    {
        int thamso1 = atoi(argv[1]);
        int thamso2 = atoi(argv[3]);
        cout << thamso1 << " / " << thamso2 << " = " << thamso1 / thamso2 << endl;
    }

    return 0;
}