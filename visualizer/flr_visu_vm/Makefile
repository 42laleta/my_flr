NAME = $(BIN_PATH)filler_visu_vm
BIN_PATH = ../../
BIN = filler_visu_vm
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c flrv_init.c flrv_init_player.c flrv_destroy.c flrv_util.c\
			flrv_draw_shape.c flrv_draw_header.c flrv_event.c flrv_set_shape.c
HEADER = flr_visual.h flr_loadfile.h

INCLUDES = -Iincludes -I$(LIBFT_DIR)includes $(CSFML_INCLUDE)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ../../libft/
CSFML_DIR = ../CSFML/
CSFML_DIR_RT = visualizer/CSFML/
CSFML_INCLUDE = -I$(CSFML_DIR)include/SFML -I$(CSFML_DIR)include

LIB = -lft -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LIB_DIR = -L$(LIBFT_DIR) -L$(CSFML_DIR)lib
RPATH = -rpath,$(CSFML_DIR_RT)lib/,-rpath,$(CSFML_DIR_RT)Frameworks/

VPATH = srcs includes ../CSFML/lib ../CSFML/include/SFML

OBJ = $(SOURCE:.c=.o)
OBJ_DIR = obj/
OBJECT = $(patsubst %.o, $(OBJ_DIR)%.o, $(OBJ))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECT)
	@echo "\033[1;3;34m"
	gcc $(FLAGS) $(OBJECT) -o $@ $(INCLUDES) $(LIB_DIR) -Wl,$(RPATH) $(LIB)
	@echo "\033[23;32m--[ "$(BIN) ]-- successfully compiled"\033[0m"

$(LIBFT) :
	@echo "\033[33;3m"
	@make -C $(LIBFT_DIR)
	@echo "\033[0m"

$(OBJ_DIR)%.o : %.c $(HEADER)
	@echo "\033[36;3m\c"
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[0m\c"

clean :
	@make -C $(LIBFT_DIR) clean
	@find $(OBJ_DIR) -type f -not -name '.gitkeep' -delete

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re : fclean all
