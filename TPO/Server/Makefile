CC=gcc
CFLAGS= -Wall

default: all

chat_server: chat_server.c
	@$(CC) $(CFLAGS) -o $@ chat_server.c
#el $@ lo que hace es que me pone como nombre del ejecutable del programa el nombre de la regla que ejecuto
#si quiero ponerle yo el nombre del ejecutable, saco el $@ y le pongo el nombre
#CC y GCC son como unos defines que se agregam

#el programa que pongo ahi es la dependencia. lo que necesita para ejecutarlo
chat_client: chat_client.c
	@$(CC) $(CFLAGS) -o $@ chat_client.c
#en caso de necesitar agregar otros programas a modo de librerias, se agregan en esta linea

clean:
	@rm -f chat_server
	@rm -f chat_client

all: clean chat_server chat_client
#ejecuta estas reglas en ese orden

# al agregar el @ al principio de la linea, no lo muestra en el compilador

