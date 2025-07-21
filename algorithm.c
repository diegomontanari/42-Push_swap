// This function creates and fills a with the numbers taken from the command line arguments.
// If nbrs are passed in a single string (argc == 2), it splits them and inserts them into a.
// If nbrs are passed as separate arguments, it takes them one by one and inserts them into a.
// If there are no numbers, it raises an error.
// PS: I need atoi as the command line is a string and I need integers.

#include "push_swap.h"
#include "libft.h"

t_stack	*ft_process(int argc, char **argv)
{
    t_stack *a;
    int i;
    int j;

    i = 1;
    a = NULL;
    if (argc < 2)
        ft_error();
    if (argc == 2)
        ft_process_quoted_numbers(argv);
    else
    {
        while (i < argc)
        {
            j = ft_atoi(argv[i]);
            ft_add_node_to_back(&a, ft_new_node(j));
            i++;
        }
    }
    return(a);
}

// in case of numbers are passed in between quotation
// marks (so all have argv[1], and I need to split.)
// So, this function takes the string, and splits 
// the numbers in order to create seperated integers.
t_stack	*ft_process_quoted_numbers(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}
    