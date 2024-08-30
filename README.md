# PROPOSALS

This document and source code contain my proposal(s) and examples for a change in the C language.

The conditional while (first proposal) is what I'm serious about. It is an update to an existing feature (while) but shouldn't break any existing code base.

The ifwhile (second proposal) is an addition to the first one and is a whole new feature. After writing the example files I wasn't so fond of this feature myself anymore. But I included it as well. Maybe you find it interesting.

The source code contains a Makefile that can be executed to run all (traditional) examples by just executing `make`.

## Conditional while

The conditional while is the traditional while that only returns a bool if ran at least once.

### Usage
```
/*
    Returns a part containing only one format from the input parameter.
    E.g: abc123 translates to abc. 123abc translates to 123.
*/
bool lex(char * value, char * output){
    if(while(isalpha(*value)){
        // Process alpha lexing
        // update output with valid content
    }) else if(while(isdigit(*value)){
        // Process number lexing
        // update output with valid content
    }) else {
        return false;
    }
    return true;
}
```
This is what I required for my interpreter. 
Without the conditional while you have to check twice for isalpha or isdigit.
Also, you'll have an extra nesting:
```
bool lex(char * value, char * output){
    if(isalpha(*value)){
        while(isalpha(*value)){
            // Process alpha lexing
            // update output with valid content
        }
        return true;
    }else if(isdigit(*value)){
        while(isdigit(*value)){
            // Process number lexing
            // update output with valid content
        }
        return true;
    }
    return false;
}

```
and setting the `is_alpha` many times or I had to do a special check before it.
I'm quite positive about this example. Also, I expect existing source code not to break because of this.

### Example files:
 - example3_new.c
 - example3_traditional.c

## Ifwhile

The ifwhile is a while that gets executed like an if. Difference with the conditional while is that it executes the code behind it if it's true under the same rules as an if statement. 

### Usage
```
/*
    Returns a part containing only one format from the input parameter.
    E.g: abc123 translates to abc. 123abc translates to 123.
*/
bool lex(char * value, char * output){
    ifwhile(isalpha(*value)){
        // Process alpha lexing
        // update output with valid content
    }else ifwhile(isdigit(*value)){
        // Process number lexing
        // update output with valid content
    } else {
        return false;
    }
    return true;
}
```

## Example files:
 - example1_new.c
 - example1_traditional.c
 - example2_new.c
 - example2_traditional.c

# Summary sources
```
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C                                6              0              6            291
-------------------------------------------------------------------------------
SUM:                             6              0              6            291
-------------------------------------------------------------------------------
```