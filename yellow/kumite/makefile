CC		=	clang++
CFLAGS	=	-std=c++17 -g

NAME 	=	kumite

.PHONY: clean, fclean, re

$(NAME): 
	$(CC) $(CFLAGS) -I . *.cpp -o $@

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)

debug:
	lldb ./$(NAME)
