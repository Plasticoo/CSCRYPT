#include <stdio.h>

void encrypt()
{

}

void decrypt()
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
	char test[] = "Test";

	cs_toupper(test);

	printf("%s\n", test);

	return 0;
}
