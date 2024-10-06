CC		=	clang++
CFLAGS	=	-std=c++17 -Wextra -Wall -Werror

NAME 	=	learner	

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
