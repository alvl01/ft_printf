#include "ft_printf.h"
#include <stdio.h>
int main()
{
  if(printf("ok%c\n", 'a') == ft_printf("ok%c\n", 'a'))
    printf("ok\n");
}
