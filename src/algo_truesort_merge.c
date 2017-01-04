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

int *arr;
int *brr;

static void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(arr[l1] <= arr[l2])
         brr[i] = arr[l1++];
      else
         brr[i] = arr[l2++];
   }
   
   while(l1 <= mid)    
      brr[i++] = arr[l1++];

   while(l2 <= high)   
      brr[i++] = arr[l2++];

   for(i = low; i <= high; i++)
      arr[i] = brr[i];
}

static void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int	*ft_algo_true_merge(t_stacks *st)
{ 
   
   int i;

	arr = ft_mallocint(st->asize - 1);
   	brr = ft_mallocint(st->asize - 1);   

   ft_intcpy(arr, st->arr, st->asize);
   ft_intcpy(brr, st->brr, st->asize);

   sort(0, st->asize - 1);
   return (ft_intcpy(ft_mallocint(st->asize), arr, st->asize));
}

// int	main(void)
// {
// 	t_stacks *st;
// 	int i;
// 	int x[10] = {9, 3, 6, 11, 24, 75, 34, 67, 111, 452};
// 	int *y;

// 	st = ft_init_t_stacks(x, 10);

// 	i = 0;
// 	while (st && i < st->asize)
// 		printf("int arr[%ld]: %d\n", i, st->arr[i++]);

// 	y = ft_algo_true_merge(st);

// 	i = 0;
// 	while (y && i < st->asize)
// 		printf("int y[%ld]: %d\n", i, y[i++]);



// 	return (0);
// }





