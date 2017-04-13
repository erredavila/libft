# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdavila <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 13:18:39 by rdavila           #+#    #+#              #
#    Updated: 2017/04/13 11:52:20 by rdavila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

LIBFTDIR = src
PRINTFDIR = src/ft_printf
BUILDDIR = obj

LIBFT = ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c		ft_memmove.c \
		ft_memchr.c		ft_memcmp.c		ft_strlen.c		ft_strdup.c			ft_strcpy.c	\
		ft_strncpy.c	ft_strcat.c		ft_strncat.c	ft_strlcat.c		ft_strchr.c \
		ft_strrchr.c	ft_strstr.c		ft_strnstr.c	ft_strcmp.c			ft_strncmp.c \
		ft_atoi.c		ft_isalpha.c	ft_isdigit.c	ft_isalnum.c		ft_isascii.c \
		ft_isprint.c	ft_toupper.c	ft_tolower.c	ft_memalloc.c		ft_memdel.c \
		ft_strnew.c		ft_strdel.c		ft_strclr.c		ft_striter.c		ft_striteri.c \
		ft_strmap.c 	ft_strmapi.c 	ft_strequ.c 	ft_strnequ.c		ft_strsub.c \
		ft_strjoin.c	ft_strtrim.c	ft_strsplit.c	ft_itoa.c			ft_putchar.c \
		ft_putstr.c		ft_putendl.c	ft_putnbr.c		ft_putchar_fd.c		ft_putstr_fd.c \
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_lstnew.c		ft_lstdelone.c		ft_lstdel.c \
		ft_lstadd.c 	ft_lstiter.c	ft_lstmap.c		ft_lstadd_back.c	ft_create_elem.c \
		ft_lstsize.c	ft_print_list.c	ft_strrev.c		ft_num_length.c		ft_count_words.c \
		ft_only_digit.c	ft_tochar.c		ft_putnstr.c	ft_itoa_base.c		ft_strnlen.c \
		ft_max.c		ft_num_length_base.c			ft_putnbrbase.c		ft_atoi_base.c \
		ft_putwchar.c	ft_abs.c

PRINTF = ft_printf.c \
		format_parser.c \
		length_parser.c \
		add_padding.c \
		generic_unsigned.c \
		handle_percent.c \
		handle_str.c \
		handle_wstr.c \
		handle_char.c \
		handle_wchar.c \
		handle_int.c \
		handle_hex.c \
		handle_octal.c \
		handle_unsigned.c \
		handle_ptr.c \
		handle_null.c

LIBFTSRC = $(patsubst %, $(LIBFTDIR)/%, $(LIBFT))
PRINTFSRC = $(patsubst %, $(PRINTFDIR)/%, $(PRINTF))

LIBFTOBJ = $(patsubst %.c, %.o, $(LIBFT))
PRINTFOBJ = $(patsubst %.c, %.o, $(PRINTF))

LIBFTOBJDIR = $(patsubst %.c, $(BUILDDIR)/%.o, $(LIBFT))
PRINTFOBJDIR = $(patsubst %.c, $(BUILDDIR)/%.o, $(PRINTF))

all: $(NAME)

$(NAME):
		gcc $(FLAGS) $(INCLUDES) -c $(LIBFTSRC)
		gcc $(FLAGS) $(INCLUDES) -c $(PRINTFSRC)
		mkdir -p $(BUILDDIR)
		mv $(LIBFTOBJ) $(PRINTFOBJ) $(BUILDDIR)
	    ar rc $(NAME) $(LIBFTOBJDIR) $(PRINTFOBJDIR)
		ranlib $(NAME)

clean:
	    /bin/rm -rf $(BUILDDIR)

fclean: clean
		/bin/rm -rf $(NAME)

re: fclean all
