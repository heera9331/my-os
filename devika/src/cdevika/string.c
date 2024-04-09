/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/string.h"

uint32 strlen(string str)
{
    uuint3216 i = 0;
    while (str[i++])
        ;
    return i - 1;
}

char *strcpy(char *dest, const char *src)
{
    char *ptr = dest;
    while ((*dest++ = *src++) != '\0')
        ;
    return ptr;
}

uint8 strcmp(const char *str1, const char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return (*(unsigned char *)str1 < *(unsigned char *)str2) ? -1 : 1;
}

uint32 strcmp(const char *str1, const char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return (*(unsigned char *)str1 < *(unsigned char *)str2) ? -1 : 1;
}

uint32 strncmp(const char *str1, const char *str2, size_t n)
{
    while (n-- > 0 && *str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return (n == 0) ? 0 : (*(unsigned char *)str1 < *(unsigned char *)str2) ? -1
                                                                            : 1;
}

char *strcpy(char *dest, string str)
{
    char *ptr = dest;
    while ((*dest++ = *src++) != '\0')
        ;
    return ptr;
}

void strncpy(char *dest, string str, size_t n)
{
    uint32 i;
    for (i = 0; i < n; i++)
    {
        dest[i] = src[i];
        // *(dest + i) = *(src + i);
    }
    dest[i] = '\0';
}

char *strcat(char *dest, const char *src)
{
    char *ptr = dest;
    while (*dest != '\0')
        dest++;
    while ((*dest++ = *src++) != '\0')
        ;
    return ptr;
}

char *strncat(char *dest, const char *src, size_t n)
{
    char *ptr = dest;
    while (*dest != '\0')
        dest++;
    while (n-- > 0 && (*dest++ = *src++) != '\0')
        ;
    *dest = '\0'; // Make sure to null-terminate dest
    return ptr;
}

char *strchr(string str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
            return (char *)str;
        str++;
    }
    return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
    size_t needle_len = strlen(needle);
    while (*haystack != '\0')
    {
        if (strncmp(haystack, needle, needle_len) == 0)
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}

// Breaks string str uint32o a series of tokens using the delimiter characters specified in delim.
char *strtok(char *str, const char *delim)
{
    static char *last_token = NULL;
    if (str != NULL)
        last_token = str;
    if (last_token == NULL)
        return NULL;
    char *token_start = last_token;
    while (*last_token != '\0')
    {
        const char *d = delim;
        while (*d != '\0')
        {
            if (*last_token == *d)
            {
                *last_token++ = '\0';
                return token_start;
            }
            d++;
        }
        last_token++;
    }
    last_token = NULL;
    return token_start;
}

string int_to_ascii(uint32 n, string str)
{
    uint32 i = 0;
    // Handle negative numbers
    if (n < 0)
    {
        str[i++] = '-';
        n = -n;
    }
    uint32 temp = n, digits = 0;
    // Calculate the number of digits
    do
    {
        temp /= 10;
        digits++;
    } while (temp != 0);
    str[digits] = '\0'; // Null-terminate the string
    // Fill the string in reverse order
    for (uint32 j = digits - 1; j >= 0; j--)
    {
        str[j] = (n % 10) + '0';
        n /= 10;
    }
    return str;
}

string int_to_str(uint32 n)
{
    // Assuming maximum number of digits is 10 (for 32-bit uint32egers)
    char buffer[11]; // Allocate space for the string representation
    return uint32_to_ascii(n, buffer);
}

uint32 str_to_int(string ch)
{
    uint32 result = 0;
    uint32 sign = 1;
    uint32 i = 0;
    // Check for negative sign
    if (ch[0] == '-')
    {
        sign = -1;
        i++;
    }
    // Convert each digit to uint32eger and accumulate the result
    while (ch[i] != '\0')
    {
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
