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


// sort(Stack<Integer> s) 
// {  
//    if (s.isEmpty()) 
//    {
//       return s;
//    }
  
//    int pivot = s.pop();
   
//    // partition
//    Stack<Integer> left  = new Stack<Integer>();
//    Stack<Integer> right = new Stack<Integer>();
   
//    while(!s.isEmpty())
//    {
//       int y = s.pop();
//       if (y < pivot) 
//       {
//          left.push(y);
//       } 
//       else 
//       {
//          right.push(y);
//       }
//    }
   
//    sort(left);
//    sort(right);
    
//    // merge
//    Stack<Integer> tmp = new Stack<Integer>();
   
//    while(!right.isEmpty()) 
//    {
//       tmp.push(right.pop());
//    }
   
//    tmp.push(pivot);
   
//    while(!left.isEmpty()) 
//    {
//       tmp.push(left.pop());
//    }

//    while(!tmp.isEmpty()) 
//    {
//       s.push(tmp.pop());
//    }
//    return s;
// }


// void  ft_push(int *array1, int *array2, size_t *size1, size_t *size2)
// {

//    if (*size2 > 0)
//    {
//       ft_revrotate1(array1, ++(*size1));
//       array1[0] = array2[0];
//       array2[0] = 0;
//       ft_rotate1(array2, (*size2)--);
//    }
// }




int   *algo_find_min_max_median(int *arr, size_t size, int *min_max_med)
{
   size_t   i;

   i = 0;
   min_max_med[0] = arr[0];
   min_max_med[1] = arr[0];
   while (i < size)
   {
      if (arr[i] > min_max_med[1])
         min_max_med[1] = arr[i];
      if (arr[i] < min_max_med[0])
         min_max_med[0] = arr[i];
      i++;
   }
   min_max_med[2] = min_max_med[0] + ((min_max_med[1] - min_max_med[0]) / 2);
   return (min_max_med);
}

void algo_true_stackmerge_sort(t_stacks *st)
{


}




int	*ft_algo_true_stackmerge(t_stacks *st)
{ 
   int i;
   int *min_max_med;
   int tt[3];

   LIST("true_merge st->arr[%ld]: %d\n", st, st->arr, st->asize)


   algo_true_stackmerge_sort(st);

   // if (!ft_arr_sorted(st->arr, st->asize))
   // {

   // }
   min_max_med = algo_find_min_max_median(st->arr, st->asize, tt);

   // DB(STR, ST, ARR, SIZE)
   LIST("min_max_med[%ld]: %d\n", min_max_med, min_max_med, 3)

   // i = 0;
   // printf("\n");
   // while (st && i < st->asize)
   //    printf("true_merge st->arr[%ld]: %d\n", i, st->arr[i++]);



   return (st->brr);
}

// int	main(void)
// {
// 	t_stacks *st;
// 	int i;
// 	int x[10] = {452, 111, 75, 67, 34, 24, 11, 9, 6, 3};
// 	int *y;

// 	st = ft_init_t_stacks(x, 10);

//    LIST("st->arr[%ld]: %d\n", st, st->arr, st->asize)


// 	y = ft_algo_true_stackmerge(st);

   
//    LIST("int y[%ld]: %d\n", y, y, st->asize)


// 	return (0);
// }





