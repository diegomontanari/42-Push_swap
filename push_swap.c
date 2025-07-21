#include "libft.h"

typedef struct s_list
{
    int             value;
    struct s_list   *next;
} t_list;


int	main(int argc, char **argv)
{
	t_list	*a; 

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}











