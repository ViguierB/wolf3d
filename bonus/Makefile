##
## Makefile for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
## 
## Started on  Wed Dec  7 12:45:32 2016 Benjamin Viguier
## Last update Wed Jan 11 17:05:38 2017 Benjamin Viguier
##

include $(shell pwd)/include/depend.mk

SRC	= 	src/my_draw_line.c	\
		src/my_put_pixel.c	\
		src/raycast.c		\
		src/move_forward.c	\
		src/openfile.c		\
		src/read_to_end.c	\
		src/projection.c	\
		src/map.c		\
		src/wolf.c		\
		src/event.c		\
		src/evt_fcts.c		\
		src/error.c		\
		src/dist_effect.c	\
		src/params.c		\
		src/params_ext.c	\
		src/open_config.c	\
		src/main.c

CFLAGS	+=	-I./include/

LDFLAGS	=	-L./lib/my/ -lc_graph_prog -lm -lmy

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

all	:	$(NAME)

$(NAME)	:	mlib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclib fclean all

fclib	:
	cd ./lib/my/ && $(MAKE) fclean && cd -

mlib	:
	cd ./lib/my/ && $(MAKE) && cd -
