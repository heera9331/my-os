/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/string.h" 

uint32 str_len(string str) {
    uint16 i=0;
    while(str[i++]);
    return i-1;
}

uint8 str_equal(string ch1,string ch2) {
    uint8 result = 1;
    uint8 size = str_len(ch1);
    if(size != str_len(ch2))
        result=0;
    else {
        ;
        for(uint8 i=0; i<=size; i++) {
            if(ch1[i] != ch2[i])
                result=0;
        }
    }
    return result;
}

string int_to_ascii(int n, string str) {
    int i = 0;
    // Handle negative numbers
    if (n < 0) {
        str[i++] = '-';
        n = -n;
    }
    int temp = n, digits = 0;
    // Calculate the number of digits
    do {
        temp /= 10;
        digits++;
    } while (temp != 0);
    str[digits] = '\0'; // Null-terminate the string
    // Fill the string in reverse order
    for (int j = digits - 1; j >= 0; j--) {
        str[j] = (n % 10) + '0';
        n /= 10;
    }
    return str;
}

string int_to_str(int n) {
    // Assuming maximum number of digits is 10 (for 32-bit integers)
    char buffer[11]; // Allocate space for the string representation
    return int_to_ascii(n, buffer);
}

int str_to_int(string ch) {
    int result = 0;
    int sign = 1;
    int i = 0;
    // Check for negative sign
    if (ch[0] == '-') {
        sign = -1;
        i++;
    }
    // Convert each digit to integer and accumulate the result
    while (ch[i] != '\0') {
        result = result * 10 + (ch[i] - '0');
        i++;
    }
    return result * sign;
}

/**
 * @desc src => source and dest => destination
 * @param src
 * @param dest
 */

void str_cpy(string src, string dest, int noOfBytes) {
    int i;
    for (i = 0; i < noOfBytes; i++) {
        dest[i] = src[i];
        // *(dest + i) = *(src + i);
    }
    dest[i] = '\0';
}