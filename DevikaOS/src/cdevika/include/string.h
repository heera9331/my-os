

#include "types.h"

/**
 * @desc return length of string
 * @return void
*/

uint32 str_len(string);

/**
 * @desc - str comparison, return 1 if both strings are equal else 0
 *
 * @return int
*/
uint8 str_equal(string str1, string str2);

void str_cpy(string, string, int32);
string int_to_ascii(int n, string str);
string int_to_str(int n);
int str_to_int(string ch);