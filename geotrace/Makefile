SHELL = /bin/sh

CFLAGS := ${CFLAGS}
CFLAGS += -Wall -Wextra -Werror

CC     ?= gcc

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
else
	NPROC := $(shell sysctl -n hw.ncpu)
endif

INC_FLAGS = -I$(shell pwd)

NAME = libgeotrace.a

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

all:
	@$(MAKE) -j$(NPROC) $(NAME)

$(NAME):	$(OBJS)
	@echo Linking $@
	@ar -rcs $(NAME) $(OBJS)

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS)  $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)

re: fclean
	@$(MAKE) -j$(NPROC) $(NAME)

.PHONY: all clean fclean re
