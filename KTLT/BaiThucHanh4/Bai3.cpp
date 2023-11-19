#include <iostream>
#include <fstream>

const int MAX_N = 30;
int tien[MAX_N];
int sol[MAX_N];
int sol_count = 0;

void rutTien(int n, int s, int vitri)
{
    if (s == 0)
    {
        // In ra cách trả tiền
        for (int i = 0; i < vitri; ++i)
        {
            std::cout << sol[i] << " ";
        }
        std::cout << std::endl;
        ++sol_count;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (s >= tien[i])
        {
            sol[vitri] = tien[i];
            rutTien(n, s - tien[i], vitri + 1);
        }
    }
}

int main()
{
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Khong the mo file input.txt" << std::endl;
        return 1;
    }

    int n, s;
    inputFile >> n >> s;

    // Nhập giá trị của các tờ tiền
    for (int i = 0; i < n; ++i)
    {
        inputFile >> tien[i];
    }

    inputFile.close();

    // Gọi hàm quay lui để tìm cách rút tiền
    rutTien(n, s, 0);

    // Kiểm tra xem có cách trả tiền hay không
    if (sol_count == 0)
    {
        std::cout << -1 << std::endl;
    }

    return 0;
}
