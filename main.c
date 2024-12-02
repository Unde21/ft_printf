#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a = 0;
	int b = 0;
	//void	*ptr = &a;
	// char s[] = "hello world";
	 a = 0; //= ft_printf("%.7s%.2s", "hello", "world");
	printf("\n");
	b = 0; //= printf("%.7s%.2s", "hello", "world");
	printf("\n a : %d  b : %d\n", a, b);
	a = ft_printf("{%1.0s}" , " SA VA PASSER");
	printf("\n");
	b = printf("{%1.0s}" , " SA VA PASSER");
	printf("\n");
	printf("\n a %d   b %d\n", a, b);
	a = ft_printf("aldadlalda %12.10d  : %-.10u :%.10s :%p :%-#20.6x ", 42, -454, "Hello", "Hello", 255);
	printf("\n");
	b = printf("aldadlalda %12.10d  : %-.10u :%.10s :%p :%-#20.6x ", 42, -454, "Hello", "Hello", 255);
	printf("\n");
	ft_printf(0);
	// a = ft_printf("{%.s || %p}" , "test", ptr);
	// printf("\n");
	// b = printf("{%.s || %p}" , "test", ptr);
	// printf("\n");
	// printf("\n a %d   b %d\n", a, b);
	// printf("\n");
	// a = ft_printf("%7.5s", "tubular");
	// printf("\n");
	// b = printf("%7.5s", "tubular");
	//ft_printf(-1);
}
