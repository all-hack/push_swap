/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:06:02 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:06:06 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFSIZE 1024

typedef struct	s_result
{
	int		*true_sort;
	size_t	true_size;
	char	*op_list;
	size_t	op_count;
	int		algo_index;	
}				t_result;

typedef struct	s_stacks
{
	int		*arr;
	int		*brr;
	size_t	asize;
	size_t	bsize;
}				t_stacks;

typedef struct	s_algo
{
	int		(*algo_condition[2]) (t_stacks *st, t_result *rt, int algo_op_size);
	char	*(*algo_op[2]) (t_stacks *st, t_result *rt);
	char	*algo_names[1];
	int		algo_op_end;
	int		algo_condition_end;
}				t_algo;

int		ft_strsearch_ov(char const *s, char const *c);
int		*ft_intcpy(int	*dst, int *src, size_t n);

int		*ft_mallocint(size_t size);
int		ft_convert_char_int(char *str);
int		*ft_cli_arguments_array(char **argv, size_t *size);

int		ps_ssov_wrapper(char const *s, char const *c);
int		ft_check_valid_input(char **argv, char *valid_char);
int 	ft_check_duplicate_int(int	*arr, size_t size);
void	ft_ps_error(int k, char *err);

void	ft_swap1(int	*array, size_t size);
void	ft_swap2(int	*arr, int	*brr, size_t asize, size_t bsize);
void	ft_push(int	*array1, int	*array2, size_t *size1, size_t *size2);
void	ft_rotate1(int	*array, size_t size);
void	ft_rotate2(int	*arr, int	*brr, size_t asize, size_t bsize);
void	ft_revrotate1(int	*array, size_t size);
void	ft_revrotate2(int	*arr, int	*brr, size_t asize, size_t bsize);

char	*ft_sa(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_sb(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_ss(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_pa(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_pb(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_ra(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_rb(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_rra(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_rrb(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_rr(int	*arr, int *brr, size_t *asize, size_t *bsize);
char	*ft_rrr(int	*arr, int *brr, size_t *asize, size_t *bsize);

t_result	*ft_init_t_result(size_t true_size);
t_stacks	*ft_init_t_stacks(int	*arr, size_t asize);
void		ft_clean_t_stacks(t_stacks **st);
void		ft_clean_t_result(t_result **rt);

t_algo		*ft_init_t_algo();
void		ft_clean_t_algo(t_algo **at);
t_result	*ft_pushswap_algo_control(t_stacks *st);



char		*ft_check_op_count(char *op_list, size_t *curr_count);
size_t		ft_count_operations(char *op_list);

int			*ft_algo_true_merge(t_stacks *st);
int			*ft_algo_true_stackmerge(t_stacks *st);

char		*op_algo_0_bubble(t_stacks *st, t_result *rt);

int			op_condition_0_less4(t_stacks *st, t_result *rt, int algo_op_end);

char		*ft_read_stdin();
char		**ft_read_cli_args(int argc, char **argv);
int			*ft_intcpy(int	*dst, int *src, size_t n);
int			ft_arr_sorted(int *arr, size_t size);




int 	zyc;
# 	define LIST(STR, ST, ARR, SIZE) zyc = 0; printf("\n"); while (ST && zyc < SIZE) {printf(STR, zyc, ARR[zyc++]);}
# 	define LIST0(STR, ST, ARR) zyc = 0; printf("\n"); while (ST && ARR[zyc]) {printf(STR, zyc, ARR[zyc++]);}



# include						<stdio.h>
#endif



