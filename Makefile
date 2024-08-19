PRINTF_DIR = ../ft_printf
LIBPRINTF = $(PRINTF_DIR)/libftprintf.a

NAME = ft_fprintf.a

SOURCES = $(wildcard *.c)

OBJS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CFLAGS += -I$(LIBPRINTF)

AR = ar rcs
RANLIB = ranlib
REMOVE = rm -f

LINKER_FLAGS = -L$(LIBPRINTF) -lftprintf
#The linker auto add the "lib" prefix, so when we pass
#the command -lftprintf we are actually calling:
# -l LIB ftprintf, and the linker also adds the suffix .a
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $

clean:
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re