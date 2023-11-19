#include <iostream>
#include <cstdio>  // Include this header for FILE and fprintf
using namespace std;

void FileInput(FILE *f) {
    int n;
    cout << "N = ";
    cin >> n;
    fprintf(f, "%d", n);
}

int main() {
    string s = "file.txt";
    FILE* fp = fopen(s.c_str(), "w+"); // Use c_str() to get a C-style string
    if (fp == NULL) // Use == for comparison
        cout << "Khong mo duoc tap tin!";
    else
        FileInput(fp);
    fclose(fp);
    return 0;
}
