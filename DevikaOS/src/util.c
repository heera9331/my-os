/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/util.h" 


// max memory size is 1000
static char memory[MAX_MEMORY_SIZE]; // Static array to simulate memory
static int next_free_index = 0; // Index to keep track of the next available memory location

void *memoryAllocate(int noOfBytes) {
    if (next_free_index + noOfBytes > MAX_MEMORY_SIZE) {
        // Memory allocation failed, return NULL
        return 0; // null
    }

    void *ptr = &memory[next_free_index]; // Pointer to the next available memory location
    next_free_index += noOfBytes; // Update the next available index
    return ptr;
}

void memoryCopy(const char *source, char *dest, int noOfBytes) {
    int i;
    for (i = 0; i < noOfBytes; i++) {
        dest[i] = source[i];
        // *(dest + i) = *(src + i);
    }
}

void memorySet(uint8 *dest, uint8 val, uint32 len) {
    uint8 *temp = (uint8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}



/**
 * K&R implementation
 */

string int_to_ascii(int n, string str) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /* TODO: implement "reverse" */
    return str;
}

string int_to_str(int n) {
    string ch = (void*)memoryAllocate(50);
    int_to_ascii(n,ch);
    int len = strLength(ch);
    int i = 0;
    int j = len - 1;
    while(i<(len/2 + len%2)) {
        char tmp = ch[i];
        ch[i] = ch[j];
        ch[j] = tmp;
        i++;
        j--;
    }
    return ch;
}

int str_to_int(string ch) {

    
    int n = 0;
    int p = 1;
    int strlen = strLength(ch);
    int i;
    for (i = strlen-1;i>=0;i--) {
        n += ((int)(ch[i] - '0')) * p;
        p *= 10;
    }
    return n;
}

