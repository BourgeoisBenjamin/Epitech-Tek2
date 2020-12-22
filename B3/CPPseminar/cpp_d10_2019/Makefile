##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

clean:
	$(MAKE) -C ex00/ clean
	$(MAKE) -C ex01/ clean

fclean: clean
	$(MAKE) -C ex00/ fclean
	$(MAKE) -C ex01/ fclean

rclean:
	$(MAKE) -C ex00/ rclean
	$(MAKE) -C ex01/ rclean

tests_run:
	$(MAKE) -C ex00/ tests_run
	$(MAKE) -C ex01/ tests_run

coverage:
	$(MAKE) -C ex00/ coverage
	$(MAKE) -C ex01/ coverage

re: fclean rclean tests_run

.PHONY: clean fclean re tests_run rclean coverage
