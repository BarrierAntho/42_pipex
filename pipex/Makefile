#Color definition
BASE		:=	\033[
RD		:=	$(BASE)0;31m
GN		:=	$(BASE)0;32m
OG		:=	$(BASE)0;33m
BU		:=	$(BASE)0;34m
MG		:=	$(BASE)0;35m
CY		:=	$(BASE)0;36m
YE		:=	$(BASE)1;33m
NC		:=	$(BASE)0m

##############################
# libft settings
FTPATH		:=	libft
IFT		:=	include
FTHEADER	:=	ft_libft.h
TFNAME		:=	libft.a
FT		:=	ft

# Standard settings
SEP_P		:=	"----------------------------------------------"
SEP_S		:=	".............................................."
NAME		:=	pipex
CC		:=	cc
CFLAGS		:=	-MMD -Wall -Wextra -Werror
#CFLAGSADD	:=	-Wconversion -g3 -fsanitize=address
#CFLAGSADD	:=	-g3 -fsanitize=address
CFLAGSADD	:=
VALGRIND	:=	valgrind

IPATH		:=	include
OPATH		:=	obj

# SOURCES FOLDER
SRCSPATH	:=	srcs
PARSEPATH	:=	parse

RM		:=	rm -rf

PPX_SRCS	:=	pipex.c

PARSE_SRCS	:=	ppx_parse.c

SRCS		:=	$(PPX_SRCS)\
			$(PARSE_SRCS)

OBJS		=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))

DEPS		=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCSPATH)\
	$(SRCSPATH)/$(PARSEPATH)
vpath %.o $(OPATH)

all:			$(NAME)

$(OPATH)/%.o:		%.c
			$(CC) $(CFLAGS) $(CFLAGSADD) -I $(IPATH) -I $(FTPATH)/$(IFT) -c $< -o $@

$(NAME):		$(OBJS)
			make -C $(FTPATH)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS) -I $(IPATH) -I $(FTPATH)/$(IFT) -L$(FTPATH) -l$(FT) -o $(NAME)

$(OBJS):		| $(OPATH)

$(OPATH):
			mkdir -p $(OPATH)

clean:
			make clean -C $(FTPATH)
			$(RM) $(OPATH)

fclean:
			make flean -C $(FTPATH)
			make clean
			$(RM) $(NAME)

re:
			make re -C $(FTPATH)
			make fclean
			make all

norme:
			@echo 3norme:
			norminette
			@echo $(SEP_P)

-include $(DEPS)

.PHONY:			all clean fclean re norme
