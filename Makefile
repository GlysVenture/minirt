CFLAGS := ${CFLAGS}
CFLAGS += -g3 -fsanitize=address -Wall -Wextra -Werror

CC     ?= gcc

MAKEFLAGS += --no-print-directory

NAME = raytracer

UNAME = $(shell uname -s)

#libs
GEO_LIB := geotrace
LIBFT_LIB := ft

#dirs
GEO = geotrace
LIBFT = libft/
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

LIBS := -L${GEO} -L${LIBFT} -l${GEO_LIB} -l${LIBFT_LIB}
ifeq ($(UNAME), Linux)
	MLX = mlx_linux
	MLX_LIB := mlx
	LIBS += -L${MLX} -l${MLX_LIB}
	LIBS += -L/usr/include/../lib -lXext -lX11 -lm -lbsd
else
	MLX = mlx
	MLX_LIB := mlx
	LIBS += -L${MLX} -l${MLX_LIB}
	LIBS += -framework OpenGL -framework AppKit
endif

INC_FLAGS := -I${GEO} -I${LIBFT} -I${MLX} -I/usr/include -Isrc

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

all:	library
	@$(MAKE) $(NAME)

release: CFLAGS += -O3 -march=native
release: fclean
release: all

$(NAME):	$(GEO)/lib$(GEO_LIB).a $(MLX)/lib$(MLX_LIB).a $(LIBFT)/lib$(LIBFT_LIB).a $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -g3 -o $(NAME)

library:
	@$(MAKE) -e CFLAGS="${CFLAGS}" -C ${LIBFT}
	@$(MAKE) -e CFLAGS="${CFLAGS}" -C ${GEO}
	@$(MAKE) -C ${MLX} 2> /dev/null

$(GEO)/lib$(GEO_LIB).a:
	@$(MAKE) -e CFLAGS="${CFLAGS}" -C ${GEO}

$(MLX)/lib$(MLX_LIB).a:
	@$(MAKE) -C ${MLX}

$(LIBFT)/lib$(LIBFT_LIB).a:
	@$(MAKE) -e CFLAGS="${CFLAGS}" -C ${LIBFT}

clean:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) -C ${GEO} clean
	@$(MAKE) -C ${MLX} clean
	@$(MAKE) -C ${LIBFT} clean
	@echo Clean done

fclean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C ${GEO} fclean
	@$(MAKE) -C ${MLX} clean
	@$(MAKE) -C ${LIBFT} fclean
	@echo Fclean done

re:		fclean all

.PHONY:	all clean fclean re library
