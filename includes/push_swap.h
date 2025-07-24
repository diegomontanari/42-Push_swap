#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
// ../ means previous dir, then libft/ then libft.h
# include "../libft/libft.h"

// I use a doubly linked list (concrete data structure)
// that behaves like a stack (abstract data structure)
typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;