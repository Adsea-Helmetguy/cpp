# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:14:15 by mlow              #+#    #+#              #
#    Updated: 2025/01/15 18:17:44 by mlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98 -MMD
#MMD means --write-user-dependencies

SRC_DIR = .
INC_DIR = .

# ************************************************************************** */
#	SOURCE                                                               */
# ************************************************************************** */
#List of SOURCE(SRC) files
SRC_FILE_NAMES = main.cpp \
			Span.cpp



# ************************************************************************** */
#	FILE_LOCATION                                                        */
# ************************************************************************** */
SRC_FILE_PATHS = $(addprefix $(SRC_DIR)/, $(SRC_FILE_NAMES))

OBJ_FILE_PATHS = $(SRC_FILE_PATHS:.cpp=.o)



# ************************************************************************** */
#	D.Files                                                              */
# ************************************************************************** */
#We need to Create a target for ".d" files from our object files
# to let make know the affected .cpp/.o files are dependent on which .h files.
# try using cat "file.d" to see what's inside, should have a .hpp inside.
DEPS = $(OBJ_FILE_PATHS:.o=.d)



# ************************************************************************** */
#	RULES                                                                */
# ************************************************************************** */
all: $(NAME)

$(NAME): $(OBJ_FILE_PATHS)
	$(CXX) $(CXXFLAGS) $(OBJ_FILE_PATHS) -o $(NAME)

#make -C goes to that path directory's makefile and make using that makefile

$(OBJ_FILE_PATHS): $(SRC_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -MMD -c $< -o $@


#Creating rules to compile individual source files for bonus to object files
clean: 
	rm -f $(OBJ_FILE_PATHS) $(DEPS)

#clear .o files including static library $(NAME)
fclean: clean
	rm -f $(NAME)

#clean files and remake "all"
re: fclean all

#It's not part of "re", not part of any rule's recipe
# it gets processed immediately when Make reads the Makefile
# Bascially, this line can be used ANYWHERE WHEHUEHE
-include $(DEPS)

PHONY: all clean fclean re
