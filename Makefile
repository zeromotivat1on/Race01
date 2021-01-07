NAME = part_of_the_matrix

SRC_FILES = $(wildcard src/*.c)
INC_FILES = $(wildcard inc/*.h)

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -o $(NAME)

all: install

install: $(NAME)

$(NAME): $(SRC_FILES)
	clang $(CFLAGS) $(SRC_FILES)

clean:
	@rm -rf $(NAME)

uninstall: clean

reinstall: uninstall all

.PHONY: all uninstall clean reinstall
