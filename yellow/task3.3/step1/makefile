CC		=	clang++
CFLAGS	=	--std=c++17 -g

SRC_BASE_REGION = 	phone_number.cpp 	\
				  	main.cpp

NAME	=	phone_number

.PHONY: all

all:
	$(CC) $(CFLAGS) $(SRC_BASE_REGION) -I . -o $(NAME)

fclean: 
	rm -rf $(NAME)
