#include <stdio.h>

void encrypt(char *str, int shift)
{
	while(*str++ != '\0')
	{
		if((*str + shift) >= 65 && (*str + shift) <= 90)
		{
			*str += shift;
		}
		else
		{
			*str += (shift - ('Z' - 'A'));
		}
	}
}

void decrypt(char *str, int shift)
{

}

void cs_toupper(char *str)
{
	while(*str++ != '\0')
	{
		*str = (*str & '_');
	}
}

int main()
{
	char test[] = "Teste\0";

	encrypt(test, 1);

	printf("%s\n", test);

	return 0;
}
