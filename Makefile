#########################
# 			#
#	MAKEFILE	#
#			#
#########################

################
#La Compilation#
################

CC = @g++
FLAGS = -Wall -ansi -pedantic

##############
#Les Fichiers#
##############

PROGNAME  = Main
SOURCE  = Cellule.cpp main.cpp
HEADER = Cellule.h
THIS = Makefile

############
#Les Cibles#
############

all : $(PROGNAME)

$(PROGNAME) : $(SOURCE:.cpp=.o)
	$(CC) $(FLAGS) $^ -o $@

Cellule.o : Cellule.cpp
	$(CC) $(FLAGS) -c $<

main.o : main.cpp
	$(CC) $(FLAGS) -c $<

#######
#Clean#
#######

clean : 
	@rm $(PROGNAME)


