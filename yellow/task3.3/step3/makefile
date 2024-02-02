CC		=	clang++
CFLAGS	=	--std=c++17

SRC_BASE_REGION = 	responses.cpp 	\
				  	query.cpp		\
				  	bus_manager.cpp	\
				  	main.cpp

HEADERS			=	query.h			\
					responses.h		\
					bus_manager.h	

NAME	=	test	

.PHONY: all

all:
	$(CC) $(CFLAGS) $(SRC_BASE_REGION) -I . -o $(NAME)

packed:
	tar -zcf arch.tar.gz $(SRC_BASE_REGION) $(HEADERS)

unpacked:
	tar -zxf arch.tar.gz
