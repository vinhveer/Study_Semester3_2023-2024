#include <bits/stdc++.h>
using namespace std;
int const p = 5;
// so luong tien trinh
int const r = 3;
// so loai tai nguyen
// p la hang r la cot
void calculatedNeed(int max[p][r], int all[p][r], int need[p][r])
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
}
// tham so la input dau vao
bool check(int av[], int max[][r], int all[][r])
{
    int need[p][r];
    calculatedNeed(max, all, need);
    bool finished[p] = {0}; // de danh dau cac tien trinh da duoc duyet qua chua
    // tao 1 cai mang de luu tien trinh an toan
    int safe[p] = {0}, cnt = 0;
    int work[r] = {0};
    for (int i = 0; i < r; i++)
    {
        work[i] = av[i];
    }
    while (cnt < p)
    {
        bool check1 = false;
        // duyet qua tung tien trinh
        for (int i = 0; i < p; i++)
        {
            if (finished[i] == 0)
            {
                // tuc la no chua duoc duyet qua thi minh duyet tung hang need cua no
                int j;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == r)
                {
                    // tuc la no da duyet qua cac hang cua thang need r
                    for (int k = 0; k < r; k++)
                        work[k] += all[i][k];
                    finished[i] = true;
                    safe[cnt++] = i;
                    check1 = true;
                }
            }
        }
        // sau khi vong for nay ket thuc
        if (check1 == false)
        {
            cout << "He thong khong an toan";
            return false;
        }
    }
    cout << "he thong an toan ";
    for (int i = 0; i < p; i++)
    {
        cout << safe[i] << " ";
    }
    return true;
}
int main()
{
    int pc[] = {0, 1, 2, 3, 4};

    int av[] = {3, 3, 2};

    int max[][r] = {{7, 5, 3},
                    {3, 2, 2},
                    {9, 0, 2},
                    {2, 2, 2},
                    {4, 3, 3}};

    int all[][r] = {{0, 1, 0},
                    {2, 0, 0},
                    {3, 0, 2},
                    {2, 1, 1},
                    {0, 0, 2}};

    check(av, max, all);
    return 0;
}