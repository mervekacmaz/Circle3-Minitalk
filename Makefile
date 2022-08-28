NAME		=	minitalk
SERVER		=	server
SERVER_SRC	=	server.c

CLIENT		=	client
CLIENT_SRC	=	client.c

RM			=	rm -rf
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(SERVER) :
	$(CC) $(FLAGS) server.c -o $(SERVER)

$(CLIENT) :
	$(CC) $(FLAGS) client.c -o $(CLIENT)
	
fclean: clean
	rm -rf $(SERVER) $(CLIENT)

clean:
	rm -rf server client

re : fclean all

.PHONY: all fclean clean re