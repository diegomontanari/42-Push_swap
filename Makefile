# ================================= VARIABILI ================================ #

# Nome dell'eseguibile finale
NAME = push_swap

# Compilatore e flag di compilazione
# la flag -I(CARTELLA IN CUI ENTRARE) dice di entrare in includes per l'header
# se l'header e' dentro 2 cartelle lo ripeti (es: -Iincludes -Idirectory2)
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -Iincludes

# Directory del progetto
LIBFTDIR = libft/

# Lista di tutti i file sorgente del progetto.
## Wildcard è una funzione di GNU Make che permette di trovare automaticamente 
## tutti i file che corrispondono a un certo pattern (ad esempio tutti i.c
## in una cartella).
SRCS = $(wildcard SRCS/push_swap/*.c)

# Crea i file oggetto sostituendo .c con .o
# Trasforma: algorithm.c -> algorithm.o, ft_add_node_to_back.c -> ft_add_node_to_back.o, ecc.
OBJS = $(SRCS:.c=.o)

# Flag per linkare la libft (-I unisce gli header, -L le librerie !!)
INCLUDE = -L ./libft -lft

# ================================== REGOLE ================================== #

# Regola per compilare i file .c in .o
# $< = primo prerequisito (file .c)
# $@ = target (file .o)
.c.o:
	$(CC) $(FLAGS) -c $< -o $@

# Target principale: compila l'eseguibile push_swap
$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

# Target all: compila tutto (solo il programma principale)
all: $(NAME)

# =============================== PULIZIA ==================================== #

# Target clean: rimuove file oggetto (.o) (riga 1) e pulisce libft (riga 2)
# 1a riga rimuove OBJS, 2a attiva make clean di libft
# pratica standard: il clean di un progetto pulisce anche le sue dipendenze.


# Il @ all'inizio del comando serve a nascondere il comando stesso durante l'esecuzione.
# Senza @:
# cd libft/ && make clean
# make[1]: Entering directory 'libft'
# [output del clean della libft]
# Con @:
# make[1]: Entering directory 'libft'
# [output del clean della libft]

clean:
	$(RM) $(OBJS)
	@cd $(LIBFTDIR) && $(MAKE) clean

# Target fclean: pulizia completa (clean + rimuove eseguibili)
# RICORDA: File sorgente (.c) → Il tuo codice originale
# File oggetto (.o) → File compilati ma non ancora eseguibili
# File libreria (.a) → Librerie compilate (come libft.a) (SONO ESEGUIBILI)
# File eseguibile (push_swap) → Il programma finale che puoi eseguire
# quindi che sia .a o eseguibili non librerie, fclean li rimuove
fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean

# Target re: ricompila tutto da zero (fclean + all)
re: fclean all

# .PHONY dice a make: "questi (clean, fclean)
# NON sono nomi di file, sono solo comandi", esegui comendo
# Senza .PHONY: make clean direbbe "il file clean esiste già, non faccio niente"
# È una "garanzia" che i target vengano sempre eseguiti.
.PHONY: all clean fclean re push_swap checker

# ======================== CHECKER (aggiunta) =============================== #
# Sorgenti checker: tutti i .c in SRCS/checker

CHECKER_SRCS = $(wildcard SRCS/checker/*.c)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

# Regola per compilare checker
# ovviamente -o checker specifica che il nome dell'eseguibile è checker
# make -C $(LIBFTDIR) compila la libft (va fatto prima di compilare checker)
checker: $(CHECKER_OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(CHECKER_OBJS) -o checker $(INCLUDE)
