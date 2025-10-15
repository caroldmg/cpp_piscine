NAME = ex03

SRCS = \
	src/main.cpp \
	src/AMateria.cpp \
	src/Character.cpp \
	src/Cure.cpp \
	src/Ice.cpp \
	src/MateriaSource.cpp \


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

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re