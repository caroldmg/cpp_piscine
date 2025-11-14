
NAME = ex02

# COLORS
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \33[0;33m
RESET := \033[0m

SRCS = \
	src/main.cpp \
	src/Bureaucrat.cpp \
	src/PresidentialPardonForm.cpp \
	src/ShrubberyCreationForm.cpp \
	src/RobotomyRequestForm.cpp \
	src/AForm.cpp \

OBJS = $(SRCS:src/%.cpp=objs/%.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -g3 #-Wshadow

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

# regla para compilar .cpp en .o dentro de objetos/
objs/%.o: src/%.cpp | objs
	$(CC) $(CPPFLAGS) -c $< -o $@

# crear la carpeta objetos si no existe
objs:
	@mkdir -p objs

all: $(NAME)

clean:
	@rm -rf objs
	@echo "$(YELLOW)\t 🧹 Limpito! 🧽 $(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
