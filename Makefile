NAME =	pipex

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   ./src/pipex.c \
		./src/pipex_utils.c 

SRC_B =	./src/pipex_bonus.c \
		./src/pipex_utils.c \
		./src/get_next_line.c \
		./src/get_next_line_utils.c

INC = 	-I libft/libft.h 	\
		-I src/pipex.h \
		-I src/get_next_line.h

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

OBJS_B =	$(SRC_B:.c=.o)
DEP_B =		$(SRC_B:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus:		$(OBJS_B)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_B} ./libft/libft.a -o ${NAME}


all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP) $(OBJS_B) $(DEP_B)
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)
-include $(DEP_B)