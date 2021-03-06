##
## Makefile for trade in /Users/aurel/Documents/Epitech/trade-bis/
##
## Made by aurelien louisditpicard
## Login   <louisd_a@epitech.eu>
##
## Started on  Sat Jun  6 02:12:07 2015 aurelien louisditpicard
## Last update Sun Jun  7 23:46:05 2015 aurelien louisditpicard
##

CXX		= 	g++

NAME 	= 	trade

SRC 	= 	src/main.cpp		\
			src/trade.cpp		\
			src/indicator.cpp	\
			src/script.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS=	-I./include --std=c++11 -W -Wall -Wextra

LDFLAGS	=	-ldl

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:			fclean all
