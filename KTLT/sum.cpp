#include <stdio.h>
#include <cstdlib>
#include <stdexcept>

// Ham tinh tong (su dung atof de chuyen ki tu sang kieu so thuc)
float Sum(int len, char *array[])
{
    float sum = 0;
    for (int i = 1; i < len; i++)
    {
        try
        {
            sum += atof(array[i]);
        }
        // Xu ly ngoai le khi chuyen doi that bai
        catch (const std::invalid_argument &e)
        {
            fprintf(stderr, "Loi chuyen doi chuoi thanh so thuc tai vi tri %d: %s\n", i, e.what());
            return 0;
        }
    }

    return sum;
}

int main(int argc, char *argv[])
{
    if (argc > 3 && argc < 10)
        printf("Sum: %.2f\n", Sum(argc, argv));
    else
        printf("Chi cong trong khoang tu 2 < n < 10! Hay thu lai!\n");

    return 0;
}