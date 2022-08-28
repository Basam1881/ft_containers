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

VEC_FILES = main.cpp vectorTests.cpp vTBasic.cpp\
						vTIterators.cpp vTRIterators.cpp\
						vTCIterators.cpp vTCRIterators.cpp\
						vTElementAccess.cpp vTCapacity.cpp\
						vTModifiers.cpp vTNonMemberFuncs.cpp\
						vTException.cpp

MAP_FILES = main.cpp ../$(COMMON_FILES)

STACK_FILES = main.cpp ../$(COMMON_FILES)

COMMON_FILES = PerformanceChecker.cpp

VEC_NAME = $(addprefix $(VEC_DIR), ${VEC_FILES})

MAP_NAME = $(addprefix $(MAP_DIR), ${MAP_FILES})

STACK_NAME = $(addprefix $(STACK_DIR), ${STACK_FILES})

SRC_DIR = srcs/

VEC_DIR = vectorTester/

MAP_DIR = mapTester/

STACK_DIR = stackTester/

# Vector Object Files
VEC_OBJ_NAME = $(addprefix $(OBJ_DIR), ${VEC_NAME:%.cpp=%.o})

# Map Object Files
MAP_OBJ_NAME = $(addprefix $(OBJ_DIR), ${MAP_NAME:%.cpp=%.o})

# Stack Object Files
STACK_OBJ_NAME = $(addprefix $(OBJ_DIR), ${STACK_NAME:%.cpp=%.o})

OBJ_DIR = objs/

# Compiliation command
CXX = c++ -g

# Compilation flags
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

# Vector Executable file's name
VNAME = ftvector

# Map Executable file's name
MNAME = ftmap

# Stack Executable file's name
SNAME = ftstack

NAME = ft

all: header $(NAME) footer

$(NAME) : $(MNAME)

$(VNAME): nothing $(OBJ_DIR) $(VEC_OBJ_NAME)
	@$(CXX) ${CXX_FLAGS} $(VEC_OBJ_NAME) -o $(VNAME)
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Executable File Is Ready\n$(NO_COLOR)"

$(MNAME): nothing $(OBJ_DIR) $(MAP_OBJ_NAME)
	@$(CXX) ${CXX_FLAGS} $(MAP_OBJ_NAME) -o $(MNAME)
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Executable File Is Ready\n$(NO_COLOR)"

$(SNAME): nothing $(OBJ_DIR) $(STACK_OBJ_NAME)
	@$(CXX) ${CXX_FLAGS} $(STACK_OBJ_NAME) -o $(SNAME)
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Executable File Is Ready\n$(NO_COLOR)"

nothing:
	@echo "\n\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)$(VEC_DIR) && mkdir -p $(OBJ_DIR)$(MAP_DIR) && mkdir -p $(OBJ_DIR)$(STACK_DIR)

$(OBJ_DIR)$(VEC_DIR)%.o : $(SRC_DIR)$(VEC_DIR)%.cpp
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)generating $@\n$(NO_COLOR)"
	@$(CXX) ${CXX_FLAGS} -c $< -o $@

$(OBJ_DIR)$(MAP_DIR)%.o : $(SRC_DIR)$(MAP_DIR)%.cpp
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)generating $@\n$(NO_COLOR)"
	@$(CXX) ${CXX_FLAGS} -c $< -o $@

$(OBJ_DIR)$(STACK_DIR)%.o : $(SRC_DIR)$(STACK_DIR)%.cpp
	@echo "\n\r\033[3A\033[0K\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)generating $@\n$(NO_COLOR)"
	@$(CXX) ${CXX_FLAGS} -c $< -o $@

header:
	@printf "\n%b" "$(NO_COLOR)"
	@echo "$(PURPLE)\t                                                                                                                                                      kXNNNNNNW          $(NO_COLOR)"
	@echo "$(PURPLE)\t           ;okOOOkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkl.  .'''''',:o0W      $(NO_COLOR)"
	@echo "$(PURPLE)\t          :ON      WNW                                                                                                                              WO;..;;.  'clc'..c0W    $(NO_COLOR)"
	@echo "$(PURPLE)\t        .dN         WNW                                                                                                                            Nd. :Ok, .dX   Nx' 'kW   $(NO_COLOR)"
	@echo "$(PURPLE)\t       'kW           WNW                                                                                                                          No..lXO' ,0W      K: .xW  $(NO_COLOR)"
	@echo "$(PURPLE)\t      .kW            WNW                                                                                                                         Wd. lN0, ,0         K; 'O  $(NO_COLOR)"
	@echo "$(PURPLE)\t     .xW              WNW                                                                                                                        O' :XXc .kW          0' ;K $(NO_COLOR)"
	@echo "$(PURPLE)\t     cN               WNW                                                                                                                       Nc .OWx. lN           Wd..dW$(NO_COLOR)"
	@echo "$(PURPLE)\t    'O                WNW                                                                                                                       k. lNX: '0             K; ,K$(NO_COLOR)"
	@echo "$(PURPLE)\t    lN                 WNW                                                                                                                     Nl .O k. lN             Wd..x$(NO_COLOR)"
	@echo "$(PURPLE)\t   .k                  WNW                                                                                                                     0, :XWl .k               0' x$(NO_COLOR)"
	@echo "$(PURPLE)\t   ;X                  WNW  $(BYELLOW) _______ _________   _______  _______  _       _________ _______ _________ _        _______  _______  _______ $(PURPLE)     k. oWX; ,K               X: .l$(NO_COLOR)"
	@echo "$(PURPLE)\t   lW                  WNW  $(BYELLOW)(  ____ \\__   __/  (  ____ \(  ___  )( (    /|\__   __/(  ___  )\__   __/( (    /|(  ____ \(  ____ )(  ____ \$(PURPLE)      Wo .k 0' cN               Wl .l$(NO_COLOR)"
	@echo "$(PURPLE)\t  .dW                  WNN  $(BYELLOW)| (    \/   ) (     | (    \/| (   ) ||  \  ( |   ) (   | (   ) |   ) (   |  \  ( || (    \/| (    )|| (    \/$(PURPLE)    Nc '0 k. oW                d .x$(NO_COLOR)"
	@echo "$(PURPLE)\t  .x                    NN  $(BYELLOW)| (__       | |     | |      | |   | ||   \ | |   | |   | (___) |   | |   |   \ | || (__    | (____)|| (_____ $(PURPLE)    X: ,K k..d                 x .x $(NO_COLOR)"
	@echo "$(PURPLE)\t  .k                    NN  $(BYELLOW)|  __)      | |     | |      | |   | || (\ \) |   | |   |  ___  |   | |   | (\ \) ||  __)   |     __)(_____  )$(PURPLE)    X; ,K x..x                 k .x $(NO_COLOR)"
	@echo "$(PURPLE)\t  .k                    NN  $(BYELLOW)| (         | |     | |      | |   | || | \   |   | |   | (   ) |   | |   | | \   || (      | (\ (         ) |$(PURPLE)    X; ,K x..x                 k .x $(NO_COLOR)"
	@echo "$(PURPLE)\t  .x                   WNN  $(BYELLOW)| )         | |     | (____/\| (___) || )  \  |   | |   | )   ( |___) (___| )  \  || (____/\| ) \ \__/\____) |$(PURPLE)    X: '0 x..dW                k .x $(NO_COLOR)"
	@echo "$(PURPLE)\t  .x                   WNW  $(BYELLOW)|/          )_(_____(_______/(_______)|/    )_)   )_(   |/     \|\_______/|/    )_)(_______/|/   \__/\_______)$(PURPLE)    N: '0 k. oW                x .x $(NO_COLOR)"
	@echo "$(PURPLE)\t   oW                  WNW  $(BYELLOW)              (_____)                                                                                         $(PURPLE)    Nl .O O. lW               Wo .l $(NO_COLOR)"
	@echo "$(PURPLE)\t   :X                  WNW                                                                                                                    Wd..x 0' :X               Nc .l$(NO_COLOR)"
	@echo "$(PURPLE)\t   '0                  WNW                                                                                                                     O. lNX: '0               K; x$(NO_COLOR)"
	@echo "$(PURPLE)\t   .dW                 WNW                                                                                                                     X; ,KWd..xW              k. l$(NO_COLOR)"
	@echo "$(PURPLE)\t    ;X                 NN                                                                                                                      Wd .xW0' :X             Nl .k$(NO_COLOR)"
	@echo "$(PURPLE)\t    .dW               WNW                                                                                                                       0' :XNl .k             0' :X$(NO_COLOR)"
	@echo "$(PURPLE)\t     ,0               WNW                                                                                                                       Wo..dW0' :X           Nl .k $(NO_COLOR)"
	@echo "$(PURPLE)\t      :X             WNW                                                                                                                         K; 'OWd..oW         Wx. lN $(NO_COLOR)"
	@echo "$(PURPLE)\t       lN            WNW                                                                                                                          O' ;KXc .xW       Wk. :X  $(NO_COLOR)"
	@echo "$(PURPLE)\t        cX          WNW                                                                                                                           Wk' ,OKc .oN     Nx. :K   $(NO_COLOR)"
	@echo "$(PURPLE)\t         ,OW       WNW                                                                                                                             WO; .lxc. ;xKNXk:..lX    $(NO_COLOR)"
	@echo "$(PURPLE)\t         ..:kXW  WNNWW                                                                                                                              WXl. ..    .....:OW     $(NO_COLOR)"
	@echo "$(PURPLE)\t          ...;OOkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO;...;loooooodkKW       $(NO_COLOR)"
	@echo "$(PURPLE)\t                                                                                                                                                     kXNNNNNNW$(NO_COLOR)"
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
	@rm -rf $(VNAME)
	@rm -rf $(MNAME)
	@rm -rf $(SNAME)
	@echo "\n\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Executable file is Deleted\n$(NO_COLOR)"


clean: header clean_o_files footer

fclean: header clean_o_files clean_exec_file footer

re: header clean_o_files clean_exec_file $(NAME) footer

.PHONY: all clean fclean re