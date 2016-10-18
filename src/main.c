#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

void cs_toupper(char *str, size_t len)
{
	uint8_t i;

	for(i = 0; i < len; i++)
	{
		str[i] = (str[i] & '_');
	}
}

void encrypt(char *str, int shift, size_t len)
{
	cs_toupper(str, len);

	uint8_t i;

	for(i = 0; i < len; i++)
	{
		if((str[i] + shift) >= 65 && (str[i] + shift) <= 90)
		{
			str[i] += shift;
		}
		else
		{
			str[i] += (shift - ('Z' - 'A'));
		}
	}
}

void decrypt(char *str, int shift, size_t len)
{
	uint8_t i;

	for(i = 0; i < len; i++)
	{
		if((str[i] - shift) >= 65 && (str[i] - shift) <= 90)
		{
			str[i] -= shift;
		}
		else
		{
			str[i] -= (shift - ('Z' - 'A'));
		}
	}
}

void print_usage()
{

}

int main(int argc, char **argv)
{
	int copts, n_shift;
	char *str;

	while((copts = getopt(argc, argv, "m:n:s:")) != -1)
	{
		switch(copts)
		{
		case 'm':
			break;
		case 'n':
			n_shift = atoi(optarg);
			break;
		case 's':
			str = optarg;
			break;
		default:
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
