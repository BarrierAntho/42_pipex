# Test definitiona
TESTPATH	:=	test
TESTFILE1	:=	file1
TESTFILE2	:=	file2
RESFILE		:=	res.txt

# Color definition
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
#VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes
VALGRIND	:=	

IPATH		:=	include
OPATH		:=	obj

# SOURCES FOLDER
SRCSPATH	:=	srcs
CMDPATH		:=	cmd
LISTPATH	:=	list

RM		:=	rm -rf

PPX_SRCS	:=	pipex.c\
			ppx_pipex_run.c

CMD_SRCS	:=	ppx_cmd_free.c\
			ppx_cmd_getvalidpath.c\
			ppx_cmd_init.c\
			ppx_cmd_init_prop.c\
			ppx_cmd_loop_envline.c\
			ppx_cmd_loop_envp.c\
			ppx_cmd_loop_envp_str.c\
			ppx_cmd_setpath.c\
			ppx_cmd_show.c

LIST_SRCS	:=	ppx_lst_set.c

SRCS		:=	$(PPX_SRCS)\
			$(CMD_SRCS)\
			$(LIST_SRCS)

OBJS		=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))

DEPS		=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCSPATH)\
	$(SRCSPATH)/$(CMDPATH)\
	$(SRCSPATH)/$(LISTPATH)\
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
			make fclean -C $(FTPATH)
			make clean
			$(RM) $(NAME)

re:
			make re -C $(FTPATH)
			make fclean
			make all

norme:
			@echo norme:
			norminette
			@echo $(SEP_P)

ori_0p:
			make --no-print-directory -i test_echo
			make --no-print-directory -i test_ls

mktest:
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_delete_test_data,$(TESTPATH))
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
	
test_echo:
			echo ""
			@echo "$(YE)$(SEP_P)$(NC)"
			echo "test"
			@echo "$(YE)$(SEP_P)$(NC)"
			echo Hello World
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
			echo $(TESTPATH)
			@$(call f_delete_test_data,$(TESTPATH))
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
			< $(TESTPATH)/$(TESTFILE1) echo
			@$(call f_delete_test_data,$(TESTPATH))
			@echo "$(YE)$(SEP_P)$(NC)"

test_ls:
			ls ""
			@echo "$(YE)$(SEP_P)$(NC)"
			ls
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
			ls $(TESTPATH)
			@$(call f_delete_test_data,$(TESTPATH))
			@echo "$(YE)$(SEP_P)$(NC)"

test:
			@$(call f_delete_test_file,$(RESFILE))
			$(VALGRIND) ./$(NAME) $(TESTPATH) "cat -e -n" "ls" $(TESTPATH)/$(TESTFILE2) | tee -a $(RESFILE)
			@echo "$(YE)$(SEP_P)$(NC)" | tee -a $(RESFILE)
			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "cat -e -n" "wc" $(TESTPATH)/$(TESTFILE2) | tee -a $(RESFILE)
			@echo "$(YE)$(SEP_P)$(NC)" | tee -a $(RESFILE)
			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "/bin/cat" "ls" $(TESTPATH)/$(TESTFILE2) | tee -a $(RESFILE)
			@echo "$(YE)$(SEP_P)$(NC)" | tee -a $(RESFILE)
			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "/usr/bin/cat" "ls" $(TESTPATH)/$(TESTFILE2) | tee -a $(RESFILE)
			@echo "$(YE)$(SEP_P)$(NC)" | tee -a $(RESFILE)
			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "/usr/bin/cat" "prout" $(TESTPATH)/$(TESTFILE2) | tee -a $(RESFILE)
			@echo "$(YE)$(SEP_P)$(NC)" | tee -a $(RESFILE)
			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "toto" "tata" $(TESTPATH)/$(TESTFILE2) | tee -a $(RESFILE)
			@echo "$(YE)$(SEP_P)$(NC)" | tee -a $(RESFILE)
#			< test cat | ls > test/file2
#			$(VALGRIND) ./$(NAME) $(TESTPATH) cat ls $(TESTPATH)/$(TESTFILE2)
#			< test ls | ls > test/file2
#			$(VALGRIND) ./$(NAME) $(TESTPATH) ls ls $(TESTPATH)/$(TESTFILE2)

define f_create_test_dir
	@mkdir -p $(1) && echo "$(CY)Creation of test directory \"$(1)\" successed$(NC)"
endef

define f_delete_test_dir
	$(RM) $(1) && echo "$(CY)Deletion of test directory \"$(1)\" successed$(NC)"
endef

define f_create_test_file
	@touch "$(1)" && echo "$(CY)Creation of test file \"$(1)\" successed$(NC)"
	@echo "This is the file \"$(1)\"" > $(1)
endef

define f_delete_test_file
	$(RM) $(1) && echo "$(CY)Deletion of test file \"$(1)\" successed$(NC)"
endef

define f_create_test_data
	$(call f_create_test_dir,$(1))
	$(call f_create_test_file,$(1)/$(2))
	$(call f_create_test_file,$(1)/$(3))
endef

define f_delete_test_data
	$(call f_delete_test_dir,$(1))
endef

-include $(DEPS)

.PHONY:			all clean fclean re norme ori_0p mktest test_echo test_ls test
