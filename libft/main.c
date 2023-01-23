/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:06 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/11 09:01:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>

int	main (void)
{
	printf("\n");
	printf("ft_isalpha :\n");
	printf("%d\n", ft_isalpha ('a'));
	printf("%d\n", isalpha ('a'));
	printf("%d\n", ft_isalpha ('5'));
	printf("%d\n", isalpha ('5'));
	printf("\n");

	printf("ft_isdigit :\n");
	printf("%d\n", ft_isdigit ('5'));
	printf("%d\n", isdigit ('5'));
	printf("%d\n", ft_isdigit ('a'));
	printf("%d\n", isdigit ('a'));
	printf("\n");	

	printf("ft_isalnum :\n");
	printf("%d\n", ft_isalnum ('5'));
	printf("%d\n", isalnum ('5'));
	printf("%d\n", ft_isalnum ('@'));
	printf("%d\n", isalnum ('@'));
	printf("\n");

	printf("ft_isascii :\n");
	printf("%d\n", ft_isascii (5));
	printf("%d\n", isascii (5));
	printf("%d\n", ft_isascii(129));
	printf("%d\n", isascii (129));
	printf("\n");

	printf("ft_isprint :\n");
	printf("%d\n", ft_isprint (34));
	printf("%d\n", isprint (34));
	printf("%d\n", ft_isprint (2));
	printf("%d\n", isprint (2));
	printf("\n");

	char	a1[50] = "Mael";
	char	a2[50] = "Bonjour 42 !";
	printf("ft_strlen :\n");
	printf("%s\n", a1);
	printf("%ld\n", ft_strlen(a1));
	printf("%s\n", a2);
	printf("%ld\n", strlen(a2));
	printf("\n");

	char	b1[50] = "Bonjour 42 !";
	char	b2[50] = "Bonjour 42 !";
	printf("ft_memset :\n");
	printf("%s\n", b1);
	printf("%s\n", (char *)ft_memset(b1, 'y', 12));
	printf("%s\n", b2);
	printf("%s\n", (char *)memset(b2, 't', 12));
	printf("\n");
	

	char	c1[50] = "Bonjour 42 !";
	char	c2[50] = "Bonjour 42 !";
	printf("ft_bzero :\n");
	printf("%s\n", c1);
	ft_bzero(c1, 5);
	printf("%s\n", c1);
	printf("%s\n", c2);
	bzero(c2, 5);
	printf("%s\n", c2);
	printf("\n");

	char	src1[50] = "Bon";
	char	dest1[50] = "Lonjour";
	char	src2[50] = "Bon";
	char	dest2[50] = "Lonjour";
	printf("ft_memcpy :\n");
	printf("%s\n", src1);
	printf("%s\n", dest1);	printf("%d\n", ft_toupper('a'));
	printf("%d\n", toupper('a'));
	printf("%s\n", (char *)ft_memcpy(dest1, src1, 3));
	printf("%s\n", src2);
	printf("%s\n", dest2);
	printf("%s\n", (char *)memcpy(dest2, src2, 3));
	printf("\n");

	char	src3[50] = "Bon";
	char	dest3[50] = "Lonjour";
	char	src4[50] = "Bon";
	char	dest4[50] = "Lonjour";
	char	src5[50] = "Attention aux poules !";
	char	*dest5 = (src5 +2);
	char	src6[50] = "Les poules c'est la vie";
	char	*dest6 = (src6 +2);
	printf("ft_memmove :\n");
	printf("%s\n", src3);
	printf("%s\n", dest3);
	printf("%s\n", (char *)ft_memmove(dest3, src3, 3));
	printf("%s\n", src4);
	printf("%s\n", dest4);
	printf("%s\n", (char *)memmove(dest4, src4, 3));
	printf("%s\n", src5);
	printf("%s\n", (char *)ft_memmove(dest5, src5, 23));
	printf("%s\n", src6);
	printf("%s\n", (char *)memmove(dest6, src6, 23));
	printf("\n");

	char	src7[50] = "Bonjour";
	char	dest7[50] = "Lon";
	printf("ft_strlcpy :\n");
	printf("%s\n", src7);
	printf("%s\n", dest7);
	printf("%ld\n", ft_strlcpy(dest7, src7, 6));
	printf("%s\n", dest7);
	printf("\n");
	
	char	src8[50] = "Mael";
	char	dest8[50] = "Bonjour ";
	printf("ft_strlcat :\n");
	printf("%s\n", src8);
	printf("%s\n", dest8);
	printf("%ld\n", ft_strlcat(dest8, src8, 15));
	printf("%s\n", dest8);
	printf("\n");

	printf("ft_toupper :\n");
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", toupper('a'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", toupper('a'));
	printf("\n");

	printf("ft_tolower :\n");
	printf("%d\n", ft_tolower('A'));
	printf("%d\n", tolower('A'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", tolower('A'));
	printf("\n");

	char	d1[50] = "Bonjour Mael & Eden Pauline";
	char	d2[50] = "Bonjour Mael & Eden Pauline";
	printf("ft_strchr :\n");
	printf("%s\n", ft_strchr(d1, '\0'));
	printf("%s\n", strchr(d2, '\0'));
	printf("%s\n", ft_strchr(d1, 'M'));
	printf("%s\n", strchr(d2, 'M'));
	printf("\n");

	char	e1[50] = "ZBonjour Mael & Eden & Pauline & Nina";
	char	e2[50] = "ZBonjour Mael & Eden & Pauline & Nina";
	printf("ft_strrchr :\n");\
	printf("%s\n", ft_strrchr(e1, 'M'));
	printf("%s\n", strrchr(e2, 'M'));
	printf("\n");

	char	f1[50] = "Bonjour Nael";
	char	f2[50] = "Bonjour Mael";
	printf("ft_strncmp :\n");
	printf("%d\n", ft_strncmp(f1, f2, 12));
	printf("%d\n", strncmp(f1, f2, 12));
	printf("\n");

	char	g1[50] = "Bonjour Eden & Nina";
	char	g2[50] = "Bonjour Pauline & Mael";
	printf("ft_memchr :\n");
	printf("%p\n", ft_memchr(g1, 'E', 19));
	printf("%p\n", memchr(g2, 'C', 19));
	printf("\n");

	char	h1[50] = "42 is for the braves";
	char	h2[50] = "42 is for the graves";
	printf("ft_memcmp :\n");
	printf("%d\n", ft_memcmp(h1, h2, 20));
	printf("%d\n", memcmp(h1,h2, 20));
	printf("\n");

	char	i1[50] = "Bonjour la famille";
	char	i2[50] = "Bonjo";
	printf("ft_strnstr :\n");
	printf("%s\n", ft_strnstr(i1, i2, 5));
	printf("%s\n", strnstr(i1, i2, 5));
	printf("\n");

	printf("ft_atoi :\n");
	printf("%d\n", ft_atoi("  13 i"));
	printf("%d\n", atoi("  13 i"));
	printf("\n");

	char	j1[50] = "Hello";
	printf("ft_substr :\n");
	printf("%s\n", ft_substr(j1, 12, 6));
	printf("\n");

	char	k1[50] = "xx tripouille   xxx";
	char	k2[50] = " x";
	printf("ft_strtrim :\n");
	printf("%s\n", ft_strtrim(k1, k2));
	printf("\n");


	char	l1[50] = "abcdaefaghiaj";
	char	l2 = 'a';
	char	**tab;
	size_t		i;
	i = 0;
	tab = ft_split(l1, l2);
	printf("ft_split : \n");
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i] );
		printf("\n");
		i++;
	}

	printf("ft_itoa : \n");
	printf("%s\n", ft_itoa(-2147483648));
	printf("\n");
}
