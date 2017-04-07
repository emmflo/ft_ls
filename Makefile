OBJDIR := objs
SRCDIR := srcs
OBJLIST := \
	options.o \
	errors.o \
	main.o \
	sort.o \
	ls.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L libft -lft
CC := clang
INCDIR := -I./libft/includes -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := ft_ls

.PHONY : all clean fclean re libft libft_clean libft_fclean

all : $(NAME)
	
$(NAME) : libft/libft.a $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIB)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

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
