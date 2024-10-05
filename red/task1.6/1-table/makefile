CC		=	clang++
CFLAGS	=	-std=c++17 -Wextra -Wall -Werror

NAME 	=	table

.PHONY: clean fclean re debug

$(NAME): 
	$(CC) $(CFLAGS) -I . *.cpp -o $@

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)

debug:
	lldb ./$(NAME)
