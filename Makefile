CC				=	gcc
INCLUDE			=	-I HEADERS
CFLAGS			=	-Wall -Wextra -Werror $(INCLUDE)
NAME			=	cub3d
GP_LIBS			=	-framework OpenGL -framework AppKit

Libft			=	Libft/libft.a
GNL_utils		=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SOURCE_FILES	=	main.c elems_constructor.c errors_handler.c get_map.c
OBJECT_FILES	=	$(SOURCE_FILES:.c=.o)

$(NAME): $(GNL_utils) $(Libft) $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(GP_LIBS) $(Libft) $(GNL_utils)  -o $(NAME)
$(Libft):
	cd Libft && make

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(OBJECT_FILES)

re: fclean $(NAME)