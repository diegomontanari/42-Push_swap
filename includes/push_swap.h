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
} t_stack;

// Costruzione e gestione lista
void		ft_add_node_to_back(t_stack **stack, t_stack *node_new);
t_stack		*ft_new_node(int value);
void		ft_free(t_stack **lst);
t_stack		*ft_stack_last(t_stack *lst);
int			ft_stack_size(t_stack *lst);

// Parsing e controllo input
t_stack		*ft_process(int argc, char **argv);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
void		ft_error(void);
void		ft_error_ch(void);
char   *get_next_line(int fd);
void		ft_freestr(char **lst);
t_stack		*ft_process_quoted_numbers(char **argv);
int			ft_atoi2(const char *str);

// Operazioni stack
void		ft_sa(t_stack **a, int j);
void		ft_sb(t_stack **b, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **a, t_stack **b, int j);
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_rrb(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);

// Algoritmi di ordinamento
void		ft_sort(t_stack **stack_a);
void		ft_sort_big(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a);
int			ft_checksorted(t_stack *stack_a);

// Utils per ordinamento
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_find_index(t_stack *a, int nbr);
int			ft_find_place_b(t_stack *stack_b, int nbr_push);
int			ft_find_place_a(t_stack *a, int nbr);

// Parsing avanzato
int			ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb(t_stack *a, t_stack *b, int c);
int			ft_rotate_type_ab(t_stack *a, t_stack *b);
int			ft_rotate_type_ba(t_stack *a, t_stack *b);
int			ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);

#endif