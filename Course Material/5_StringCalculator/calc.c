#include "calc.h"
#include<math.h>
int compute(char* str)
{
    if(str[1]=='+')
    {
        return (str[0]-48) + (str[2]-48);
    }
    else if(str[1]=='-')
    {
        return(str[0]-48) - (str[2]-48);
    }
    else if(str[1]=='*')
    {
        return(str[0]-48) * (str[2]-48);
    }
    else
    {
        if(str[2]-48==0)
        {
            return 0;
        }
        else
        {
            return (int)ceil ((double)(str[0]-48)/(str[2]-48));
        }
    }
}