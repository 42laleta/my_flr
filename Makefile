DIR_VISU = visualizer/
DIR_BOT = bot/
THIS_DIR := $(shell pwd) 

.PHONY : all clean fclean re

all : 
	make create_sup_files
	make -C $(DIR_BOT)
	make -C $(DIR_VISU)

create_sup_files:
	@echo "#!/bin/bash\ncd" $(THIS_DIR) \
	"\n#lldb -o run ./bot/build/74_human_adapter.filler \
	\n./bot/build/74_human_adapter.filler" \
	> r_adapter.command
	@chmod +x r_adapter.command
	@echo "#!/bin/bash\ncd" $(THIS_DIR) \
	"\n./bot/build/72_human_controller.filler" \
	> r_controller.command
	@chmod +x r_controller.command
	@echo "#!/bin/bash\ncd" $(THIS_DIR) \
	"\n./bot/build/71_human_view.filler" \
	> r_view.command
	@chmod +x r_view.command

del_sup_files:
	rm -f r_adapter.command r_controller.command r_view.command
	rm -f filler.trace

clean :
	@make -C $(DIR_BOT) clean
	@make -C $(DIR_VISU) clean

fclean : clean
	@make -C $(DIR_BOT) fclean
	@make -C $(DIR_VISU) fclean
	@make del_sup_files

re : fclean all
