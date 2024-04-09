

#include "types.h" 
#include "stddef.h" 

// string => const char *ptr
char *strcpy(char *dest, string str);
char *strncpy(char *dest, string str, size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strchr(string str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);
uint32 strlen(string str);

string int_to_ascii(int n, string str);
string int_to_str(int n);
int str_to_int(string ch);