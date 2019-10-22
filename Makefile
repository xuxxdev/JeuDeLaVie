#########################
# 			#
#	MAKEFILE	#
#			#
#########################

################
#La Compilation#
################

CC = @g++
FLAGS = -Wall -ansi -pedantic -g

##############
#Les Fichiers#
##############

PROGNAME  = Main
SOURCE  = Cellule.cpp main.cpp PopulationVivante.cpp Population.cpp option.cpp tabOptions.cpp JeudelavieDeux.cpp
HEADER = Cellule.h PopulationVivante.h Population.h option.h tabOptions.h JeudelavieDeux.h
THIS = Makefile

############
#Les Cibles#
############

all : $(PROGNAME)

$(PROGNAME) : $(SOURCE:.cpp=.o)
	$(CC) $(FLAGS) $^ -o $@

Cellule.o : Cellule.cpp
	$(CC) $(FLAGS) -c $<

PopulationVivante.o : PopulationVivante.cpp
	$(CC) $(FLAGS) -c $<

Population.o : Population.cpp
	$(CC) $(FLAGS) -c $<

option.o : option.cpp
	$(CC) $(FLAGS) -c $<

tabOptions.o : tabOptions.cpp
	$(CC) $(FLAGS) -c $<

JeudelavieDeux.o : JeudelavieDeux.cpp
	$(CC) $(FLAGS) -c $<

main.o : main.cpp
	$(CC) $(FLAGS) -c $<

#######
#Clean#
#######

clean : 
	@rm $(PROGNAME) *.o


