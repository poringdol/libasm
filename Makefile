SHELL = /bin/sh

FLAGS = -Wall -Werror -Wextra -g
FLAGS_OBJ = -f elf64

CC = gcc
ASM = nasm
AR = ar rs
RM = rm -rf

NAME = libasm.a
SRC = ft_strlen.s\
	  ft_strcpy.s\
	  ft_strcmp.s\
	  ft_write.s\
	  ft_read.s\
	  ft_strdup.s

TEST = test

OBJS = $(SRC:.s=.o)
OBJDIR = ./objects/
OBJ = $(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJDIR)%.o: %.s
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	$(ASM) $(FLAGS_OBJ) $< -o $@

$(TEST): $(NAME)
		$(CC) $(FLAGS) $@.c -L. -lasm -o $(TEST)
clean:
	@$(RM) $(OBJDIR)

fclean:
	$(RM) $(OBJDIR) $(NAME) $(TEST) *.txt

re: fclean all

.PHONY: all clean fclean re $(TEST)