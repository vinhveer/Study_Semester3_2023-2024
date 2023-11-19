#include <iostream>
#include <cstdio>

using namespace std;

#define MTK "Leodoi.mtk1"
#define H "Leodoi.h1"
#define MAX 100 // so dinh toi da

// Khai bao bien
int sodinh;
int mtk[MAX][MAX];
int h[MAX];

FILE *fp;

void PrintMatrix(int mt[MAX][MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << mt[i][j] << " ";
        cout << endl;
    }
}

void PrintArray(int a[MAX], int size)
{
    for (int j = 0; j < size; j++)
        cout << a[j] << " ";
    cout << endl;
}

void ReadFile_MTK()
{
    fp = fopen(MTK, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "File MTK not found!\n");
        return;
    }

    fscanf(fp, "%d", &sodinh);
    for (int i = 0; i < sodinh; i++)
        for (int j = 0; j < sodinh; j++)
            fscanf(fp, "%d", &mtk[i][j]);

    fclose(fp);
    cout << "sodinh: " << sodinh << endl;
    PrintMatrix(mtk, sodinh);
}

void ReadFile_H()
{
    fp = fopen(H, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "File H not found!\n");
        return;
    }

    for (int i = 0; i < sodinh; i++)
        fscanf(fp, "%d", &h[i]);

    fclose(fp);
    cout << endl;
    PrintArray(h, sodinh);
}

void Hiking(int start, int goal)
{
    int n;
    int OPEN[MAX];
    int OPENED[MAX]; // Tập các đỉnh đã được đưa vào Open
    int CLOSE[MAX]; // Tập các đỉnh đã xét
    int CHA[MAX];
    int Tn[MAX]; // Tập các đỉnh tìm năng để đưa vào Open

    // Khởi tạo giá trị cho các mảng
    for (int i = 0; i < sodinh; i++)
    {
        OPENED[i] = i;
        CLOSE[i] = i;
        CHA[i] = -1;
    }
    int dem = 0; // Số lượng các phần tử còn lại trong open
    OPEN[dem++] = start; // Khởi tạo OPEN = start, OPEN[0] = start, dem = 1
    cout << "OPEN[]: ";
    PrintArray(OPEN, dem);
    n = OPEN[--dem];
    while (dem >= 0) // Còn phần tử trong OPEN
    {
        n = OPEN[--dem]; // dem = 0, n = OPEN[0]
        CLOSE[n] = -1;
        cout << "Dinh dang xet: " << n << endl;
        cout << "OPEN[]: ";
        PrintArray(OPEN, dem);

        if (n == goal)
        {
            cout << "Tim thay duong di tu " << start << " den " << goal << endl;
            //in duong di tu start den goal
            cout << "CHA[]: ";
            PrintArray(CHA, sodinh);

            int duongdi[MAX];
            int len = 0;
            for (int i = goal; i > 0; i = CHA[i])
            {
                duongdi[len++] = i;
            }

            printf("\nDuong di tu %d den %d: ", start, goal);
            for (int i = len--; i > 0; i--)
            {
                printf("%d -> ", duongdi[i]);
            }


            return;  //duongdi[9]
        }
        else
        {
            // Xet các đỉnh kề của n
            for (int i = 0; i < sodinh; i++)
            {
                if (mtk[n][i] == 1 && CLOSE[i] != -1 && OPENED[i] != 1)
                {
                    Tn[dem_Tn++] = i;
                    OPEN[i] = -1;
                    OPENED[i] = -1;
                    CHA[i] = n;
                }
            }
            cout << "Tn[] chua sap xep: " << endl;
            inmang(Tn, dem_Tn);

            for (int i = 0; i < dem_Tn -1; i++)
                for (int j = i + 1; j < dem_Tn; j++)
                {
                    if (h[Tn[i]] < h[Tn[j]])
                    {
                        int tam = Tn[i];
                        Tn[i] = Tn[j];
                        Tn[j] = tam;
                    }
                }

            // Chen cac gia tri của Tn vao OPEN
            for (int i = 0; i < dem_TN; i++)
                OPEN[dem++] = Tn[i];

            cout << "OPEN[] sau khi chen: " << endl;
            PrintArray(OPEN, dem);
        }
    }
    cout << "Khong tim thay duong di tu " << start << " den " << endl;
}

int main()
{
    ReadFile_MTK();
    ReadFile_H();
    Hiking(0, 7);
    return 0;
}
