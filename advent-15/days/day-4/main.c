#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StringToChar(int value) {
    int length = snprintf(NULL, 0, "%d", value);
    char *new_str = malloc(length + 1);
    snprintf(new_str, length + 1, "%d", value);
    return new_str;
}

char *HashMD5(char *input) {
    // MD5 Creates 128-bit hash and null end.
    char *encoded = malloc((sizeof(int) * 16) + 1);

    return encoded;
}

bool CheckHash(char *hash) {
    int five_zeroes = 0;

    while ((*hash++) == '0') {
        five_zeroes++;
    }

    if (five_zeroes == 5) {
        return true;
    }

    return false;
}

int main() {
    int postfix = 0;
    bool valid_hash = false;

    // Place Secret key here
    char *key_val = "bgvyzdsv";
    //--------------------

    while (postfix < 500) {
        char *key = malloc(sizeof(char) * 50);
        strcpy(key, key_val);

        char *post_str = StringToChar(postfix);

        strcat(key, post_str);
        printf("%s\n", key);

        char *created_hash = HashMD5(key);
        valid_hash = CheckHash(created_hash);

        free(key);
        free(post_str);
        postfix++;
    }
}
