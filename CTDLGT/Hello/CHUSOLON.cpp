#include <stdio.h>

int isValidParentheses(char *s) {
    int balance = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            balance--;
            if (balance < 0) {
                return 0;  // Dãy ngoặc không hợp lệ
            }
        }
    }
    return balance == 0;  // Nếu balance bằng 0, dãy ngoặc hợp lệ
}

int main() {
    char input[101];
    scanf("%s", input);

    if (isValidParentheses(input)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}