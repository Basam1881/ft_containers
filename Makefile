# Colors
PURPLE			= \033[1;35m
BLUE			= \033[1;34m
WHITE			= \033[1;37m
LIGHT_BLUE		= \033[1;36m
GREEN			= \033[1;32m
RED				= \033[1;31m
BYELLOW			= \033[1;33m
IYELLOW			= \033[3;33m
LIGHT_GREEN		= \033[38;5;46m
GREY 			= \033[38;5;8m
ORANGE 			= \033[38;5;202m
NO_COLOR  		= \033[m
BGBLUE			= \033[46;5;1m
# Name Of The Author
AUTHOR = Bassam

# Intra Username
Intra_Login = Bnaji

# Project Name
PROJECT_NAME = ft_containers

# Starting Date of the project
DATE = 27 - 05 - 2022

CPP_FILES = main.cpp vectorTests.cpp vTBasic.cpp vTIterators.cpp vTRIterators.cpp vTCIterators.cpp vTCRIterators.cpp

SRC_NAME = $(addprefix $(OBJ_DIR), ${CPP_FILES})

SRC_DIR = srcs/

# Object Files
OBJ_NAME = $(addprefix $(OBJ_DIR), ${CPP_FILES:%.cpp=%.o})

OBJ_DIR = objs/

# Compiliation command
CXX = c++ -g

# Compilation flags
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

# Executable file's name
NAME = container

all: header $(NAME) footer

$(NAME): nothing $(OBJ_DIR) $(OBJ_NAME)
	@$(CXX) ${CXX_FLAGS} $(OBJ_NAME) -o $(NAME)
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Executable File Is Ready\n$(NO_COLOR)"

nothing:
	@echo "\n\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)generating $@\n$(NO_COLOR)"
	@$(CXX) ${CXX_FLAGS} -c $< -o $@

header:
	@printf "\n%b" "$(NO_COLOR)"
	@echo
	@echo "$(BGBLUE)\t\t ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄ $(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌ ▐░░░░░░░░░▌ ▐░░░░░░░░░░░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█░█▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌       ▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄█░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌  ▐░▌ ▐░░░░░░░░░▌ $(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░▌          ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀█░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░▌          ▐░▌          ▐░▌          ▐░▌    ▐░▌▐░▌▐░▌       ▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌          ▐░█▄▄▄▄▄█░█░▌▐░█▄▄▄▄▄▄▄█░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t▐░░░░░░░░░░░▌▐░▌          ▐░▌           ▐░░░░░░░░░▌ ▐░░░░░░░░░░░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t ▀▀▀▀▀▀▀▀▀▀▀  ▀            ▀             ▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀ $(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t ▄▄▄▄▄▄▄▄▄▄▄  ▄       ▄  ▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄  $(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░░░░░░░░░░░▌▐░▌     ▐░▌▐░░░░░░░░░▌ ▐░░░░░░░░░▌ $(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░█▀▀▀▀▀▀▀▀▀  ▐░▌   ▐░▌▐░█░█▀▀▀▀▀█░▐░█░█▀▀▀▀▀█░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░▌            ▐░▌ ▐░▌ ▐░▌▐░▌    ▐░▐░▌▐░▌    ▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░█▄▄▄▄▄▄▄▄▄    ▐░▐░▌  ▐░▌ ▐░▌   ▐░▐░▌ ▐░▌   ▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░░░░░░░░░░░▌    ▐░▌   ▐░▌  ▐░▌  ▐░▐░▌  ▐░▌  ▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░█▀▀▀▀▀▀▀▀▀    ▐░▌░▌  ▐░▌   ▐░▌ ▐░▐░▌   ▐░▌ ▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░▌            ▐░▌ ▐░▌ ▐░▌    ▐░▌▐░▐░▌    ▐░▌▐░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░█▄▄▄▄▄▄▄▄▄  ▐░▌   ▐░▌▐░█▄▄▄▄▄█░█░▐░█▄▄▄▄▄█░█░▌$(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t▐░░░░░░░░░░░▌▐░▌     ▐░▌▐░░░░░░░░░▌ ▐░░░░░░░░░▌ $(NO_COLOR)"
	@echo "$(BGBLUE)\t\t\t ▀▀▀▀▀▀▀▀▀▀▀  ▀       ▀  ▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀  $(NO_COLOR)"
	@echo
	@printf "\t\t\t\t$(LIGHT_GREEN)AUTHORS\t\t:\t$(WHITE)%b\n$(NO_COLOR)" "$(AUTHOR)"
	@printf "\t\t\t\t$(LIGHT_GREEN)Intra Login\t:\t$(WHITE)%b\n$(NO_COLOR)" "$(Intra_Login)"
	@printf "\t\t\t\t$(LIGHT_GREEN)NAME\t\t:\t$(WHITE)%b\n$(NO_COLOR)" "$(PROJECT_NAME)"
	@printf "\t\t\t\t$(LIGHT_GREEN)DATE\t\t:\t$(WHITE)%b\n\n$(NO_COLOR)" "$(DATE)"
	@echo "\t$(BYELLOW)LOADING...$(NO_COLOR)\n"

footer:
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡"
	@echo "$(BYELLOW)⚡\t\t\t\t\t$(BYELLOW)READY\t\t\t\t\t\t$(BYELLOW)⚡"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡$(NO_COLOR)"

clean_o_files:
	@rm -rf $(OBJ_DIR)
	@echo "\n\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)object files are Deleted\n$(NO_COLOR)"

clean_exec_file:
	@rm -rf $(NAME)
	@echo "\n\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Executable file is Deleted\n$(NO_COLOR)"


clean: header clean_o_files footer

fclean: header clean_o_files clean_exec_file footer

re: header clean_o_files clean_exec_file $(NAME) footer

.PHONY: all clean fclean re