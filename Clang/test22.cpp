 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoa(char s[]) {
    int i, j, n;
    n = strlen(s);
    for (i = 0; i < n; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            for (j = i; j < n; j++) {
                s[j] = s[j + 1];
            }
            n--;
            i--;
        }
    }
    if (s[0] == ' ') {
        for (i = 0; i < n; i++) {
            s[i] = s[i + 1];
        }
        n--;
    }
    if (s[n - 1] == ' ') {
        s[n - 1] = '\0';
        n--;
    }
    for (i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    s[0] -= 32;
    for (i = 0; i < n; i++) {
        if (s[i] == ' ') {
            s[i + 1] -= 32;
        }
    }
}

int kiemTraDoiXung(char s[]) {
    int i, j, n;
    n = strlen(s);
    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

int tanSuatXuatHien(char s[], char k) {
    int i, n, count = 0;
    n = strlen(s);
    for (i = 0; i < n; i++) {
        if (s[i] == k) {
            count++;
        }
    }
    return count;
}

void sapXepChuCai(char s[]) {
    int i, j, n;
    char temp;
    n = strlen(s);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    char s[201], k;
    printf("Nhap chuoi s: ");
    fgets(s, 201, stdin);
    chuanHoa(s);
    printf("Chuoi sau khi chuan hoa: %s\n", s);
    if (kiemTraDoiXung(s)) {
        printf("Chuoi doi xung\n");
    } else {
        printf("Chuoi khong doi xung\n");
    }
    printf("Nhap ki tu k: ");
    scanf("%c", &k);
    if (tanSuatXuatHien(s, k)) {
        printf("Tan suat xuat hien cua ki tu %c la %d\n", k, tanSuatXuatHien(s, k));
    } else {
        printf("Ki tu %c khong xuat hien trong chuoi s\n", k);
    }
    sapXepChuCai(s);
    printf("Chuoi sau khi sap xep cac ki tu theo thu tu tang dan: %s\n", s);
    return 0;
}
