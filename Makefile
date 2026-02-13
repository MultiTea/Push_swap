# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 15:13:12 by lbolea            #+#    #+#              #
#    Updated: 2026/02/13 09:22:53 by lbolea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

#SOURCES
SRC_DIR		:= src
SRCS		:= main.c \
	parsing.c \
	algorithm/small_cases.c \
	algorithm/bigy.c \
	rules/rules_push.c \
	rules/rules_rev_rot.c \
	rules/rules_rotate.c \
	rules/rules_swap.c \
	utils/utils.c \
	utils/utils_algo.c \
	utils/utils_debug_tools.c \
	utils/utils_find.c \
	utils/utils_parsing.c \
	utils/utils_sort.c \
	utils/utils_stack_init.c \
	utils/utils_stack_set.c \
	utils/ft_split_args.c
SRCS 		:= $(SRCS:%=$(SRC_DIR)/%)

#INCLUDES
INCS		:= 	include \
	libs/Libft/ \
	libs/printf/include/

#LIBS
LIBS	:= ft ftprintf
LIBS_TARGET :=	\
	libs/Libft/libft.a \
	libs/printf/libftprintf.a

#BUILD
BUILD_DIR 	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#FLAGS
CC 			:= cc
CCFLAGS 	:= -Wall -Wextra -Werror
AR 			:= ar
ARFLAGS		:= rcs
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))

#TOOLS
RM 			:= rm -f
DIR_DUP		= mkdir -p $(@D)
MAX_J 		:= 8

## COLORS
DEF		= \033[0m
GREEN 	= \033[0;32m

##COMMANDES

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)[OK]$(DEF) CREATED $(NAME)"

$(LIBS_TARGET):
	@$(MAKE) --no-print-directory -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(GREEN)[OK]$(DEF) CREATED $@"

-include $(DEPS)

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) --no-print-directory -C $$f clean; done
	@$(RM) $(OBJS) $(DEPS)
	@echo "$(GREEN)[OK]$(DEF) CLEANED $(NAME) objs & deps"

fclean: clean
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) --no-print-directory -C $$f fclean; done
	@$(RM) $(NAME)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)[OK]$(DEF) CLEANED $(NAME)"

re:
	@+make --no-print-directory -j$(MAX_J) fclean --no-print-directory
	@+make --no-print-directory all
	@echo "$(GREEN)[OK]$(DEF) RECOMPILED $(NAME)"

#debug: fclean
#	@$(MAKE) --no-print-directory $(OBJS) $(LIBS_TARGET) CCFLAGS="$(CCFLAGS) -g"
#	@$(CC) $(CCFLAGS) -g $(LDFLAGS) $(OBJS) $(LDLIBS) -o debug
#	@echo "$(GREEN)[OK]$(DEF) CREATED debug program"

.PHONY: all clean fclean re