#include <stdio.h>
#include "staticlibexports.h"

int staticlib_third_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+1);
}

int staticlib_fourth_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+2);
}
