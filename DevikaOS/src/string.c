/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */


#include "include/string.h"

uint16 strLength(string str) {
    uint16 i=0;
    while(str[i++]);
    return i-1;
}

uint8 strEqual(string ch1,string ch2) {
    uint8 result = 1;
    uint8 size = strLength(ch1);
    if(size != strLength(ch2))
        result=0;
    else {
        uint8 i = 0;
        for(i;i<=size;i++) {
            if(ch1[i] != ch2[i])
                result = 0;
        }
    }
    return result;
}
