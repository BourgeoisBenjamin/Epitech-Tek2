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
	$(MAKE) -C ex03/ clean
	$(MAKE) -C ex04/ clean
	$(MAKE) -C ex05/ clean
	$(MAKE) -C ex06/ clean

fclean: clean
	$(MAKE) -C ex00/ fclean
	$(MAKE) -C ex01/ fclean
	$(MAKE) -C ex02/ fclean
	$(MAKE) -C ex03/ fclean
	$(MAKE) -C ex04/ fclean
	$(MAKE) -C ex05/ fclean
	$(MAKE) -C ex06/ fclean

rclean:
	$(MAKE) -C ex00/ rclean
	$(MAKE) -C ex01/ rclean
	$(MAKE) -C ex02/ rclean
	$(MAKE) -C ex03/ rclean
	$(MAKE) -C ex04/ rclean
	$(MAKE) -C ex05/ rclean
	$(MAKE) -C ex06/ rclean

tests_run:
	$(MAKE) -C ex00/ tests_run
	$(MAKE) -C ex01/ tests_run
	$(MAKE) -C ex02/ tests_run
	$(MAKE) -C ex03/ tests_run
	$(MAKE) -C ex04/ tests_run
	$(MAKE) -C ex05/ tests_run
	$(MAKE) -C ex06/ tests_run

coverage:
	$(MAKE) -C ex00/ coverage
	$(MAKE) -C ex01/ coverage
	$(MAKE) -C ex02/ coverage
	$(MAKE) -C ex03/ coverage
	$(MAKE) -C ex04/ coverage
	$(MAKE) -C ex05/ coverage
	$(MAKE) -C ex06/ coverage

re: fclean rclean tests_run

.PHONY: clean fclean re tests_run rclean coverage
