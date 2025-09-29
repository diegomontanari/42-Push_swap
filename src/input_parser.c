/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:02:12 by dmontana          #+#    #+#             */
/*   Updated: 2025/09/28 17:02:14 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function parses (elabora/interpreta)the command-line arguments
// and fills stack 'a'.
// 1. If argc < 2: there are no arguments → triggers an error.
// 2. If argc == 2: assumes a single quoted
//					string of numbers → splits and converts them.
// 3. If argc > 2: processes each argument individually
//				and converts them to integers.
// It uses ft_atoi2 to safely convert strings and checks for overflow.

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		a = ft_process_quoted_numbers(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_node_to_back(&a, ft_new_node(j));
			i++;
		}
	}
	return (a);
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
	if (!tmp)
		return (NULL);
	if (!tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_node_to_back(&a, ft_new_node(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

// Converts a string to an integer with overflow protection.
// (normal atoi does not have overflow protection)
// - Skips leading whitespace characters.
// - Handles optional '+' or '-' sign.
// - Converts the string to a number, stopping at invalid characters.
// - If the string is invalid or the number overflows, triggers an error.
int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}
