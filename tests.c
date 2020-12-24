/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:53:28 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/04 01:20:52 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <assert.h>

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
	//ft_printf(".%00d.", 42);
	//printf("-%00d.\n", 42);
	end(s);
}

void	testminus(const char *s)
{
	start(s);
	ft_printf(".%-3d.", 42);
	printf("-.%-3d.\n", 42);
	ft_printf(".%-5d.", 42);
	printf("-.%-5d.\n", 42);
	//ft_printf(".%-05d.", 42);
	//printf("-.%-05d.\n", 42);
	ft_printf(".%07d.", -52);
	printf("-.%07d.\n", -52);
	end(s);
}

void	testreturn(const char *s)
{
	start(s);
	int a = 12;
	int *p = &a;
	printf("CHAR\n");
	//assert(printf("") == ft_printf(""));
	assert(printf("%c", 'a') == ft_printf("%c", 'a'));
	assert(printf("Hello") == ft_printf("Hello"));
	assert(printf("%%") == ft_printf("%%"));
	//assert(printf(NULL) == ft_printf(NULL));
	assert(printf("%5c", 'g') == ft_printf("%5c", 'g'));
	assert(printf("%5.3c", 'g') == ft_printf("%5.3c", 'g'));
	assert(printf("a") == ft_printf("a"));
	printf("\nSTRING\n");
	assert(printf("Hello") == ft_printf("Hello"));
	assert(printf("%s", "Hello") == ft_printf("%s", "Hello"));
	assert(printf("%5s", "Hello") == ft_printf("%5s", "Hello"));
	assert(printf("%5.3s", "Hello") == ft_printf("%5.3s", "Hello"));
	assert(printf("%2.4s", "Hello") == ft_printf("%2.4s", "Hello"));
	printf("\nPOINTER\n");
	assert(printf("%p", p) == ft_printf("%p", p));
	assert(printf("%5p", p) == ft_printf("%5p", p));
	assert(printf("%5.1p", p) == ft_printf("%5.1p", p));
	assert(printf("%5.10p", p) == ft_printf("%5.10p", p));
	printf("\nINT\n");
	assert(printf("%d", 12) == ft_printf("%d", 12));
	assert(printf("%4d", 123) == ft_printf("%4d", 123));
	assert(printf("%1d", 123) == ft_printf("%1d", 123));
	assert(printf("%4.5d", 123) == ft_printf("%4.5d", 123));
	assert(printf("%4.0d", 123) == ft_printf("%4.0d", 123));
	assert(printf("%0.5d", 123) == ft_printf("%0.5d", 123));
	assert(printf("%0.5d", -123) == ft_printf("%0.5d", -123));
	assert(printf("%5.0d", -123) == ft_printf("%5.0d", -123));
	assert(printf("%5.6d", -123) == ft_printf("%5.6d", -123));
	printf("\nUINT\n");
	assert(printf("%u", 12) == ft_printf("%u", 12));
	assert(printf("%4u", 123) == ft_printf("%4u", 123));
	assert(printf("%1u", 123) == ft_printf("%1u", 123));
	assert(printf("%4.5u", 123) == ft_printf("%4.5u", 123));
	assert(printf("%4.0u", 123) == ft_printf("%4.0u", 123));
	assert(printf("%0.5u", 123) == ft_printf("%0.5u", 123));
	assert(printf("%0.5u", -123) == ft_printf("%0.5u", -123));
	assert(printf("%5.0u", -123) == ft_printf("%5.0u", -123));
	assert(printf("%5.6u", -123) == ft_printf("%5.6u", -123));
	printf("\nXINT\n");
	assert(printf("%x", 12) == ft_printf("%x", 12));
	assert(printf("%4x", 123) == ft_printf("%4x", 123));
	assert(printf("%1x", 123) == ft_printf("%1x", 123));
	assert(printf("%4.5x", 123) == ft_printf("%4.5x", 123));
	assert(printf("%4.0x", 123) == ft_printf("%4.0x", 123));
	assert(printf("%0.5x", 123) == ft_printf("%0.5x", 123));
	assert(printf("%0.5x", -123) == ft_printf("%0.5x", -123));
	assert(printf("%5.0x", -123) == ft_printf("%5.0x", -123));
	assert(printf("%5.6x", -123) == ft_printf("%5.6x", -123));
	end(s);
}

int	main(void)
{
	/*teststr("teststr");
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
	printf("\n================================================================================\n");
	*/
	testreturn("TESTRETURN");
	return (0);
}
