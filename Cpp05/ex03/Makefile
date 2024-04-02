NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = objs/

SRC =	srcs/main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/ShrubberyCreationForm.cpp  srcs/PresidentialPardonForm.cpp srcs/RobotomyRequestForm.cpp

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
