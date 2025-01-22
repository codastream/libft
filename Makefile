NAME:=		libft.a

CC:=		cc
CFLAGS:=	-Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -g
endif

ifdef FPIE
	CFLAGS += -fPIE
endif

SRC_DIR:=		./
HEADER_DIR:=	./
INCLUDE_DIR:= 	./includes
LIBFT_DIR:=		libft
OBJ_DIR:= 		./

SRCS_FILES =	array/ft_has_unique_values_array.c\
				array/ft_quick_sort.c\
				array/ft_count_2dchar_null_ended.c\
				array/ft_count_3dchar_null_ended.c\
				conversion/ft_atoi_base.c\
				conversion/ft_hextoi.c\
				conversion/ft_atoi.c\
				conversion/ft_atol.c\
				conversion/ft_atoull.c\
				conversion/ft_convert_base.c\
				conversion/ft_is_out_of_int_range.c\
				conversion/ft_itoa.c\
				conversion/ft_ltoa.c\
				conversion/ft_lutoa_base.c\
				data/hash_print.c\
				data/hash.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				list/ft_lstadd_back.c\
				list/ft_lstadd_front.c\
				list/ft_lstclear.c\
				list/ft_lstdelone.c\
				list/ft_lstiter.c\
				list/ft_lstlast.c\
				list/ft_lstmap.c\
				list/ft_lstnew.c\
				list/ft_lstsize.c\
				math/ft_isprime.c\
				math/ft_iseven.c\
				mem/ft_bzero.c\
				mem/ft_calloc.c\
				mem/ft_free2d.c\
				mem/ft_memchr.c\
				mem/ft_memcmp.c\
				mem/ft_memcpy.c\
				mem/ft_memmove.c\
				mem/ft_memset.c\
				print/ft_print_address.c\
				print/ft_print_array_int.c\
				print/ft_print_tabstr.c\
				print/ft_print_char.c\
				print/ft_print_hexa.c\
				print/ft_print_integer.c\
				print/ft_print_str.c\
				print/ft_print_unsigned.c\
				print/ft_printf.c\
				print/ft_putchar_fd.c\
				print/ft_putendl_fd.c\
				print/ft_putnbr_fd.c\
				print/ft_putstr_fd.c\
				print/ft_puterr.c\
				print/ft_print_color.c\
				printfd/ft_print_address_fd.c\
				printfd/ft_print_char_fd.c\
				printfd/ft_print_hexa_fd.c\
				printfd/ft_print_integer_fd.c\
				printfd/ft_print_str_fd.c\
				printfd/ft_print_unsigned_fd.c\
				printfd/ft_printfd.c\
				splitter/delimiters.c\
				splitter/delimiters2.c\
				splitter/free.c\
				splitter/ft_splitter.c\
				splitter/init.c\
				splitter/separators.c\
				string/ft_isalpha.c\
				string/ft_isalnum.c\
				string/ft_isdigit.c\
				string/ft_isemptystr.c\
				string/ft_isascii.c\
				string/ft_isnumstr.c\
				string/ft_isprint.c\
				string/ft_split.c\
				string/ft_split_str.c\
				string/ft_strcat.c\
				string/ft_strcmp.c\
				string/ft_strdup.c\
				string/ft_striteri.c\
				string/ft_strjoin.c\
				string/ft_strlcat.c\
				string/ft_strlcpy.c\
				string/ft_strlen.c\
				string/ft_strmapi.c\
				string/ft_strncmp.c\
				string/ft_strnstr.c\
				string/ft_strchr.c\
				string/ft_strchri.c\
				string/ft_strstri.c\
				string/ft_strcharsi.c\
				string/ft_strrchr.c\
				string/ft_strtrim.c\
				string/ft_substr.c\
				string/ft_toupper.c\
				string/ft_tolower.c\

SRCS:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS:= $(SRCS:.c=.o)

#=========#
# TARGETS #
#=========#

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
