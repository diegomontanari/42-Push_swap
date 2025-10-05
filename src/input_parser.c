/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:02:12 by dmontana          #+#    #+#             */
/*   Updated: 2025/10/04 16:19:27 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function parses (elabora/interpreta)the command-line arguments
// and fills stack 'a'.
// 1. If argc < 2: no arguments → exits silently (no error).
// 2. If argc == 2: assumes a single quoted string of numbers → splits and 
//    converts them.
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
		ft_error();
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
// if (!*str) manages things like: " " or "" etc...
// - Converts the string to a number, stopping at invalid characters.
// - If the string is invalid or the number overflows, triggers an error.
static const char	*ft_skip_whitespace_and_sign(const char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!*str || !ft_isdigit(*str))
		ft_error();
	return (str);
}

int	ft_atoi2(const char *str)
{
	int				sign;
	long long int	result;

	result = 0;
	str = ft_skip_whitespace_and_sign(str, &sign);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		result = result * 10 + (*str - '0');
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_error();
	return ((int)(sign * result));
}
/*
❓ Perché il negativo ha un numero in più?
È dovuto alla rappresentazione in complemento a due, che è lo standard per rappresentare numeri negativi nei computer.

In complemento a due, lo zero è rappresentato in modo unico.

Questo fa sì che ci siano più combinazioni disponibili per i negativi rispetto ai positivi.

In pratica:

Ci sono 2³¹ numeri negativi: da -1 a -2147483648

Ci sono 2³¹ - 1 numeri positivi: da 0 a 2147483647

💡 Curiosità
Se provi a fare -(-2147483648) in C, ottieni... un overflow! Perché 2147483648 non è rappresentabile come int. Ti serve long o long long per gestirlo.

♟️ Quindi
"2147483648" → overflow: supera INT_MAX → errore
"-2147483649" → underflow: scende sotto INT_MIN → errore

Chiaro?
	
Questo è il motivo per cui non ho passato l'ultimo test all'exam rank 02, ora so che basta mettere (> MAX_INT) o (< MIN_INT), ma non (=)
*/
