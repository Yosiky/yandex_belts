CC		=	clang++
CFLAGS	=	--std=c++17
# CFLAGS	+= -g

.PHONY: all

vector_part:
	$(CC) $(CFLAGS) $(SRC_BASE_REGION) -I . $@.cpp -o $@

set_part:
	$(CC) $(CFLAGS) $(SRC_BASE_REGION) -I . $@.cpp -o $@

split_into_words:
	$(CC) $(CFLAGS) $(SRC_BASE_REGION) -I . $@.cpp -o $@

fclean: 
	rm -rf $(NAME)
