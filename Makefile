CFLAGS := ${CFLAGS}
CFLAGS += -Wall -Wextra -Werror

CC     ?= gcc

MAKEFLAGS += --no-print-directory

NAME = raytracer

INC_FLAGS := -Igeotrace -Imlx -Ilibft
LIB := geotrace/libgeotrace.a
MLX_LIB := mlx/libmlx.a
LIBFT_LIB := libft/libft.a

GEO = geotrace
MLX = mlx
LIBFT = libft

LIBS = -Lgeotrace -Lmlx -Llibft -lgeotrace -lm -lmlx -lft

SRCS = main.c object.c camera.c
OBJS = ${SRCS:%=%.o}

%.c.o: %.c
	@echo Compiling $@
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

all:	library
	@$(MAKE) $(NAME)

$(NAME):	$(LIB) $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) -framework OpenGL -framework AppKit $(OBJS) $(LIBS) -o $(NAME)

library:
	@$(MAKE) -C ${LIBFT} bonus
	@$(MAKE) -C ${GEO}
	@$(MAKE) -C ${MLX}

$(LIB):
	@$(MAKE) -C ${GEO}

$(MLX_LIB):
	@$(MAKE) -C ${MLX}

$(LIBFT_LIB):
	@$(MAKE) -C ${LIBFT} bonus

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C ${GEO} clean
	@$(MAKE) -C ${MLX} clean
	@$(MAKE) -C ${LIBFT} clean
	@echo Clean done

fclean:
	@rm -rf $(OBJS)
	@rm -f $(NAME)
	@$(MAKE) -C ${GEO} fclean
	@$(MAKE) -C ${MLX} clean
	@$(MAKE) -C ${LIBFT} fclean
	@echo Fclean done

re:		fclean all

.PHONY:	all clean fclean re