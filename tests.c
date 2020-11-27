/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:53:28 by lflorrie          #+#    #+#             */
/*   Updated: 2020/11/27 13:03:26 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	start(const char *s)
{
	printf("--------START %s---------\n", s);
	printf("ft_printf	-	printf\n");
}

void	end(const char *s)
{
	printf("-------END %s------------\n", s);
}

void	teststr(const char *s)
{
	start(s);
	ft_printf("Without args");
	printf("	-	Without args\n");
	ft_printf("");
	printf("	-	\n");
	end(s);
}

void	testc(const char *s)
{
	start(s);
	ft_printf("%c", 'c');
	printf("	-	%c\n", 'c');
	ft_printf("%c", ' ');
	printf("	-	%c\n", ' ');
	
	ft_printf("%c%c%c%c%c", 'a', 'b', 'c', 'd', 'e');
	printf("	-	%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e');
	ft_printf("Hello, %ct's %c%c%c%c", 'i', 't', 'e','s','t');
	printf("	-	Hello, %ct's %c%c%c%c\n", 'i', 't', 'e', 's', 't');
	
	end(s);
}

void	testp(const char *s)
{
	start(s);
	int	a = 42;
	char	c = 'G';
	void	*pa = &a;
	void	*pc = &c;

	ft_printf("%p", pa);
	printf("	-	%p\n", pa);
	ft_printf("%p", pc);
	printf("	-	%p\n", pc);
	ft_printf("%p%p%p%p%p", pa, pc, pa, pc, pc);
	printf("	-	%p%p%p%p%p\n", pa, pc, pa, pc, pc);
	ft_printf("It is int : %p. It is char : %p", pa, pc);
	printf("	-	It is int : %p. It is char : %p\n", pa, pc);
	
	end(s);
}

void	testd(const char *s)
{
	start(s);
	ft_printf("%d", 42);
	printf("	-	%d\n", 42);
	ft_printf("%d", -42);
	printf("	-	%d\n", -42);
	ft_printf("%i", 0);
	printf("	-	%i\n", 0);
	ft_printf("%d%d%d%d%d", 0, 1, 2, 3, 4);
	printf("	-	%d%d%d%d%d\n", 0, 1, 2, 3 ,4);
	ft_printf("Abc %d def %i", 123, 456);
	printf("	-	Abc %d def %i\n", 123, 456);
	end(s);
}

void	tests(const char *s)
{
	start(s);
	ft_printf("%s", "Hello");
	printf("	-	%s\n", "Hello");
	ft_printf("%s", "");
	printf("	-	%s\n", "");
	ft_printf("%s%s%s", "Hi!", "Hi!", "Hi!");
	printf("	-	%s%s%s\n", "Hi!", "Hi!", "Hi!");
	ft_printf("Hi %s, print %s", "Username", "F");
	printf("	-	Hi %s, print %s\n", "Username", "F");
	
	end(s);
}
void	testpersent(const char *s)
{
	start(s);
	ft_printf("%%");
	printf("	-	%%\n");

	ft_printf("%%%%%%");
	printf("	-	%%%%%%\n");
	end(s);
}
void	testmix(const char *s)
{
	start(s);
	int a = 42;
	int *p = &a;
	ft_printf("%s %i %p", "Hello", a, p);
	printf("	-	%s %i %p\n", "Hello", a, p);
	
	end(s);
}

void	testwidth(const char *s)
{
	start(s);
	
	ft_printf(".%0d.", 42);
	printf("-.%0d.\n", 42);
	ft_printf(".%4d.", 42);
	printf("-.%4d.\n", 42);
	ft_printf(".%1d.", 42);
	printf("-.%1d.\n", 42);
	end(s);
}

void	testaccuracy(const char *s)
{
	start(s);
	ft_printf(".%7.5d.", 42);
	printf("-.%7.5d.\n", 42);
	ft_printf(".%4.4d.", 42);
	printf("-.%4.4d.\n", 42);
	ft_printf(".%1.3d.", 42);
	printf("-%1.3d.\n", 42);
	end(s);
}

void	testzerofill(const char *s)
{
	start(s);
	ft_printf(".%03d.", 42);
	printf("-.%03d.\n", 42);
	ft_printf(".%02d.", 42);
	printf("-.%02d.\n", 42);
	ft_printf(".%00d.", 42);
	printf("-%00d.\n", 42);
	end(s);
}

void	testminus(const char *s)
{
	start(s);
	ft_printf(".%-3d.", 42);
	printf("-.%-3d.\n", 42);
	ft_printf(".%-5d.", 42);
	printf("-.%-5d.\n", 42);
	ft_printf(".%-05d.", 42);
	printf("-.%-05d.\n", 42);
	end(s);
}

int	main(void)
{
	teststr("teststr");
	testc("testc");
	tests("tests");
	testp("testp");
	testd("testd");
	testpersent("test%");
	testmix("test1");
	printf("\n============================================================================\n");
	testwidth("testwidth");
	testaccuracy("testaccuracy");
	testzerofill("testzerofill");
	testminus("testminus");
	return (0);
}
