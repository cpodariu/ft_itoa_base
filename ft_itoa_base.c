#include <stdlib.h>

char get_ascii(int c)
{
	if (c < 0)
		c = -c;
	if (c <= 9)
		return (c + '0');
	return (c - 10 + 'A');
}

char *ft_itoa_base(int value, int base)
{
	int i;
	char *k;
	int sign;

	k = (char*)malloc(sizeof(char) * 34);
	sign = 1;
	if (value < 0)
		sign = -1;
	if (value == 0)
	{
		k[0] = '0';
		k[1] = 0;
		return k;
	}
	k[33] = 0;
	i = 32;
	while(value)
	{
		k[i] = get_ascii(value % base);
		value = value / base;
		i--;
	}
	if (sign == -1 && base == 10)
		k[i] = '-';
	else
		i++;
	k += i;
	return k;
}
