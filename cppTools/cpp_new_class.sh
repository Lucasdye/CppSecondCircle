#!/bin/bash

# Vérification du nombre d'arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 [nom_de_la_classe] [chemin_vers_le_repertoire]"
    exit 1
fi

# Récupération du nom de la classe et du chemin du répertoire depuis les arguments
class_name=$1
uppercase_class_name=$(echo "$class_name" | awk '{print toupper($0)}')
directory=$2
login=$USER
user=$(printf "%-*s" 8 ${login})
by=$(printf "%-*s" 37 "By: ${login} <${login}@student.42.fr>")
filename_hpp=$(printf "%-*s" 43 "$class_name.hpp" | cut -c1-43)
filename_cpp=$(printf "%-*s" 43 "$class_name.cpp" | cut -c1-43)

# Vérification si le répertoire existe
if [ ! -d "$directory" ]; then
    echo "Le répertoire spécifié n'existe pas."
    exit 1
fi

# Modèle de Makefile
custom_makefile=$(cat <<'EOM'
NAME = 
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
OBJ_DIR = objs/

SRC =	srcs/main.cpp \

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.cpp=.o)))

TOTAL_FILES := $(words $(SRC))
CURRENT_FILE = 0
PERCENTAGE = 0

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

define update_progress
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	@printf "$(GREEN)\rCompiling [%-20s] %d%%" "####################" "$(PERCENTAGE)"
endef

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)\nCompilation complete.$(RESET)"

$(OBJ_DIR)%.o: srcs/%.cpp | $(OBJ_DIR)
	$(call update_progress)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(YELLOW)Cleaning up...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)Full clean...$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean

EOM
)

# Modèle pour le fichier .hpp avec un en-tête standard
hpp_content="\
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${filename_hpp}        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   ${by}          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $(date "+%d/%m/%Y") $(date "+%H:%M:%S") by ${user}          #+#    #+#             */
/*   Updated: $(date "+%d/%m/%Y") $(date "+%H:%M:%S") by ${user}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ${uppercase_class_name}_HPP
# define ${uppercase_class_name}_HPP

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string.h>

class ${class_name}
{
private:



public:

    ${class_name}();
    ${class_name}(${class_name} const & src);
    ${class_name}& operator=(${class_name} const & instance);
    ~${class_name}();

};

#endif
"

# Modèle pour le fichier .cpp avec un en-tête standard
cpp_content="\
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${filename_cpp}        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   ${by}          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $(date "+%d/%m/%Y") $(date "+%H:%M:%S") by ${user}          #+#    #+#             */
/*   Updated: $(date "+%d/%m/%Y") $(date "+%H:%M:%S") by ${user}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include \"../incs/${class_name}.hpp\"

${class_name}::${class_name}()
{
	std::cout << ""\"Default constructor called for ${class_name}\""" << std::endl;
}

${class_name}::${class_name}(${class_name} const & src)
{
	std::cout << ""\"Copy constructor called for ${class_name}\""" << std::endl;
}

${class_name}&	${class_name}::operator=(${class_name} const & instance)
{
	std::cout << ""\"Assignment operator called for ${class_name}\""" << std::endl;
	if (this != &instance)
	{
	}
	return *this;
}

${class_name}::~${class_name}()
{
	std::cout << ""\"Destructor called for ${class_name}\""" << std::endl;
}

"

main_content="\
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   ${by}          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $(date "+%d/%m/%Y") $(date "+%H:%M:%S") by ${user}          #+#    #+#             */
/*   Updated: $(date "+%d/%m/%Y") $(date "+%H:%M:%S") by ${user}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include \"../incs/${class_name}.hpp\"

int	main()
{

	return (0);
}

"

#creation des dirs
if [ ! -e "${directory}/srcs" ]; then
	mkdir ${directory}/srcs
fi 

if [ ! -e "${directory}/incs" ]; then
	mkdir ${directory}/incs
fi 

# Création du Makefile avec le modèle
if [ ! -e "${directory}/Makefile" ]; then
	echo "$custom_makefile" > "${directory}/Makefile"
fi

# Création du fichier .hpp avec le modèle
if [ ! -e "${directory}/incs/${class_name}.hpp" ]; then
	echo "$hpp_content" > "${directory}/incs/${class_name}.hpp"
fi

# Création du fichier .cpp avec le modèle
if [ ! -e "${directory}/srcs/${class_name}.cpp" ]; then
	echo "$cpp_content" > "${directory}/srcs/${class_name}.cpp"
fi

# Création du fichier main.cpp avec le modèle
if [ ! -e "${directory}/srcs/main.cpp" ]; then
	echo "$main_content" > "${directory}/srcs/main.cpp"
fi

echo "${class_name}.cpp et ${class_name}.hpp ont été créés avec succès."
