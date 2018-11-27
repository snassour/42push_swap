all:
	make -C ./libft
	make -C ./libpushswap
	make -C ./srcs_checker
	make -C ./srcs_push_swap
	cp ./srcs_push_swap/push_swap .
	cp ./srcs_checker/checker .

clean:
	make clean -C ./libft
	make clean -C ./libpushswap
	make clean -C ./srcs_checker
	make clean -C ./srcs_push_swap

fclean: clean
	make fclean -C ./libft
	make fclean -C ./libpushswap
	make fclean -C ./srcs_checker
	make fclean -C ./srcs_push_swap
	rm -f push_swap
	rm -f checker

re: fclean all

checker:
	make -C ./libft
	make -C ./libpushswap
	make -C ./srcs_checker
	cp ./srcs_checker/checker .

push_swap:
	make -C ./libft
	make -C ./libpushswap
	make -C ./srcs_push_swap
	cp ./srcs_push_swap/push_swap .

clean_checker:
	make clean -C ./srcs_checker
	make clean -C ./libpushswap
	make clean -C ./libft

clean_push_swap:
	make clean -C ./srcs_push_swap
	make clean -C ./libpushswap
	make clean -C ./libft

fclean_checker: clean_checker
	rm checker

fclean_push_swap: clean_push_swap
	rm push_swap