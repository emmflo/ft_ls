OBJDIR := objs
SRCDIR := srcs
OBJLIST := \
	options.o \
	errors.o \
	main.o \
	sort.o \
	display.o \
	prefs.o \
	xattr.o \
	acls.o \
	ls.o \
	print.o \
	ft_itoa.o \
	display_utils.o \
	colors.o \
	columns.o \
	sizes.o \
	sizes2.o \
	display_l.o \
	display_print.o \
	display_to_str.o \
	display_x.o \
	display_str_name.o \
	display_1.o \
	display_m.o \
	display_c_.o \
	display_date.o \
	get_color.o \
	get_total.o \
	display_permissions.o \
	permissions_helpers.o \
	ls_makefile.o \
	ls_sizecmp.o \
	ls_namecmp.o \
	ls_btimcmp.o \
	ls_ctimcmp.o \
	ls_atimcmp.o \
	ls_mtimcmp.o \
	ls_timcmp.o \
	ls_filter.o \
	ls_recursive.o \
	ls_utils.o \
	ls_sort.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
DEPS := $(OBJS:.o=.d)
LIB := -L libft -lft
CC := clang
INCDIR := -I./libft/includes -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
#CFLAGS := $(INCDIR)
NAME := ft_ls
DEBUG := -g

.PHONY : all clean fclean re libft libft_clean libft_fclean

all : $(NAME)
	
$(NAME) : libft/libft.a $(OBJS)
	$(CC) $(DEBUG) $(OBJS) -o $@ $(LIB)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(DEBUG) $(CFLAGS) -MMD -MT "$@" -MP -c $< -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean : libft_clean
	-rm -r $(OBJDIR)

fclean : libft_fclean
	-rm $(NAME)
	-rm -r $(OBJDIR)

re : fclean all
	
libft/libft.a :
	make -C libft

libft_clean :
	make clean -C libft

libft_fclean :
	make fclean -C libft

-include $(DEPS)
