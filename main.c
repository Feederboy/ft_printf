#include "ft_printf.h"


int main()
{
/*
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	int count = 33;
	printf("Simple input test\n");
	printf("PR =%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d]\n", i, j, k, l, m, c, e, d); //T23
	ft_printf("FT =%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d]\n", i, j, k, l, m, c, e, d); //T23

	printf("\n\n");
	a = -4;
	while (a < 5)
{
	count++;
	printf("T = %d   a = %d\n", count, a);
	printf("PR =%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	ft_printf("FT =%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	count++;
	printf("T = %d   a = %d\n", count, a);
	printf("PR =%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	ft_printf("FT =%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	count++;
	printf("T = %d   a = %d\n", count, a);
	printf("PR =%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	ft_printf("FT =%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	count++;
	printf("T = %d   a = %d\n", count, a);
	printf("PR =%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	ft_printf("FT =%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d]\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	a++;
}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			count++;
			printf("T = %d   a = %d   b = %d   n = 1\n", count, a, b);
			printf("PR =%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			ft_printf("FT =%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);

			count++;
			printf("T = %d   a = %d   b = %d   n = 2\n", count, a, b);
			printf("PR =%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			ft_printf("FT =%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);

			count++;
			printf("T = %d   a = %d   b = %d   n = 3\n", count, a, b);
			printf("PR =%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			ft_printf("FT =%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);

			b++;
		}
		a++;
	}



	printf("\n\n\n TG \n\n\n");
	printf("[%1.d]\n", -12);
	ft_printf("[%1.d]\n", -12);
	printf("[%1.d]\n", 0);
	ft_printf("[%1.d]\n", 0);
	printf("[%d]\n", 0);
	ft_printf("[%d]\n", 0);
	printf("[%1.i]\n", 8);
	ft_printf("[%1.i]\n", 8);
	printf("[%1.i]\n", 0);
	ft_printf("[%1.i]\n", 0);
	printf("[%i]\n", 0);
	ft_printf("[%i]\n", 0);
	printf("[%1.u]\n", 0);
	ft_printf("[%1.u]\n", 0);
	printf("[%u]\n", 0);
	ft_printf("[%u]\n", 0);


	ft_printf("\n[%5.0i]   [%5.i]\n", 0, 0);
	printf("\n[%5.0i]   [%5.i]\n", 0, 0);

	printf("PR =[%*d]\n", -4, -12);
	ft_printf("PR =[%*d]\n", -4, -12);
	printf("PR =[%0*i]\n", -4, 8);
	ft_printf("FT =[%0*i]\n", -4, 8);
	printf("PR =[%.*d]\n", -4, 0);
	ft_printf("FT =[%.*d]\n", -4, 0);
	printf("PR =[%*d]\n", -4, 0);
	ft_printf("FT =[%*d]\n", -4, 0);
	printf("[%0-8.3x]\n", 8375);
	ft_printf("[%0-8.3x]\n", 8375);
	printf("\nPR =[%.*d]   %%.*d   1, 0\n", 1, 0);
	ft_printf("FT =[%.*d]   %%.*d  1, 0\n", 1, 0);
	printf("\nPR =[%.*d]   %%.*d  0, 0\n", 0, 0);
	ft_printf("FT =[%.*d]   %%.*d   0,0\n", 0, 0);
	printf("\nPR =[%*.*d]   %%*.*d  -2, 0, 0\n", -2, 0, 0);
	ft_printf("FT =[%*.*d]   %%*.*d   -2, 0, 0\n", -2, 0, 0);
	printf("\nPR =[%*.d]   %%*.d  -2, 0\n", -2, 0);
	ft_printf("FT =[%*.d]   %%*.d   -2, 0\n", -2, 0);
	printf("\nPR =[%*d]  %%*d  -2, 0\n", -2, 0);
	ft_printf("FT =[%*d]   %%*d  -2, 0\n", -2, 0); //si width != 0 et juste has_prec mais !prec alors afficher des width * spaces
	printf("\nPR =[%*.*d]   %%*.*d  -2, 5, 0\n", -2, 5, 0);
	ft_printf("FT =[%*.*d]   %%*.*d   -2, 5, 0\n", -2, 5, 0);
	printf("\nPR =[%*.*d]   %%*.*d  -2, 0, 5\n", -2, 0, 5);
	ft_printf("FT =[%*.*d]   %%*.*d   -2, 0, 5\n", -2, 0, 5);
	printf("\nPR =[%0*.*d]   %%0*.*d  0, 2, 8\n", 0, 2, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d   0, 2, 8\n", 0, 2, 8);
	printf("\nPR =[%0.*d]   %%0.*d   2, 8\n", 2, 8);
	ft_printf("FT =[%0.*d]   %%0.*d    2, 8\n", 2, 8);
	printf("\nPR =[%0*.d]   %%0*.d  2, 8\n",  2, 8);
	ft_printf("FT =[%0*.d]   %%0*.d   2, 8\n",  2, 8);
	printf("\nPR =[%0*.*d]   %%0*.*d  2, 4, 8\n", 2, 4, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d   2, 4, 8\n", 2, 4, 8);
	printf("\nPR =[%0*.*d]   %%0*.*d  4, 2, 8\n", 4, 2, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d   4, 2, 8\n", 4, 2, 8);
	//les exemples du dessus exprimemt bien le pb : si width > prec alors espaces puis 0, si prec > width que des 0

	printf("\nPR =[%*.d]   %%*.d  -2, 0\n", -2, 0);      //probleme de conflit entre ces 2 exemples
	ft_printf("FT =[%*.d]   %%*.d   -2, 0\n", -2, 0); //a corriger dans la fct de check ligne 911

	printf("\nPR =[%*.*d]   %%*.*d  -2, 0, 5\n", -2, 0, 5);
	ft_printf("FT =[%*.*d]   %%*.*d   -2, 0, 5\n", -2, 0, 5);

	printf("\nPR =[%0*.*d]   %%0*.*d  0, 2, 8\n", 0, 2, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d   0, 2, 8\n", 0, 2, 8);

	printf("\nPR =[%0*.*d]   %%0*.*d  2, -5, 8\n", 2, -5, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d  2, -5, 8\n", 2, -5, 8);

	printf("\nPR =[%0*.*d]   %%0*.*d  2, 2, 8\n", 2, 2, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d  2, 2, 8\n", 2, 2, 8);

	printf("\nPR =[%0*.*d]   %%0*.*d  2, 5, 8\n", 2, 5, 8);
	ft_printf("FT =[%0*.*d]   %%0*.*d  2, 5, 8\n", 2, 5, 8);
	printf("\n\n\n");
		
	a = -4;
	while (a < 5)
{
	printf("\n");
	printf("PR =%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s    a = %d\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u, a);
	ft_printf("FT =%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s    a = %d\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u, a);
	a++;
}


	printf("\n\n\n");



	printf("\n\n\n");

	a = -1;

	while (a < 5)
{
	printf("PR =%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
	

	ft_printf("FT =%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);

	a++;
	printf("\n\n-------------------------------------\n\n\n");
}

	printf("PR =%*u\n", a, j);
	ft_printf("FT =%*u\n", a, j);
	printf("a = %d     j = %d\n", a, j);



	a = -1;
	while (a < 5)
{


	printf("PR =%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

	printf("FT =%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

	a++;
	printf("\n\n-------------------------------------\n\n\n");


}

	printf("PR =%*.*u, %*.*x, %*.*X,\n", -1, 0, a, -1, 0, b, -1, 0, l);
	printf("FT =%*.*u, %*.*x, %*.*X,\n", -1, 0, a, -1, 0, b, -1, 0, l);




	printf("\n\n-------------------------------------\n\n\n");

	a = -1;
	while(a < 5) //T257-346
	{
		b = -1;
		while (b < 5)
		{
			printf("a = %d     b = %d\n", a, b);

			printf("PR =%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

			ft_printf("FT =%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);


			printf("\n************************************************************************\n");

			printf("PR =%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

			ft_printf("FT =%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

			printf("\n************************************************************************\n");

			printf("PR =%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

			ft_printf("FT =%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

			printf("\n{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{\n");
			b++;
		}
		a++;
	}

*/
	printf("\n\n-------------------------------------\n\n\n");

	printf("PR =[%*.*u], [%*.*x], [%*.*X], [%*.*d]\n", -1, 0, l, -1, 0, l, -1, 0, l, -1, 0, l);
	ft_printf("FT =[%*.*u], [%*.*x], [%*.*X], [%*.*d]\n", -1, 0, l, -1, 0, l, -1, 0, l, -1, 0, l);











	return (0);
}
