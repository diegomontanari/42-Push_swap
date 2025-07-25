#include "includes/push_swap.h"
// - Il primo if verifica se il minimo è in cima 
//  (In questo caso l'unica comb. disordinata è min-max-mid)
// - Else if se max in cima con ra max va in fondo,
//   Se ordinati ok, se no basta fare sa dei primi 2.
// - Else (ovvero se medio in cima): nel primo if
//   se max è in 2a (mid-max-min) basta un rra,
//   se max in ultima (mid-min-max) basta un sa.
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}