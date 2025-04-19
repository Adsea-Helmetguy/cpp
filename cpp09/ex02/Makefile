# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 09:41:23 by mlow              #+#    #+#              #
#    Updated: 2025/03/11 09:41:25 by mlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98 -MMD

SRC_DIR = .
INC_DIR = .

# ************************************************************************** */
#       SOURCE (#List of SOURCE(SRC) files)                                  */
# ************************************************************************** */
SRC_FILE_NAMES = main.cpp \
			PmergeMe.cpp \
			step42_splitpairs/split_pairs.cpp \
			print_values/print_mainpend.cpp \
			print_values/binary_leftover.cpp \
			deque_version/alt_binary.cpp \
			deque_version/alt_mainpend.cpp \
			deque_version/alt.cpp
			


# ************************************************************************** */
#       FILE_LOCATION                                                        */
# ************************************************************************** */
SRC_FILE_PATHS = $(addprefix $(SRC_DIR)/, $(SRC_FILE_NAMES))

OBJ_FILE_PATHS = $(SRC_FILE_PATHS:.cpp=.o)



# ************************************************************************** */
#       D.Files                                                              */
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

$(OBJ_FILE_PATHS): $(SRC_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -MMD -c $< -o $@

clean: 
	rm -f $(OBJ_FILE_PATHS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#It's not part of "re", not part of any rule's recipe
# it gets processed immediately when Make reads the Makefile
# Bascially, this line can be used ANYWHERE WHICHEVER LINE WHEHUEHE
-include $(DEPS)

PHONY: all clean fclean re
















