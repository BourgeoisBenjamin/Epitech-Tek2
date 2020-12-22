##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

clean:
	$(MAKE) -C ex00/ clean
	$(MAKE) -C ex01/ clean
	$(MAKE) -C ex02/ clean

fclean: clean
	$(MAKE) -C ex00/ fclean
	$(MAKE) -C ex01/ fclean
	$(MAKE) -C ex02/ fclean

rclean:
	$(MAKE) -C ex00/ rclean
	$(MAKE) -C ex01/ rclean
	$(MAKE) -C ex02/ rclean

tests_run:
	$(MAKE) -C ex00/ tests_run
	$(MAKE) -C ex01/ tests_run
	$(MAKE) -C ex02/ tests_run

coverage:
	$(MAKE) -C ex00/ coverage
	$(MAKE) -C ex01/ coverage
	$(MAKE) -C ex02/ coverage

re: fclean rclean tests_run

.PHONY: clean fclean re tests_run rclean coverage
