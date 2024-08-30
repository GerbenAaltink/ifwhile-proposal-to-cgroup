#include <ctype.h>   // isdigit isalpha
#include <stdbool.h> // bool
#include <stdio.h>   // printf
#include <string.h>  // strlen
void process_string(char *value) { printf("String processed: %s\n", value); }
void process_number(char *value) { printf("Number processed: %s\n", value); }
bool lex(const char *value) {
    return while (*value) {
        const unsigned int temp_length = 1984;
        char temp[temp_length];
        char *tptr = temp;
        unsigned int length = 0;
        bool is_string = while (isalpha(*value)) {
            *tptr = *value;
            tptr++;
            value++;
            length++;
        }
        if(is_string){
            *temp = '\0';
            tptr -= length;
            process_string(tptr);
            continue;
        }
        bool is_number = while (isdigit(*value)) {
            *temp = *value;
            temp++;
            value++;
            length++;
        }
        if(is_number)
        {
            *tptr = '\0';
            tptr -= length;
            process_number(tptr);
            continue;
        } 
        // Unexpected data, skip
        value++;
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
