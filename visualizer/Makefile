DIR_VISU_VM = flr_visu_vm/
DIR_VISU_HUMAN = flr_visu_human/

.PHONY : all clean fclean re

all :
	make -C $(DIR_VISU_VM)
	make -C $(DIR_VISU_HUMAN)

clean :
	@make -C $(DIR_VISU_VM) clean
	@make -C $(DIR_VISU_HUMAN) clean

fclean : clean
	@make -C $(DIR_VISU_VM) fclean
	@make -C $(DIR_VISU_HUMAN) fclean

re : fclean all
