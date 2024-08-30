#include <ctype.h>   // isdigit isalpha
#include <stdbool.h> // bool
#include <stdio.h>   // printf
#include <string.h>  // strlen
void process_string(char *value) { printf("String processed: %s\n", value); }
void process_number(char *value) { printf("Number processed: %s\n", value); }
bool lex(const char *value) {
    bool success = false;
    while (*value) {
        const unsigned int temp_length = 42;
        char temp[temp_length];
        char *tptr = temp;
        unsigned int length = 0;
        if (isalpha(*value)) {
            while (isalpha(*value)) {
                *tptr = *value;
                tptr++;
                value++;
                length++;
            }
            *tptr = '\0';
            tptr -= length;
            process_string(tptr);
            continue;
        } else if (isdigit(*value)) {
            while (isdigit(*value)) {
                *tptr = *value;
                tptr++;
                value++;
                length++;
            }
            *tptr = '\0';
            tptr -= length;
            process_number(tptr);
            continue;
        }
        // Unexpected data, skip
        value++;
        success = true;
    }
    return success;
}
int main() {
    char value[] = "1337*cat+42-dog_1984/pony";
    if (lex(value)) {
        printf("Lex result: %s\n", "success!");
    } else {
        printf("Lex result: %s\n", "failure!");
    }
    return 0;
}
