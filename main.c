
#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

int main()
{
	int a = 0;
	int b = 0;
	FILE *fp;
	int i_1 = 0;
	int i_2 = 0;
	//Удалить сначала то что было в файле
	fp = fopen("test.txt", "r");
	while (fscanf(fp, "%d %d", &a, &i_1) != EOF)
	{
		fscanf(fp, "%d %d", &b, &i_2);
		while (i_1 != i_2)
		{
			//printf("NO OUTPUT in one of the functions. Test %i. Got %i\n", i_1, a);
			i_1 = i_2;
			a = b;
			fscanf(fp, "%d %d", &b, &i_2);
		}
		if (a != b)
			printf("ERROR in test %i. Actual %i. Expected %i\n", i_1, a, b);
	}
	/*int n1 = 3;
	int n2 = 3;
	ft_printf("   %u    %li    %s    %X    %n  \n",2,(long)-30,"2",4,&n1);
	   printf("   %u    %li    %s    %X    %n  \n",2,(long)-30,"2",4,&n2);
	   printf("%i %i", n1, n2);*/
	return (0);
}
