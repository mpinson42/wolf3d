NAME = wolf3d

SRC = srcs/main.c srcs/pars.c srcs/lib.c srcs/event.c srcs/algo.c srcs/init.c srcs/menu.c srcs/affiche.c srcs/destroy.c srcs/bmp.c srcs/img.c

FLAGS = -Wall -Wextra -Werror

SRC2 = main.o pars.o lib.o event.o algo.o init.o menu.o affiche.o destroy.o bmp.o img.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@make -C ./minilibx_macos all
	@cp ./minilibx_macos/libmlx.a ./lib
	@cp ./libft/libft.a ./lib
	gcc  $(FLAGS) -lpthread  -I ./include/  -L./lib  -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC)
	afplay musique/enclume.mp3 &


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean
	afplay musique/destruction.mp3 &

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
