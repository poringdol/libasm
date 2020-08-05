#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <asm/unistd.h>
#include "libasm.h"

char *test_str[8] = {
						"test",
						"test",
						"test ",
						"TEST",
						" !123 teSt %;",
						"TEst \0tEst",
						"",
						NULL
};

int	strlen_test()
{
	for (int i = 0; test_str[i]; i++)
	{
		size_t i1 =    strlen(test_str[i]);
		size_t i2 = ft_strlen(test_str[i]);
		if (i1 != i2)
			return (printf("\tFAIL ft_strlen: Expected '%li', received '%li'\n", i1, i2));
	}
	return (printf("ft_strlen passed all tests\n"));
}

int	strcpy_test()
{
	char	str1[20];
	char	str2[20];

	for (int i = 0; test_str[i]; i++)
	{
		   strcpy(str1, test_str[i]);
		ft_strcpy(str2, test_str[i]);
		if (strcmp(str1, str2))
			return (printf("\tFAIL ft_strcpy: Expected '%s', received '%s'\n", str1, str2));
	}
	return (printf("ft_strcpy passed all tests\n"));
}

int	strcmp_test()
{
	for (int i = 0; i < 6; i++)
	{
		int i1 =    strcmp(test_str[i], test_str[i + 1]);
		int i2 = ft_strcmp(test_str[i], test_str[i + 1]);
		if (i1 != i2)
			return(printf("\tFAIL ft_strcmp: For strings '%s' & '%s' expected %i, received %i\n", test_str[i], test_str[i + 1], i1, i2));
	}
	return (printf("ft_strcmp passed all tests\n"));
}

int	write_test()
{
	errno = 0;
	int	fd1 = open("text1.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	int	fd2 = open("text2.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (errno) perror("Exit");

	for (int i = 0; test_str[i]; i++)
	{
		ssize_t i1 =    write(fd1, test_str[i], strlen(test_str[i]));
		//    write(1, "\n", 1);
		ssize_t i2 = ft_write(fd2, test_str[i], strlen(test_str[i]));
		// ft_write(1, "\n", 1);
		// perror("Exit");
		// printf("%li\n", i2);
		if (i1 != i2)
			return (printf("\tFAIL ft_write: Expected '%li', received '%li'\n", i1, i2));
		ft_write(fd2, test_str[i], strlen(test_str[i]));
		char str1[20] = {0},
			 str2[20] = {0};
		for (int j = 0, k = 1; k > 0; j++)
			k = read(fd1, &str1[j], 1);
		for (int j = 0, k = 1; k > 0; j++)
			k = read(fd2, &str2[j], 1);
		if (strcmp(str1, str2))
			return (printf("\tFAIL ft_write: Expected '%s', received '%s'\n", str1, str2));
	}
	return (printf("ft_write passed all tests\n"));
}

int	read_test()
{
	char	str1[20] = {0};
	char	str2[20] = {0};
	int	fd1 = open("text1.txt", O_RDWR | O_TRUNC | O_CREAT, 0000);
	int	fd2 = open("text2.txt", O_RDWR | O_TRUNC | O_CREAT, 0000);
	for (int i = 0; test_str[i]; i++)
	{
		ssize_t i1 =    read(fd1, str1, strlen(test_str[i]));
		ssize_t i2 = ft_read(fd2, str2, strlen(test_str[i]));
		if (i1 != i2)
			return (printf("\tFAIL ft_read: Expected '%li', received '%li'\n", i1, i2));
		if (strcmp(str1, str2))
			return (printf("\tFAIL ft_read: Expected '%s', received '%s'\n", str1, str2));
	}
	return (printf("ft_read passed all tests\n"));
}

int	strdup_test()
{
	char	*str1;
	char	*str2;

	for (int i = 0; test_str[i]; i++)
	{
		str1 =    strdup(test_str[i]);
		str2 = ft_strdup(test_str[i]);
		if (strcmp(str1, str2))
			return (printf("\tFAIL ft_strdup: Expected '%s', received '%s'\n", str1, str2));
		printf("%s\n", str1);
		printf("%s\n", str2);
	}
	return (printf("ft_strdup passed all tests\n"));
}

int	main(void)
{
	strlen_test();
	strcpy_test();
	strcmp_test();
	write_test();
	read_test();
	strdup_test();
}