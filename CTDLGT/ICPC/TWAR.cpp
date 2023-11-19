#include <iostream>
#include <vector>
using namespace std;

struct TriangleMatrix
{
    int x;
    int y;
    bool check = false;
};

vector<TriangleMatrix> array;

void CreateTriangle()
{
    array.push_back(TriangleMatrix(1, 2, false));
    array.push_back(TriangleMatrix(1, 3, false));
    array.push_back(TriangleMatrix(2, 4, false));
    array.push_back(TriangleMatrix(3, 5, false));
    array.push_back(TriangleMatrix(3, 6, false));
    
}

int main()
{
    CreateTriangle();
    for (int i = 0; i < array.size(); i++)
    {
        cout << "x: " << array[i].x << ", y: " << array[i].y << ", check: " << array[i].check << endl;
    }
    return 0;
}
