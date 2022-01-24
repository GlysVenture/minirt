CFLAGS := ${CFLAGS}
CFLAGS += -Wall -Wextra -Werror

CC     ?= gcc

MAKEFLAGS += --no-print-directory

NAME = raytracer

INC_FLAGS := -Igeotrace
LIB := geotrace/libgeotrace.a

LIBS := -Lgeotrace -lgeotrace -lm

SRCS = main.c
OBJS = ${SRCS:%=%.o}

%.c.o: %.c
	@echo Compiling $@
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

all:	library
	@$(MAKE) $(NAME)

$(NAME):	$(LIB) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) -o $(NAME)

library:
	@$(MAKE) -C geotrace

$(LIB):
	@$(MAKE) -C geotrace

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C geotrace clean
	@echo Clean done

fclean:
	@rm -rf $(OBJS)
	@rm -f $(NAME)
	@$(MAKE) -C geotrace fclean
	@echo Fclean done

re:		fclean all

.PHONY:	all clean fclean re