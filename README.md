# push_swap

### definitions

* new library functions
	* `int	ft_strsearch_ov(char const *s, char const *c)`
		* checks to make sure that only valid characters defined in `c` appear in searched string `s`
		* returns 1 if string is valid, 0 if invalid, -1 for errror

* structs
	* s_result` --> `t_result`
		* `int	*true_sort`
			* the list of integers properly sorted with a tested algorithm
		* `size_t	true_size`
			* initial size of stack a i.e. the size of the list of integers
		* `char	*op_list`
			* the operation list of the current best successful sort
		* `size_t	op_count`
			* the operation count of the current best successful sort
		* `int algo_index`
			* the index in the algorithm function array of the algorithm used for current best successful sort

	* `s_stacks` --> `t_stacks`
		* `int		*arr`
			* the array that represents stack a
		* `int		*brr`
			* the array that represents stack b
		* `size_t	asize`
			* the current size of stack a
		* `size_t	bsize`
			* the current size of stack b

	* `s_algo` -> `t_algo`
		* `int	(*algo_condition[i]) (t_stacks *st, t_result *rt)`
			* a function array containing a series of condition functions to check the starting stack against
			* returns a `int` which corresponds to the algorithm in `algo_op` to be selected and used
			* terminated by 0
		* `char	*(*algo_op[i]) (t_stacks *st, t_result *rt)`
			* a function array containing a series of algorithms to be applied based on a condition in `algo_condition`
			* terminated by 0
		* `char	**[i]algo_names`
			* the name of the algorithm for the corresponding index
		* `int	algo_op_size`
			* corresponds the size of the `algo_op` function array including terminating 0
		* `int	algo_condition_size`
			* corresponds the size of the `algo_condition` function array including terminating 0

* overlap_allocation.c
	* `int *ft_mallocint(size_t size)`
		* mallocate `size` + 1 memory to an `int` array and bzero it. the extra space is for a terminating 0 which is used for how i implemented the push_swap operations.
	* `int ft_convert_char_int(char *str)`
		* converts a valid `char*` called `str` into a `int` and returns the `int`
		* only checks to make sure that `str` represents a valid `int` in size
	* `int *ft_cli_arguments_array(char **argv, size_t *size)`
		* converts the array of `char*` argv into a `int*` using `ft_convert_char_int` and `ft_mallocint`
		* does no error checking

* overlap_validity.c
	* `int	ps_ssov_wrapper(char const *s, char const *c)`
		* a wrapper built arround `ft_strsearch_ov` to make it apply to the specs of the project
		* checks for a leading `-` and if found increments `s` by 1 and passes the result to `ft_strsearch_ov`
	* `int	ft_check_valid_input(char **argv, char *valid_char)`
		* a wrapper around `ps_ssov_wrapper` that runs it in a loop for every `char*` in `argv`
	* `int ft_check_duplicate_int(int	*arr, size_t size)`
		* checks `int` array `arr` for duplicate `int`'s

* overlap_ps_operations_ps.c
	* `void	ft_swap1(int	*array, size_t size)`
		* corresponds either `sa` and `sb`
		* swaps the value stored in `array[0]` with the one stored in `array[1]`
		* if there is less than 2 values in the array does nothing
	* `void	ft_swap2(int	*arr, int	*brr, size_t asize, size_t bsize)`
		* corresponds to `ss`
		* performs `ft_swap1` to `arr` and `brr`
	* `void	ft_push(int	*array1, int	*array2, size_t *size1, size_t *size2)`
		* corresponds to either `pa` or `pb`
		* removes the value at the top of `array2` and puts it at the top of `array1`

* overlap_ps_operations_rot.c
	* `void	ft_rotate1(int	*array, size_t size)`
		* corresponds to either `ra` or `rb`
		* shifts the values in `array` up one
		* the first element becomes the last
	* `void	ft_rotate2(int	*arr, int	*brr, size_t asize, size_t bsize)`
		* corresponds to `rr`
		* performs `ft_rotate1` to both `arr` and `brr`
	* `void	ft_revrotate1(int	*array, size_t size)`
		* corresponds to either `rra` or `rrb`
		* shifts the values in `array` down one
		* last element becomes the first
	* `void	ft_revrotate2(int	*arr, int	*brr, size_t asize, size_t bsize)`
		* corresponds to `rrr`
		* performs `ft_revrotate1` to both `arr` and `brr`

* overlap_struct_infa.c
	* `t_stacks	*ft_init_t_stacks(int	*arr, size_t asize)`
		* initalization function for our `t_stacks` struct
	* `void	ft_clean_t_stacks(t_stacks **st)`
		* freeing function for our `t_stacks`
	* `t_result	*ft_init_t_result(int	*true_sort, size_t true_size)`
		* initialization function for our `t_result` struct
	* `void	ft_clean_t_result(t_result **rt)`
		* freeing function for our `t_result` struct

* algo_struct_infa.c
	* `t_algo	*ft_init_t_algo()`
		* initializes `t_algo` inputing the appropriate functions one at a time because the norm is chocking out my freedom
	* `void	ft_clean_t_algo(t_algo **at)`
		* frees `t_algo` safely, though since most of it is static it's kinda no biggies
	

* algo_pushswap_control.c
	* `t_result	*ft_pushswap_algo_control(t_stacks *st)`
		* the main control structure of algorithm application and selection
		* run stack a represented by `st->arr` into a condition function contained in `algo_condition` which will return an `int` corresponding to the index in `algo_op` of the algorithm function to be run
		* run the algorithm selected by the condition function
		* do this for every valid condition, checking to see if a better `op_count` is found each time
		* if no conditions are run, default to the first algorithm in `algo_op` 

* helper_array.c
	* `int	*ft_intcpy(int	*dst, int *src, size_t n)`
		* copies `n` `int`'s from `src` into pre-allocated `dst`
	* `int	ft_arr_sorted_asc(int *arr, size_t size)`
		* checks to see if `arr` is sorted in ascending order

* helper_cli.c
	* `char	**ft_read_cli_args(int argc, char **argv)`
		* validates and handles the command line arguments passed to the program
	* `char	*ft_read_stdin()`
		* reads from the standard input and returns the operations

* op_conditions_set_0.c
	* `int	op_condition_0_less4(t_stacks *st, t_result *rt, int algo_op_end)`
		* checks to see if the size of the stack is less than 4
	* `int	op_condition_1_less6(t_stacks *st, t_result *rt, int algo_op_end)`
		* checks to see if the size of the stack is less than 6

* push_swap algorithm files all contain only the functions related to that algorithm
	* they follows a naming convention
		* "op_algo" 
		* followed by the index in `op_algo` function array 
		* followed by the name of the sort
	* files
		* op_algo_0_bubble.c
			* a two-stack bubble sort implementation





















