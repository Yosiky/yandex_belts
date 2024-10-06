CC		=	clang++
CFLAGS	=	-std=c++17 -Wextra -Wall -Werror

NAME 	=	sort_student	

.PHONY: run clean fclean re debug

run: $(NAME)
	./$(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -I . *.cpp -o $@

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)

debug:
	lldb ./$(NAME)
