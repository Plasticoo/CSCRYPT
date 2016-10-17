#include <stdio.h>
#include <inttypes.h>
#include <string.h>

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

void decrypt(char *str, int shift)
{

}

int main()
{
	char test[] = "Teste";

	encrypt(test, 12, strlen(test));

	printf("%s\n", test);

	return 0;
}
