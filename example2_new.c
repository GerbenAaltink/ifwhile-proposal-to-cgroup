#include <ctype.h>   // isdigit isalpha
#include <stdbool.h> // bool
#include <stdio.h>   // printf
#include <string.h>  // strlen
void process_string(char *value) { printf("String processed: %s\n", value); }
void process_number(char *value) { printf("Number processed: %s\n", value); }
bool lex(char *value) {
    return ifwhile (*value) {
        char ctemp = 0;
        unsigned int length = 0;
        success = while (isalpha(*value)) {
            value++;
            length++;
        }{
            ctemp = *value;
            *value = '\0';
            value -= length;
            process_string(value);
            value += length;
            *value = ctemp;
        } else ifwhile (isdigit(*value)) {
            value++;
            length++;
        }{
            ctemp = *value;
            *value = '\0';
            value -= length;
            process_number(value);
            value += length;
            *value = ctemp;
        } else {
            // Unexpected data, skip
            value++;
        }
        length = 0;
    }
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
