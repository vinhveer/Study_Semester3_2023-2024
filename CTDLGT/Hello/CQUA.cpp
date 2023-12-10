#include <stdio.h>

#define MAX 100

int Input(int count, int array[]) {
    for (int i = 0; i < count; i++)
        scanf("%d", &array[i]);
    return 0;
}

int CheckEqualWeights(int count, int appleArray[]) {
    int sumWeight = 0;
    int weight200 = 0;
    int weight100 = 0;
    
    for (int i = 0; i < count; i++) {
        sumWeight += appleArray[i];
        if (appleArray[i] == 200) {
            weight200++;
        } else {
            weight100++;
        }
    }

    if (sumWeight % 2 != 0 || weight100 % 2 != 0) {
        return 0;
    }

    if (weight200 % 2 == 0 || (weight200 > 0 && weight100 > 0)) {
        return 1;
    }

    return 0;
}

int main() {
    int count;
    int appleArray[MAX];

    // Đọc số lượng quả táo và trọng lượng của từng quả
    scanf("%d", &count);
    Input(count, appleArray);

    if (CheckEqualWeights(count, appleArray)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
