#include "types.h"

#ifndef STRING_H
#define STRING_H


uint16 strlength(string ch)
{
        uint16 i = 1;
        while(ch[i++]);  
        return --i;
}


#endif
