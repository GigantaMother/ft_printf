#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int main()
{
    //test();
    //-----
    int ret_my = 0;
    int ret_or = 0;
    //-----------
    char c;
    char *s = "AlexAlex";
    int  d = 0;                  // -2147483648    2147483647
    int  i = 50;          // -2147483648    2147483647
    unsigned int u = 500; // 4294967295
    unsigned int x = 10;       // 4294967295
    unsigned int X = 110;       // 4294967295

    c = 'a';
    s = "AlexAlex";
    d = 42;
    i = -404;
    u = 1235;
    x = 505;
    X = 178;
	// "%*.*i", -1, 0, 0
	//char *p = s;
	
    ret_my = ft_printf("%d");
	
    printf("\n");
    ret_or =    printf("%d");  // "%---2d", 5
    printf("\n%d|%d\n", ret_my, ret_or);
    printf("------------------------\n");
    return (0);
}

/*
// "%%Hello %c %s %d %i %u %x %X || ", c, s, d, i, u, x, X
// "%c %s %d %u %x %X|", c, s, d, u, x ,X
// "%5c%5s%5d%5u%5x%5X|", c, s, d, u, x ,X
// "%-5c%-5s%-5d%-5u%-5x%-5X|", c, s, d, u, x ,X
// "%5d%5u%5x%5X|", d, u, x ,X
// "%05d%05u%05x%05X|", d, u, x ,X
// "%.4d %.4u %.4x %.4X|", d, u, x ,X
// "%d|%5d|%-d|%-5d|%0d|%00d|%05d|%.d|%.5d|", d, d, d, d, d, d, d, d, d
        printf("\nNO GOOD FLAGS\n");
        printf("spec.empty= %d\n", spec->empty);
        printf("spec.minus= %d\n", spec->minus);
        printf("spec.zero= %d\n", spec->zero);
        printf("spec.accur= %d\n", spec->accur);
*/