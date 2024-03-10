CC		=	clang++
CFLAGS	=	-std=c++17 -g
# CFLAGS	+=	-Werror -Wextra -Wall 

NAME 	=	kumite

.PHONY: clean, fclean, re

$(NAME): 
	$(CC) $(CFLAGS) -I . *.cpp -o $@

clean: 
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME).dSYM
	rm -rf $(NAME).zip

re: fclean $(NAME)

debug:
	lldb ./$(NAME)

arch: fclean
	zip $(NAME).zip *.*
