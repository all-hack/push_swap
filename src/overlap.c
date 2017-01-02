/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:03:35 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:03:38 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"






int	ps_ssov_wrapper(char const *s, char const *c)
{
	if (s && c)
	{		
		if (s[0] == '-')
			return (ft_strsearch_ov(++s, c));
		else
			return (ft_strsearch_ov(s, c));
	}
	return (-1);
}


int	ft_check_valid_input(char **argv, char *valid_char)
{
	if (argv && *argv)
	{
		while (*argv)
			if (ps_ssov_wrapper(*argv++, valid_char) == 0)
				return (0);
		return (1);		
	}
	return (-1);
}


void ft_error(int k)
{
	if (k < 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int *ft_mallocint(size_t size)
{
	int	*arr;

	if ((arr = (int*)malloc(sizeof(int) * size)))		
		return (arr);
	else
		return (NULL);

}

int ft_convert_char_int(char *str)
{
	intmax_t	tmp;
	int			x;

	if (str[0] == '-')
		x = 11;
	else
		x = 10;
	if (ft_strlen(str) <= x)
	{
		tmp = ft_intmax_atoi(str);
		printf("%ld\n", tmp);
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_error(0);
		return (tmp);
	}
	ft_error(0);
}


int *ft_cli_arguments_array(char **argv, size_t *size)
{
	intmax_t	i;
	int			*arr;
	
	if (argv && size)
	{
		*size = 0;
		while(argv[*size])
			(*size)++;
		NULL_GUARD(arr = ft_mallocint(*size));
		i = -1;
		while (++i < *size)
			arr[i] = ft_convert_char_int(argv[i]);
		return (arr);
	}	
	return (NULL);
}

static	int	recursive_loop(int a, int *arr, size_t size)
{
	size_t i;

	if (arr)
	{
		i = 0;
		while (i < size)
			if (a == arr[i++])
				return (1);
		return (0);
	}
	return (-1);
}


int ft_check_duplicate_int(int	*arr, size_t size)
{
	int	*i;

	if (arr)
	{
		i = arr + size - 1;
		while (arr < i)
			if (recursive_loop(*arr, ++arr, --size))
				return (0);
		return (1);
	}
	return (-1);
}


void	ft_swap1(int	*array, size_t size)
{
	int	tmp;

	if (size > 1)
	{
		tmp = array[0];
		array[0] = array[1];
		array[1] = tmp;
	}
}

void	ft_swap2(int	*arr, int	*brr, size_t asize, size_t bsize)
{
	ft_swap1(arr, asize);
	ft_swap1(brr, bsize);
}



void	ft_rotate1(int	*array, size_t size)
{	
	size_t	i;	

	i = 0;
	if (size > 1)
		while (i++ < size - 1)
			ft_swap1(array++, size);
}

void	ft_rotate2(int	*arr, int	*brr, size_t asize, size_t bsize)
{
	ft_rotate1(arr, asize);
	ft_rotate1(brr, bsize);
}

void	ft_revrotate1(int	*array, size_t size)
{
	int		tmp;
	size_t	i;	

	i = 1;
	if (size > 1)
		while (i++ < size)
			ft_swap1((array + (size - i)), size);
}

void	ft_revrotate2(int	*arr, int	*brr, size_t asize, size_t bsize)
{
	ft_revrotate1(arr, asize);
	ft_revrotate1(brr, bsize);
}


void	ft_push(int	*array1, int	*array2, size_t *size1, size_t *size2)
{

	if (*size2 > 1)
	{
		ft_revrotate1(array1, ++(*size1));
		array1[0] = array2[0];
		array2[0] = 0;
		ft_rotate1(array2, (*size2)--);
	}
}




int main(int argc, char** argv)
{
	size_t	asize;
	size_t	bsize;
	int		*arr;
	int		*brr;
	size_t	i;

	// // while (argv[j])
	// // 	printf("argd: %s\n", argv[j++]);
	// if (argc == 2)	
	// 	argv = ft_strsplit(argv[1], ' ');
	// else
	// 	argv++;
	// if (argc > 1)
	// 	ft_error(ft_check_valid_input(argv, "0123456789"));	
	// else
	// 	return (0);

	// arr = ft_cli_arguments_array(argv, &asize);
	// ft_error(ft_check_duplicate_int(arr, asize));
	// brr = ft_mallocint(asize);
	// bsize = asize;

	// i = 0;
	// while (i < size)
	// 	printf("int array: %d\n", arr[i++]);

	
	int array1[7] = {1, 6, 4, 9, 3, 8, 0};
	int array2[4] = {5, 5, 5, 0};
	asize = 6;
	bsize = 3;
	
	i = 0;
	printf("asize: %d\n", asize);
	while (i < asize)
		printf("array1[%d]: %d\n", i, array1[i++]);
	
	printf("\n");
	i = 0;
	printf("bsize: %d\n", bsize);
	while (i < bsize)
		printf("array2[%d]: %d\n", i, array2[i++]);

	ft_push(array1, array2, &asize, &bsize);

	i = 0;
	printf("asize: %d\n", asize);
	while (i < asize)
		printf("array1[%d]: %d\n", i, array1[i++]);
	
	printf("\n");
	i = 0;
	printf("bsize: %d\n", bsize);
	while (i < bsize)
		printf("array2[%d]: %d\n", i, array2[i++]);
	

	// printf("input valid\n");
	// printf("return: %d\n", ft_check_valid_input(argv, "0123456789"));
	// ft_cli_arguments_array(argv, j);

	return (0);

}





