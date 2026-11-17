#include <string.h>

int longestValidParentheses(char* s) {
    int left = 0, right = 0, maxLength = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            int length = 2 * right;
            if (length > maxLength) maxLength = length;
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            int length = 2 * left;
            if (length > maxLength) maxLength = length;
        } else if (left > right) {
            left = right = 0;
        }
    }

    return maxLength;

}
