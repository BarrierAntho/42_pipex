# Test definitiona
TESTPATH	:=	test
TESTFILE1	:=	file1
TESTFILE2	:=	file2
DIR_F1		:=	$(TESTPATH)/$(TESTFILE1)
DIR_F2		:=	$(TESTPATH)/$(TESTFILE2)
RES_ORI		:=	res_origin.txt
RES_MYPPX		:=	res_mypppx.txt

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

MAIN_SRCS	:=	pipex.c

MAIN_BONUS_SRCS	:=	pipex_bonus.c

PPX_SRCS	:=	ppx_file_access.c\
			ppx_pipex_cmd.c\
			ppx_pipex_run.c\
			ppx_pipex_wait.c

CMD_SRCS	:=	ppx_cmd_close_fd.c\
			ppx_cmd_free.c\
			ppx_cmd_getvalidpath.c\
			ppx_cmd_init.c\
			ppx_cmd_init_prop.c\
			ppx_cmd_init_prop_null.c\
			ppx_cmd_loop_envline.c\
			ppx_cmd_loop_envp.c\
			ppx_cmd_loop_envp_str.c\
			ppx_cmd_setpath.c\
			ppx_cmd_show.c

LIST_SRCS	:=	ppx_lst_fd.c\
			ppx_lst_fd_infile.c\
			ppx_lst_fd_outfile.c\
			ppx_lst_fd_pfd.c\
			ppx_lst_set.c

SRCS		:=	$(MAIN_SRCS)\
			$(PPX_SRCS)\
			$(CMD_SRCS)\
			$(LIST_SRCS)

SRCS_BONUS	:=	$(MAIN_BONUS_SRCS)\
			$(PPX_SRCS)\
			$(CMD_SRCS)\
			$(LIST_SRCS)

OBJS		=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))

OBJS_BONUS	=	$(addprefix $(OPATH)/, $(SRCS_BONUS:.c=.o))

DEPS		=	$(OBJS:.o=.d)

DEPS_BONUS	=	$(OBJS_BONUS:.o=.d)

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

$(OBJS_BONUS):		| $(OPATH)

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

bonus:			$(OBJS_BONUS)
			make -C $(FTPATH)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS_BONUS) -I $(IPATH) -I $(FTPATH)/$(IFT) -L$(FTPATH) -l$(FT) -o $(NAME)

norme:
			@echo norme:
			norminette
			@echo $(SEP_P)

mktest:
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_delete_test_data,$(TESTPATH),$(RES_ORI),$(RES_MYPPX))
			@echo "$(YE)$(SEP_P)$(NC)"
			@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
	
test:
			@$(call f_delete_test_file,$(RES_MYPPX))
			@$(call f_delete_test_file,$(RES_ORI))
			$(VALGRIND) ./$(NAME) '' '' '' ''
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "cat -e -n" "wc" $(TESTPATH)/$(TESTFILE2)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "cat -e -n" "head" "wc" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "cat -e -n" "ls" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "cat -e -n" "wc" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "/bin/cat" "ls" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "/usr/bin/cat" "ls" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "/usr/bin/cat" "prout" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			$(VALGRIND) ./$(NAME) $(TESTPATH)/$(TESTFILE1) "toto" "tata" $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX)
#			@echo "$(YE)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(TESTPATH)/$(TESTFILE2) >> $(RES_MYPPX
#			@echo "$(RD)$(SEP_P)$(NC)" >> $(RES_MYPPX)
#			cat $(RES_MYPPX)
#			< test cat | ls > test/file2
#			$(VALGRIND) ./$(NAME) $(TESTPATH) cat ls $(TESTPATH)/$(TESTFILE2)
#			< test ls | ls > test/file2
#			$(VALGRIND) ./$(NAME) $(TESTPATH) ls ls $(TESTPATH)/$(TESTFILE2)


test_ori:
			$(call f_test_ori)

test_myppx:
			$(call f_test_myppx)

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
	@$(call f_delete_test_dir,$(1))
	@$(call f_delete_test_file,$(2))
	@$(call f_delete_test_file,$(3))
endef

define f_test_ori

	@$(call f_delete_test_file,$(TESTPATH))
	@$(call f_delete_test_file,$(RES_ORI))
	@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
	< $(DIR_F1) cat | wc > $(DIR_F2)
	cat $(DIR_F2) >> $(RES_ORI)
	cat $(RES_ORI)
	@echo "$(YE)$(SEP_P)$(NC)"

endef

define f_test_myppx
	@$(call f_delete_test_file,$(TESTPATH))
	@$(call f_delete_test_file,$(RES_MYPPX))
	@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
	./$(NAME) $(DIR_F1) "cat" "wc" $(DIR_F2)
	cat $(DIR_F2) >> $(RES_MYPPX)
	@echo "$(YE)$(SEP_P)$(NC)"
	@$(call f_delete_test_file,$(TESTPATH))
	@$(call f_create_test_data,$(TESTPATH),$(TESTFILE1),$(TESTFILE2))
	./$(NAME) $(DIR_F1) "cat" "ls" $(DIR_F2)
	cat $(DIR_F2) >> $(RES_MYPPX)
	@echo "$(YE)$(SEP_P)$(NC)"
	cat $(RES_MYPPX)
endef

define f_test_compare
	diff $(1) $(2)
endef

-include $(DEPS)

-include $(DEPS_BONUS)

.PHONY:			all clean fclean re bonus norme mktest test test_ori test_myppx
