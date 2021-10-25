/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:46 by gphilipp          #+#    #+#             */
/*   Updated: 2021/10/25 14:09:39 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "minunit.h"
#include "../libft.h"

MU_TEST(allowed_function) {
	mu_check(system("sh ./test/allowed_function.sh") == 0);
}

MU_TEST(test_isalpha) {
	mu_check(ft_isalpha('a') == 1);
	mu_check(ft_isalpha('b') == 1);
	mu_check(ft_isalpha('z') == 1);
	mu_check(ft_isalpha('A') == 1);
	mu_check(ft_isalpha('B') == 1);
	mu_check(ft_isalpha('Z') == 1);
	mu_check(ft_isalpha('0') == 0);
	mu_check(ft_isalpha('^') == 0);
	mu_check(ft_isalpha('-') == 0);
	mu_check(ft_isalpha('9') == 0);
	mu_check(ft_isalpha('a') == isalpha('a'));
	mu_check(ft_isalpha('-') == isalpha('-'));
}

MU_TEST(test_isdigit) {
	mu_check(ft_isdigit('0') == 1);
	mu_check(ft_isdigit('1') == 1);
	mu_check(ft_isdigit('9') == 1);
	mu_check(ft_isdigit('a') == 0);
	mu_check(ft_isdigit('B') == 0);
	mu_check(ft_isdigit('0' - 1) == 0);
	mu_check(ft_isdigit('2') == isdigit('2'));
	mu_check(ft_isdigit('-') == isdigit('-'));
}

MU_TEST(test_isalnum) {
	mu_check(ft_isalnum('a') == 1);
	mu_check(ft_isalnum('b') == 1);
	mu_check(ft_isalnum('z') == 1);
	mu_check(ft_isalnum('A') == 1);
	mu_check(ft_isalnum('B') == 1);
	mu_check(ft_isalnum('Z') == 1);
	mu_check(ft_isalnum('0') == 1);
	mu_check(ft_isalnum('1') == 1);
	mu_check(ft_isalnum('9') == 1);
	mu_check(ft_isalnum('^') == 0);
	mu_check(ft_isalnum('-') == 0);
	mu_check(ft_isalnum('0' - 1) == 0);
	mu_check(ft_isalnum('a') == isalnum('a'));
	mu_check(ft_isalnum('2') == isalnum('2'));
	mu_check(ft_isalnum('-') == isalnum('-'));
}

MU_TEST(test_isascii) {
	mu_assert_int_eq(isascii(-1), ft_isascii(-1));
	mu_assert_int_eq(isascii(0), ft_isascii(0));
	mu_assert_int_eq(isascii('a'), ft_isascii('a'));
	mu_assert_int_eq(isascii('-'), ft_isascii('-'));
	mu_assert_int_eq(isascii(126), ft_isascii(126));
	mu_assert_int_eq(isascii(127), ft_isascii(127));
	mu_assert_int_eq(isascii(128), ft_isascii(128));
	mu_assert_int_eq(isascii(129), ft_isascii(129));
	mu_assert_int_eq(isascii('a'), ft_isascii('a'));
	mu_assert_int_eq(isascii(176), ft_isascii(176));
	mu_assert_int_eq(isascii(177), ft_isascii(177));
	mu_assert_int_eq(isascii(178), ft_isascii(178));
}

MU_TEST(test_isprint) {
	mu_check(ft_isprint(' ') == 1);
	mu_check(ft_isprint('a') == 1);
	mu_check(ft_isprint('~') == 1);
	mu_check(ft_isprint('-') == 1);
	mu_check(ft_isprint(177) == 0);
	mu_check(ft_isprint('\0') == 0);
	mu_check(ft_isprint('\n') == 0);
	mu_check(ft_isprint('\t') == 0);
	mu_check(ft_isprint('\n') == isprint('\n'));
	mu_check(ft_isprint(177) == isprint(177));
}

MU_TEST(test_strlen) {
	mu_check(ft_strlen("piscine42") == 9);
	mu_check(ft_strlen("piscine 42") == strlen("piscine 42"));
	mu_check(ft_strlen("42") == strlen("42"));
	mu_check(ft_strlen("") == strlen(""));
}

MU_TEST(test_memset) {
	char	nums[] = "0123456789";
	char	nums2[] = "0123456789";
	mu_assert_string_eq("1111111119", ft_memset(nums, '1', 9));
	mu_assert_string_eq("1111111119", memset(nums2, '1', 9));
	mu_assert_string_eq("1111111119", ft_memset(nums, '0', 0));
	mu_assert_string_eq("1111111119", memset(nums, '0', 0));
	/* suite : */
	char	str[] = "42\0NO! OVERLAP GNGNGNGNGN !";
	char	arrow[] = "-->";
	char	str2[] = "42\0NO! OVERLAP GNGNGNGNGN !";
	mu_assert_string_eq("42", str);
	mu_assert_string_eq("...NO! OVERLAP GNGNGNGNGN !", ft_memset(str, '.', 3));
	mu_assert_string_eq("...NO! OVERLAP GNGNGNGNGN !", memset(str2, '.', 3));
}

MU_TEST(test_bzero) {
	char	numso[] = "0123456789";
	char	nums[] = "0123456789";
	bzero(numso, 9);
	ft_bzero(nums, 9);
	mu_assert_int_eq(0, memcmp(numso, nums, 10));
}

MU_TEST(test_memcpy) {
	char	nums[] = "0123456789";
	char	type[] = "abcdegngngn";
	char	numso[] = "0123456789";
	mu_assert_string_eq(memcpy(numso, type, 0), ft_memcpy(nums, type, 0));
	mu_assert_string_eq(memcpy(numso, type, 5), ft_memcpy(nums, type, 5));
	/* suite : */
	char	str[] = "42\0 GNGNGNGNGN !";
	char	arrow[] = "-->";
	char	stro[] = "42\0 GNGNGNGNGN !";
	mu_assert_string_eq("42", str);
	mu_assert_string_eq(memcpy(stro, arrow, 3), ft_memcpy(str, arrow, 3));
	mu_assert_string_eq(memcpy(NULL, NULL, 3), ft_memcpy(NULL, NULL, 3));
}

MU_TEST(test_memmove) {
	char	nums[] = "0123456789";
	char	type[] = "abcdegngngn";
	char	nums2[] = "0123456789";
	// 0123456789
	mu_assert_string_eq(memmove(nums2, type, 0), ft_memmove(nums, type, 0));
	// abcde56789
	mu_assert_string_eq(memmove(nums2, type, 5), ft_memmove(nums, type, 5));
	/* suite : */
	char	str[] = "42\0 GNGNGNGNGN !";
	char	arrow[] = "-->";
	char	str2[] = "42\0 GNGNGNGNGN !";
	char	arrow2[] = "...";
	mu_assert_string_eq("42", str);
	mu_assert_string_eq(memmove(str2, arrow, 3), ft_memmove(str, arrow, 3));
	mu_assert_string_eq(memmove(str2, arrow2, 4), ft_memmove(str, arrow2, 4));
	char	overlap[] = "0123456789";
	char	overlap_original[] = "0123456789";
	ft_memmove(&overlap[2], &overlap[0], 5);
	memmove(&overlap_original[2], &overlap_original[0], 5);
	mu_assert_string_eq(overlap_original, overlap);
	char	overlap2[] = "0123456789";
	char	overlap2_original[] = "0123456789";
	ft_memmove(&overlap2[0], &overlap2[2], 5);
	memmove(&overlap2_original[0], &overlap2_original[2], 5);
	mu_assert_string_eq(overlap2_original, overlap2);
	mu_assert_string_eq(memmove(NULL, NULL, 3), memmove(NULL, NULL, 3));
}

MU_TEST(test_strlcpy) {
	char dest[12];
	char desto[12];
	char src[] = "piscine 42ok ok ok ok ok";
	mu_assert_int_eq(strlcpy(desto, src, 9), ft_strlcpy(dest, src, 9));
	mu_assert_string_eq(desto, dest);
	char src2[] = "piscine 42";
	mu_assert_int_eq(strlcpy(desto, src2, 9), ft_strlcpy(dest, src2, 9));
	mu_assert_string_eq(desto, dest);
	char dest3[] = "xxxxxxxxxx... N'affiche pas ici !";
	char desto3[] = "xxxxxxxxxx... N'affiche pas ici !";
	char src3[] = "piscine 42";
	mu_assert_int_eq(strlcpy(desto3, src3, 9), ft_strlcpy(dest3, src3, 9));
	mu_assert_string_eq(desto3, dest3);
	char ydest[] = "xxxxxxxxxx... N'affiche pas ici !";
	char ydesto[] = "xxxxxxxxxx... N'affiche pas ici !";
	char ysrc[] = "42";
	mu_assert_int_eq(strlcpy(ydesto, ysrc, 6), ft_strlcpy(ydest, ysrc, 6));
	mu_assert_string_eq(ydesto, ydest);
	char ysrc2[] = "piscine 42ok ok ok ok ok";
	mu_assert_int_eq(strlcpy(ydesto, ysrc2, 9), ft_strlcpy(ydest, ysrc2, 9));
	mu_assert_string_eq(ydesto, ydest);
	char x0dest[] = "xxxxxxxxxx... N'affiche pas ici !";
	char x0desto[] = "xxxxxxxxxx... N'affiche pas ici !";
	char x0src[] = "\0 piscine 42";
	mu_assert_int_eq(strlcpy(x0desto, x0src, 10), ft_strlcpy(x0dest, x0src, 10));
	mu_assert_string_eq(x0desto, x0dest);
	char x1dest[] = "xx\0xxxxxxxx... N'affiche pas ici !";
	char x1desto[] = "xx\0xxxxxxxx... N'affiche pas ici !";
	char x1src[] = "piscine 42";
	mu_assert_int_eq(strlcpy(x1desto, x1src, 10), ft_strlcpy(x1dest, x1src, 10));
	mu_assert_string_eq(x1desto, x1dest);
	char x2dest[] = "xxxxxxxxxx... N'affiche pas ici !";
	char x2desto[] = "xxxxxxxxxx... N'affiche pas ici !";
	char x2src[] = "";
	mu_assert_int_eq(strlcpy(x2desto, x2src, 0), ft_strlcpy(x2dest, x2src, 0));
	mu_assert_string_eq(x2desto, x2dest);
	char x3dest[] = "xxxxxxxxxx... N'affiche pas ici !";
	char x3desto[] = "xxxxxxxxxx... N'affiche pas ici !";
	char x3src[] = "piscine 42";
	mu_assert_int_eq(strlcpy(x3desto, x3src, 0), ft_strlcpy(x3dest, x3src, 0));
	mu_assert_string_eq(x3desto, x3dest);
	for (int i = 0; i < 10; ++i)
	{
		char b0dest[] = "piscin\0xxxxxx";
		char b0desto[] = "piscin\0xxxxxx";
		char b0src[] = "e\0xxxxxx";
		mu_assert_int_eq(strlcpy(b0desto, b0src, 0), ft_strlcpy(b0dest, b0src, 0));
		mu_assert_string_eq(b0desto, b0dest);
	}
	for (int i = 0; i < 12; ++i)
	{
		char b1dest[] = "piscin\0xxxxxx";
		char b1desto[] = "piscin\0xxxxxx";
		char b1src[] = "e 42\0xxxxxx";
		mu_assert_int_eq(strlcpy(b1desto, b1src, 0), ft_strlcpy(b1dest, b1src, 0));
		mu_assert_string_eq(b1desto, b1dest);
	}
}

MU_TEST(test_strlcat) {
	char	dest1[42] = "piscine";
	char	dest2[42] = "piscine";
	mu_assert_int_eq(strlcat(dest1, " 42->le code n'est pas bon", 11),
				  ft_strlcat(dest2, " 42->le code n'est pas bon", 11));
	mu_assert_string_eq(dest1, dest2);
	char	dest1a[42] = "piscine";
	char	dest2a[42] = "piscine";
	mu_assert_int_eq(strlcat(dest1a, " 42", 18), ft_strlcat(dest2a, " 42", 18));
	mu_assert_string_eq(dest1a, dest2a);
	char	dest1b[42] = "piscine";
	char	dest2b[42] = "piscine";
	mu_assert_int_eq(strlcat(dest1b, "", 4), ft_strlcat(dest2b, "", 4));
	mu_assert_string_eq(dest1b, dest2b);
	char	dest1c[42] = "piscine";
	char	dest2c[42] = "piscine";
	mu_assert_int_eq(strlcat(dest1c, "42", 4), ft_strlcat(dest2c, "42", 4));
	mu_assert_string_eq(dest1c, dest2c);
	for (int i = 0; i < 10; ++i)
	{
		mu_assert_int_eq(strlcat(dest1c, "42", i), ft_strlcat(dest2c, "42", i));
		mu_assert_string_eq(dest1c, dest2c);
	}
}

MU_TEST(test_toupper) {
	mu_check(ft_toupper('a') == 'A');
	mu_check(ft_toupper('b') == 'B');
	mu_check(ft_toupper('a' - 1) == 'a' - 1);
	mu_check(ft_toupper('b') == 'B');
	mu_check(ft_toupper('z') == 'Z');
	mu_check(ft_toupper('A') == 'A');
	mu_check(ft_toupper('B') == 'B');
	mu_check(ft_toupper('Z') == 'Z');
	mu_check(ft_toupper('0') == '0');
	mu_check(ft_toupper('^') == '^');
	mu_check(ft_toupper('-') == '-');
	mu_check(ft_toupper('9') == '9');
	mu_check(ft_toupper('a') == toupper('a'));
	mu_check(ft_toupper('z') == toupper('Z'));
	mu_check(ft_toupper('A') == toupper('A'));
	mu_check(ft_toupper('-') == toupper('-'));
}

MU_TEST(test_tolower) {
	mu_check(ft_tolower('A') == 'a');
	mu_check(ft_tolower('B') == 'b');
	mu_check(ft_tolower('A' - 1) == 'A' - 1);
	mu_check(ft_tolower('B') == 'b');
	mu_check(ft_tolower('Z') == 'z');
	mu_check(ft_tolower('a') == 'a');
	mu_check(ft_tolower('b') == 'b');
	mu_check(ft_tolower('z') == 'z');
	mu_check(ft_tolower('0') == '0');
	mu_check(ft_tolower('^') == '^');
	mu_check(ft_tolower('-') == '-');
	mu_check(ft_tolower('9') == '9');
	mu_check(ft_tolower('A') == tolower('A'));
	mu_check(ft_tolower('Z') == tolower('z'));
	mu_check(ft_tolower('a') == tolower('a'));
	mu_check(ft_tolower('-') == tolower('-'));
}

MU_TEST(test_strchr) {
	char	a0str[] = "OOOK\0:P";
	int		a0chr;
	mu_check(ft_strchr(a0str, 'i') == 0);
	mu_check(strchr(a0str, 'o') == ft_strchr(a0str, 'o'));
	a0chr = 'O';
	mu_assert_string_eq(strchr(a0str, a0chr), ft_strchr(a0str, a0chr));
	a0chr = 'K';
	mu_assert_string_eq(strchr(a0str, a0chr), ft_strchr(a0str, a0chr));
	a0chr = '\0';
	mu_assert_string_eq(strchr(a0str, a0chr), ft_strchr(a0str, a0chr));
	a0chr = ':';
	mu_assert_string_eq(strchr(a0str, a0chr), ft_strchr(a0str, a0chr));
	char	a1str[] = "mais t'es ou t'pas la";
	a0chr = 't' + 256;
	mu_assert_string_eq(ft_strchr(a1str, a0chr), ft_strchr(a1str, a0chr));
}

MU_TEST(test_strrchr) {
	char	a0str[] = "OOOK\0:P";
	int		a0chr;
	mu_check(ft_strrchr(a0str, 'i') == 0);
	mu_check(strrchr(a0str, 'o') == ft_strrchr(a0str, 'o'));
	a0chr = 'O';
	mu_assert_string_eq(strrchr(a0str, a0chr), ft_strrchr(a0str, a0chr));
	a0chr = 'K';
	mu_assert_string_eq(strrchr(a0str, a0chr), ft_strrchr(a0str, a0chr));
	a0chr = '\0';
	mu_assert_string_eq(strrchr(a0str, a0chr), ft_strrchr(a0str, a0chr));
	a0chr = ':';
	mu_assert_string_eq(strrchr(a0str, a0chr), ft_strrchr(a0str, a0chr));
	char	a1str[] = "mais t'es ou t'pas la";
	a0chr = 't' + 256;
	mu_assert_string_eq(ft_strrchr(a1str, a0chr), ft_strrchr(a1str, a0chr));
}

MU_TEST(test_strncmp) {
	mu_assert_int_eq(strncmp("pisc<ine 40dwde", "piscine 42dewde", 10),
				  ft_strncmp("pisc<ine 40dwde", "piscine 42dewde", 10));
	mu_assert_int_eq(strncmp("piscine", "piscine 42dwdewdw", 10),
				  ft_strncmp("piscine", "piscine 42dwdewdw", 10));
	mu_assert_int_eq(strncmp("piscine 42dewd", "piscineXXX", 7),
				  ft_strncmp("piscine 42dewd", "piscineXXX", 7));
	mu_assert_int_eq(strncmp("piscine 42dedw", "piscine 425824", 10),
				  ft_strncmp("piscine 42dedw", "piscine 425824", 10));
	mu_assert_int_eq(strncmp("piscine 42dwdw", "piscine", 10),
				  ft_strncmp("piscine 42dwdw", "piscine", 10));
	mu_assert_int_eq(strncmp("piscine 42dwwed", "piscine 40dwedewd", 10),
				  ft_strncmp("piscine 42dwwed", "piscine 40dwedewd", 10));
	mu_assert_int_eq(strncmp("42\200", "42\0", 3),
				  ft_strncmp("42\200", "42\0", 3));
}

MU_TEST(test_menchr) {
	char	a0str[] = "OOOK\0:P            :) ";
	int		a0chr;
	mu_check(ft_memchr(a0str, 'i', 20) == 0);
	a0chr = 'o';
	mu_assert_string_eq(memchr(a0str, a0chr, 20), ft_memchr(a0str, a0chr, 20));
	a0chr = 'K';
	mu_assert_string_eq(memchr(a0str, a0chr, 3), ft_memchr(a0str, a0chr, 3));
	a0chr = 'O';
	mu_assert_string_eq(memchr(a0str, a0chr, 20), ft_memchr(a0str, a0chr, 20));
	a0chr = 'K';
	mu_assert_string_eq(memchr(a0str, a0chr, 20), ft_memchr(a0str, a0chr, 20));
	a0chr = '\0';
	mu_assert_string_eq(memchr(a0str, a0chr, 20), ft_memchr(a0str, a0chr, 20));
	a0chr = ':';
	mu_assert_string_eq(memchr(a0str, a0chr, 20), ft_memchr(a0str, a0chr, 20));
	char	loopstr[] = "Ookajkd\0:P";
	char	loopchr[] = "Ookajkd:P\0";
	for (int i = 0; i < 20; ++i)
		for (int x = 0; x < 10; ++x)
			mu_assert_string_eq(memchr(loopstr, (int) loopchr[x], i), ft_memchr(loopstr, (int) loopchr[x], i));
	char	str[] = "     a.   \0.  b.       ";
	for (int i = 0; i < 20; ++i)
		mu_assert_string_eq(memchr(str, 'a', i), ft_memchr(str, 'a', i));
	for (int i = 0; i < 20; ++i)
		mu_assert_string_eq(memchr(str, 'b', i), ft_memchr(str, 'b', i));
	int	a1str[12] = {'a', 0, -1, 'b', 'o', 'n', 'j', 'o', 'u', 'r', '!', 0};
	int	a1chr = -1;
	mu_assert_string_eq(memchr(a1str, a1chr, 11), ft_memchr(a1str, a1chr, 11));
}

MU_TEST(test_memcmp) {
	mu_assert_int_eq(memcmp("\0", "\200", 10),
				  ft_memcmp("\0", "\200", 10));
	mu_assert_int_eq(memcmp("pisc<ine 40dwde", "piscine 42dewde", 10),
				  ft_memcmp("pisc<ine 40dwde", "piscine 42dewde", 10));
	mu_assert_int_eq(memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4),
				  ft_memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4));
	mu_assert_int_eq(memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 8),
				  ft_memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 8));
	mu_assert_int_eq(memcmp("atoms\0\0\0\0", "atoms\0abc", 8),
				  ft_memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
	mu_assert_int_eq(memcmp("\xff\xaa\xde\200", "\xff\xaa\xde\0", 8),
				  ft_memcmp("\xff\xaa\xde\200", "\xff\xaa\xde\0", 8));
	mu_assert_int_eq(memcmp("piscine", "piscine 42dwdewdw", 10),
				  ft_memcmp("piscine", "piscine 42dwdewdw", 10));
	mu_assert_int_eq(memcmp("piscine", "piscine 42dwdewdw", 10),
				  ft_memcmp("piscine", "piscine 42dwdewdw", 10));
	mu_assert_int_eq(memcmp("piscine 42dewd", "piscineXXX", 7),
				  ft_memcmp("piscine 42dewd", "piscineXXX", 7));
	mu_assert_int_eq(memcmp("piscine 42dedw", "piscine 425824", 10),
				  ft_memcmp("piscine 42dedw", "piscine 425824", 10));
	mu_assert_int_eq(memcmp("piscine 42dwdw", "piscine", 10),
				  ft_memcmp("piscine 42dwdw", "piscine", 10));
	mu_assert_int_eq(memcmp("piscine 42dwwed", "piscine 40dwedewd", 10),
				  ft_memcmp("piscine 42dwwed", "piscine 40dwedewd", 10));
	mu_assert_int_eq(memcmp("\0piscine 42dwwed", "\0piscine 40dwedewd", 10),
				  ft_memcmp("\0piscine 42dwwed", "\0piscine 40dwedewd", 10));
	for (int i = 0; i < 20; ++i)
		mu_assert_int_eq(memcmp("piscine\0de 42.  \0   ", "piscine\0de 42/     ", i),
					  ft_memcmp("piscine\0de 42.  \0   ", "piscine\0de 42/     ", i));
}

MU_TEST(test_strnstr) {
	mu_assert_string_eq(strnstr("piscine 42", "42", 11),
					 ft_strnstr("piscine 42", "42", 11));
	mu_assert_string_eq(strnstr("piscine 42", "42", 10),
					 ft_strnstr("piscine 42", "42", 10));
	mu_assert_string_eq(strnstr("piscine 42", "42", 9),
					 ft_strnstr("piscine 42", "42", 9));
	mu_assert_string_eq(strnstr("piscine 42", "42", 8),
					 ft_strnstr("piscine 42", "42", 8));
	mu_assert_string_eq(strnstr("piscine 42", "p", 10),
					 ft_strnstr("piscine 42", "p", 10));
	mu_assert_string_eq(strnstr("piscine 42", "2", 10),
					 ft_strnstr("piscine 42", "2", 10));
	mu_assert_string_eq(strnstr("piscine 42", "z", 10),
					 ft_strnstr("piscine 42", "z", 10));
	mu_assert_string_eq(strnstr("piscine 42", "in", 10),
					 ft_strnstr("piscine 42", "in", 10));
	mu_assert_string_eq(strnstr("piscine 42", "", 10),
					 ft_strnstr("piscine 42", "", 10));
	mu_assert_string_eq(strnstr("piscine 42", "z", 10),
					 ft_strnstr("piscine 42", "z", 10));
	mu_assert_string_eq(strnstr("piscine 42", "zoo", 10),
					 ft_strnstr("piscine 42", "zoo", 10));
	mu_assert_string_eq(strnstr("piscine 42", "20", 10),
					 ft_strnstr("piscine 42", "20", 10));
	mu_assert_string_eq(strnstr("piscine 42", "piscine 42", 10),
					 ft_strnstr("piscine 42", "piscine 42", 10));
	mu_assert_string_eq(strnstr("4242", "4242", 4),
					 ft_strnstr("4242", "4242", 4));
	mu_assert_string_eq(strnstr("4242", "424", 4),
					 ft_strnstr("4242", "424", 4));
	mu_assert_string_eq(strnstr("4444", "444", 4),
					 ft_strnstr("4444", "444", 4));
	mu_assert_string_eq(strnstr("4444", "444", 3),
					 ft_strnstr("4444", "444", 3));
	mu_assert_string_eq(strnstr("4444", "444", 2),
					 ft_strnstr("4444", "444", 2));
	mu_assert_string_eq(strnstr("abcdef", "bcd", 6),
					 ft_strnstr("abcdef", "bcd", 6));
	mu_assert_string_eq(strnstr("abcdef", "xyz", 6),
					 ft_strnstr("abcdef", "xyz", 6));
	mu_assert_string_eq(strnstr("", "", 20),
					 ft_strnstr("", "", 20));
	mu_assert_string_eq(strnstr("a", "", 20),
					 ft_strnstr("a", "", 20));
	mu_assert_string_eq(strnstr("", "a", 20),
					 ft_strnstr("", "a", 20));
	mu_assert_string_eq(strnstr("abc", "a", 20),
					 ft_strnstr("abc", "a", 20));
	mu_assert_string_eq(strnstr("abc", "c", 20),
					 ft_strnstr("abc", "c", 20));
	mu_assert_string_eq(strnstr("abc", "abc", 20),
					 ft_strnstr("abc", "abc", 20));
	mu_assert_string_eq(strnstr("abc", "abcde", 20),
					 ft_strnstr("abc", "abcde", 20));
	mu_assert_string_eq(strnstr("AbcAbcdAbcde", "Abcd", 20),
					 ft_strnstr("AbcAbcdAbcde", "Abcd", 20));
	mu_assert_string_eq(strnstr("piscine 42", "i", 20),
					 ft_strnstr("piscine 42", "i", 20));
	mu_assert_string_eq(strnstr("ababce", "abc", 20),
					 ft_strnstr("ababce", "abc", 20));
	mu_assert_string_eq(strnstr("aaabcabcd", "z", 9),
					 ft_strnstr("aaabcabcd", "z", 9));
	mu_assert_string_eq(strnstr("aaaaBczz", "aaBc", 9),
					 ft_strnstr("aaaaBczz", "aaBc", 9));
	mu_assert_string_eq(strnstr("pbpbpbC", "pbpbC", 9),
					 ft_strnstr("pbpbpbC", "pbpbC", 9));
	mu_assert_string_eq(strnstr("aaabcabcd", "aabc", 20),
					 ft_strnstr("aaabcabcd", "aabc", 20));
}

MU_TEST(test_atoi) {
	char *num[1];
	num[0] = "\t\n\v\f\r ---+--+1234ab567";
	mu_assert_int_eq(0, ft_atoi(num[0]));
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "\t\n\v\f\r -1234ab567";
	mu_assert_int_eq(-1234, ft_atoi(num[0]));
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "\t\n\v\f\r -+1234ab567";
	mu_assert_int_eq(0, ft_atoi(num[0]));
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "\t\n\v\f\r +-1234ab567";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "-+1234ab567";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "+-1234ab567";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "\n-1234ab567";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "12-12";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "12 12";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "-    1212";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "1 287";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "1287.  ";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "\\n34  ";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "   42   ";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "   -42   ";
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	num[0] = "   -\n42   ";
	mu_assert_int_eq(-2147483648, ft_atoi("-2147483648"));
	mu_assert_int_eq(2147483647, ft_atoi("2147483647"));
	mu_assert_int_eq(atoi(num[0]), ft_atoi(num[0]));
	mu_assert_int_eq(atoi("-1234"), ft_atoi("-1234"));
	mu_assert_int_eq(atoi("-2147483648"), ft_atoi("-2147483648"));
	mu_assert_int_eq(atoi("-10101010"), ft_atoi("-10101010"));
	mu_assert_int_eq(atoi("-100"), ft_atoi("-100"));
	mu_assert_int_eq(atoi("-42"), ft_atoi("-42"));
	mu_assert_int_eq(atoi("-1"), ft_atoi("-1"));
	mu_assert_int_eq(atoi("0"), ft_atoi("0"));
	mu_assert_int_eq(atoi("1"), ft_atoi("1"));
	mu_assert_int_eq(atoi("42"), ft_atoi("42"));
	mu_assert_int_eq(atoi("100"), ft_atoi("100"));
	mu_assert_int_eq(atoi("10101010"), ft_atoi("10101010"));
	mu_assert_int_eq(atoi("2147483647"), ft_atoi("2147483647"));
}

MU_TEST(test_calloc) {
	for (int i = 0, *o, *c; i < malloc_good_size(2) + 8; ++i)
	{
		o = calloc(i, sizeof(*o));
		c = ft_calloc(i, sizeof(*c));
		mu_assert_int_eq(malloc_size(o), malloc_size(c));
		if (i > 0)
			mu_assert_int_eq(o[i - 1], c[i - 1]);
		free(o);
		free(c);
	}
}

MU_TEST(test_strdup) {
	char *src;
	char *str, *stro;
	for (int i = 0, *o, *c; i < malloc_good_size(2) + 8; ++i)
	{
		src = calloc(i + 1, sizeof(*src));
		memset(src, 'a', i);
		stro = strdup(src);
		str = ft_strdup(src);
		mu_assert_int_eq(malloc_size(stro), malloc_size(str));
		mu_assert_string_eq(stro, str);
		free(stro);
		free(str);
		free(src);
	}
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(allowed_function);
	MU_RUN_TEST(test_isalpha);
	MU_RUN_TEST(test_isdigit);
	MU_RUN_TEST(test_isalnum);
	MU_RUN_TEST(test_isascii);
	MU_RUN_TEST(test_isprint);
	MU_RUN_TEST(test_strlen);
	MU_RUN_TEST(test_memset);
	MU_RUN_TEST(test_bzero);
	MU_RUN_TEST(test_memcpy);
	MU_RUN_TEST(test_memmove);
	MU_RUN_TEST(test_strlcpy);
	MU_RUN_TEST(test_strlcat);
	MU_RUN_TEST(test_toupper);
	MU_RUN_TEST(test_tolower);
	MU_RUN_TEST(test_strchr);
	MU_RUN_TEST(test_strrchr);
	MU_RUN_TEST(test_strncmp);
	MU_RUN_TEST(test_menchr);
	MU_RUN_TEST(test_memcmp);
	MU_RUN_TEST(test_strnstr);
	MU_RUN_TEST(test_atoi);
	MU_RUN_TEST(test_calloc);
	MU_RUN_TEST(test_strdup);
}
/*
MU_TEST(test_substr) {
	char str[] = "C'est la piscine de 42 OK !?";
	char *out;
	mu_assert_string_eq(NULL, ft_substr(NULL, 0, 2));
	mu_assert_string_eq("2", ft_substr("piscine 42", 9, 13));
	mu_assert_string_eq("\0", ft_substr("piscine 42", 10, 13));
	mu_assert_string_eq("\0", ft_substr("piscine 42", 11, 13));
	mu_assert_string_eq("piscine de 42", out = ft_substr(str, 9, 13)); free(out);
	mu_assert_string_eq("\0", out = ft_substr(str, 8, 0)); free(out);
	mu_assert_string_eq("C'est la piscine de 42 OK !?", out = ft_substr(str, 0, 100));
	mu_assert_int_eq(malloc_good_size(29 * sizeof(char)), malloc_size(out));
	free(out);
	char *stra = calloc(malloc_good_size(2) + 9, sizeof(*stra));
	memset(stra, 'a', malloc_good_size(2) + 8);
	char *aaaaa;
	for (int i = 1, *o, *c; i < malloc_good_size(2) + 8; ++i)
	{
		out = ft_substr(stra, 0, i);
		aaaaa = calloc(i + 1, sizeof(*stra));
		mu_assert_string_eq(memset(aaaaa, 'a', i), out);
		mu_assert_int_eq(malloc_size(aaaaa), malloc_size(out));
		free(aaaaa);
		free(out);
	}
	free(stra);
}

MU_TEST(test_strjoin) {
	char s1[] = "piscine de";
	char s2[] = " 42";
	char *out;
	mu_assert_string_eq("piscine de 42", out = ft_strjoin(s1, s2));
	mu_assert_int_eq(malloc_good_size(14 * sizeof(char)), malloc_size(out));
	free(out);
	char *s1d;
	for (int i = 0, *o, *c; i < malloc_good_size(2) + 8; ++i)
	{
		s1d = calloc(i + 1, sizeof(*s1d));
		memset(s1d, 'a', i);
		out = ft_strjoin(s1d, s2);
		mu_assert_int_eq(malloc_good_size(i + 4), malloc_size(out));
		free(s1d);
		free(out);
	}
	mu_assert_string_eq("lorem ipsumdolor sit amet", out = ft_strjoin("lorem ipsum", "dolor sit amet"));
	free(out);
}

MU_TEST(test_strtrim) {
	char *out;
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("piscine de 42", "")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("      piscine de 42     ", " ")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("aaaaaapiscine de 42bbbbb", "ab")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("abaaaapiscine de 42babbb", "ab")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("iiiiiipiscine de 42iiiii", "i")); free(out);
	mu_assert_string_eq(".  piscine de 42  .", out = ft_strtrim(".  piscine de 42  .", " ")); free(out);
	mu_assert_string_eq("  piscine de 42  ", out = ft_strtrim(".  piscine de 42  .", ".")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim(".  piscine de 42  .", " .")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim(".  piscine de 42  .", ". ")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("   piscine de 42   ", "  ")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("        piscine de 42", "  ")); free(out);
	mu_assert_string_eq("piscine de 42", out = ft_strtrim("piscine de 42      ", "  ")); free(out);
	mu_assert_string_eq("\0", out = ft_strtrim("\0ET LE \\O ALORS? Tu te l'es grillé...", "\0\0\0")); free(out);
	mu_assert_string_eq("(piscine de 42)", out = ft_strtrim("piscned42(piscine de 42)piscned42", "piscned42")); free(out);
	mu_assert_string_eq("(piscine de 42)", out = ft_strtrim("piscned42(piscine de 42)piscned42", "zs42pcndei")); free(out);
	char *str;
	char *bbbbb;
	int size_loc = malloc_good_size(sizeof(char));
	int size_str = size_loc * 3;
	str = calloc(size_str + 1, sizeof(*str));
	memset(str, 'b', size_str);
	memset(str, 'a', size_loc + 3);
	memset(&str[size_str - size_loc - 3], 'c', size_loc + 3);
	bbbbb = calloc(size_loc - 6 + 1, sizeof(*bbbbb));
	mu_assert_string_eq(memset(bbbbb, 'b', size_loc - 6), out = ft_strtrim(str, "ac"));
	mu_assert_int_eq(malloc_size(bbbbb), malloc_size(out));
	free(bbbbb);
	free(out);
}

MU_TEST(test_split) {
	char	*sentence = ",,,,,,,Ceci est le,d,e,b,u,t de tout !,,,,,:),,,,,,";
	char	**res;
	char	**out;
	res = ft_split("          ", ' ');
	mu_check(NULL == res[0]);
	free(res);
	res = ft_split("    ,,    ", ' ');
	mu_assert_string_eq(",,", res[0]); free(res[0]);
	mu_assert_string_eq(NULL, res[1]);
	free(res);
	res = ft_split(",,        ", ' ');
	mu_assert_string_eq(",,", res[0]); free(res[0]);
	mu_assert_string_eq(NULL, res[1]);
	free(res);
	res = ft_split("        ,,", ' ');
	mu_assert_string_eq(",,", res[0]); free(res[0]);
	mu_assert_string_eq(NULL, res[1]);
	free(res);
	res = ft_split(",,", ' ');
	mu_assert_string_eq(",,", res[0]); free(res[0]);
	mu_assert_string_eq(NULL, res[1]);
	free(res);
	res = ft_split("w         ", ' ');
	mu_assert_string_eq("w", res[0]); free(res[0]);
	mu_check(NULL == res[1]);
	free(res);
	res = ft_split("w    ,,   ", ' ');
	mu_assert_string_eq("w", res[0]); free(res[0]);
	mu_assert_string_eq(",,", res[1]); free(res[1]);
	mu_assert_string_eq(NULL, res[2]);
	free(res);
	res = ft_split("w ,,      ", ' ');
	mu_assert_string_eq("w", res[0]); free(res[0]);
	mu_assert_string_eq(",,", res[1]); free(res[1]);
	mu_assert_string_eq(NULL, res[2]);
	free(res);
	res = ft_split("w       ,,", ' ');
	mu_assert_string_eq("w", res[0]); free(res[0]);
	mu_assert_string_eq(",,", res[1]); free(res[1]);
	mu_assert_string_eq(NULL, res[2]);
	free(res);
	res = ft_split("w ,,", ' ');
	mu_assert_string_eq("w", res[0]); free(res[0]);
	mu_assert_string_eq(",,", res[1]); free(res[1]);
	mu_assert_string_eq(NULL, res[2]);
	free(res);
	res = ft_split(sentence, ',');
	mu_assert_string_eq("Ceci est le", res[0]); free(res[0]);
	mu_assert_string_eq("d", res[1]); free(res[1]);
	mu_assert_string_eq("e", res[2]); free(res[2]);
	mu_assert_string_eq("b", res[3]); free(res[3]);
	mu_assert_string_eq("u", res[4]); free(res[4]);
	mu_assert_string_eq("t de tout !", res[5]); free(res[5]);
	mu_assert_string_eq(":)", res[6]); free(res[6]);
	mu_assert_string_eq(NULL, res[7]);
	free(res);
	char *str;
	char *bbbbb;
	int size_loc = malloc_good_size(sizeof(char));
	int size_str = size_loc * 2;
	str = calloc(size_str + 1, sizeof(*str));
	memset(str, 'b', size_str);
	memset(&str[size_loc], 'c', size_str - size_loc);
	str[size_loc] = ',';
	mu_assert_string_eq("bbbbbbbbbbbbbbbb,ccccccccccccccc", str); // 16 et 15
	out = ft_split(str, ',');
	mu_assert_int_eq(32, malloc_size(out[0])); // 32
	mu_assert_int_eq(16, malloc_size(out[1])); // 16
	bbbbb = calloc(size_loc + 1, sizeof(*bbbbb));
	mu_assert_string_eq(memset(bbbbb, 'b', size_loc), out[0]);
	mu_assert_int_eq(malloc_size(bbbbb), malloc_size(out[0]));
	free(out[0]);
	free(bbbbb);
	bbbbb = calloc(size_loc, sizeof(*bbbbb));
	mu_assert_string_eq(memset(bbbbb, 'c', size_loc - 1), out[1]);
	mu_assert_int_eq(malloc_size(bbbbb), malloc_size(out[1]));
	free(out[1]);
	free(bbbbb);
	free(out);
	free(str);
}

MU_TEST(test_itoa) {
	char *out;
	mu_assert_string_eq("-1234", out = ft_itoa(-1234)); free(out);
	mu_assert_string_eq("-2147483648", out = ft_itoa(-2147483648));
	mu_assert_int_eq(malloc_good_size(12), malloc_size(out)); free(out);
	mu_assert_string_eq("-10101010", out = ft_itoa(-10101010)); free(out);
	mu_assert_string_eq("-100", out = ft_itoa(-100)); free(out);
	mu_assert_string_eq("-42", out = ft_itoa(-42)); free(out);
	mu_assert_string_eq("-1", out = ft_itoa(-1)); free(out);
	mu_assert_string_eq("0", out = ft_itoa(0)); free(out);
	mu_assert_string_eq("1", out = ft_itoa(1)); free(out);
	mu_assert_string_eq("42", out = ft_itoa(42)); free(out);
	mu_assert_string_eq("100", out = ft_itoa(100)); free(out);
	mu_assert_string_eq("10101010", out = ft_itoa(10101010)); free(out);
	mu_assert_string_eq("2147483647", out = ft_itoa(2147483647)); free(out);
}

char md_toupper(unsigned int index, char c)
{
	(void) index;
	return toupper(c);
}

char writeindex(unsigned int index, char c)
{
	(void) c;
	return '0' + index;
}

MU_TEST(test_strmapi) {
	mu_assert_string_eq("PISCINE 42", ft_strmapi("piscine 42", &md_toupper));
	mu_assert_string_eq("42", ft_strmapi("42", &md_toupper));
	mu_assert_string_eq("A", ft_strmapi("A", &md_toupper));
	mu_assert_string_eq("0123456789", ft_strmapi("piscine 42", &writeindex));
	char *str, *stro;
	for (int i = 0, *o, *c; i < malloc_good_size(2) + 8; ++i)
	{
		stro = calloc(i + 1, sizeof(*stro));
		memset(stro, 'A', i);
		str = ft_strmapi(stro, &md_toupper);
		mu_assert_int_eq(malloc_size(stro), malloc_size(str));
		mu_assert_string_eq(stro, str);
		free(stro);
		free(str);
	}
}

void v2_md_toupper(unsigned int index, char *c)
{
	(void) index;
	*c = toupper(*c);
}

void v2_writeindex(unsigned int index, char *c)
{
	*c = '0' + index;
}

MU_TEST(test_striteri) {
	char str[] = "piscine 42";
	ft_striteri(str, &v2_md_toupper);
	mu_assert_string_eq("PISCINE 42", str);
	char str2[] = "42";
	ft_striteri(str2, &v2_md_toupper);
	mu_assert_string_eq("42", str2);
	char str3[] = "A";
	ft_striteri(str3, &v2_md_toupper);
	mu_assert_string_eq("A", str3);
	char str4[] = "piscine 42";
	ft_striteri(str4, &v2_writeindex);
	mu_assert_string_eq("0123456789", str4);
}

int	fs_open(char *path, int *length)
{
	int		fd;
	char	src;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	*length = 0;
	while (read(fd, &src, 1))
	{
		(*length)++;
	}
	close(fd);
	return (1);
}

char	*fs_read(char *path, int length)
{
	int		i;
	int		fd;
	char	*content;
	char	src;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	content = malloc(sizeof(char) * (length + 1));
	if (content == 0)
		return (0);
	while (read(fd, &src, 1))
	{
		content[i] = src;
		i++;
	}
	content[length] = '\0';
	close(fd);
	return (content);
}

char	*get_content(char *path)
{
	int			length;
	char		*content;
	int			newline;

	if (fs_open(path, &length) == 0)
		return (NULL);
	content = fs_read(path, length);
	return (content);
}

MU_TEST(test_putxxx_fd) {
	char *path = ".temp_test_putxxx_fd";
	fclose(fopen(path, "wb+"));
	int fd = open(path, O_WRONLY);
	ft_putchar_fd('\t', fd);
	ft_putstr_fd("--> ", fd);
	ft_putendl_fd("super !", fd);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	mu_assert_string_eq("\t--> super !\n-2147483648", get_content(path));
}

MU_TEST_SUITE(test_suite2) {
	MU_RUN_TEST(test_substr);
	MU_RUN_TEST(test_strjoin);
	MU_RUN_TEST(test_strtrim);
	MU_RUN_TEST(test_split);
	MU_RUN_TEST(test_itoa);
	MU_RUN_TEST(test_strmapi);
	MU_RUN_TEST(test_striteri);
	MU_RUN_TEST(test_putxxx_fd);
}
*/

int main(void) {
	MU_RUN_SUITE(test_suite);
	//MU_RUN_SUITE(test_suite2);
	MU_REPORT();
	return MU_EXIT_CODE;
}
