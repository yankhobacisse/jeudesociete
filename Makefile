CC = g++

OBJS = InterfacePlateau.o Plateau.o Othello.o Puissance4.o Puissance4Var.o Collection.o FiveOrMore.o FiveOrMoreVar.o main.o

test : $(OBJS)
	$(CC) $(OBJS) -o $@ -lm
InterfacePlateau.o : Plateau/InterfacePlateau.h Plateau/ListeCouleur.h Plateau/ListeCouleur.cpp
	$(CC) -o $@ -c Plateau/InterfacePlateau.cpp
Plateau.o : Plateau/ListeCouleur.h Plateau/InterfacePlateau.h Plateau/Plateau.h Plateau/Plateau.cpp
	$(CC) -o $@ -c Plateau/Plateau.cpp
Othello.o : Othello/Othello.h Plateau/Plateau.h Othello/Othello.cpp
	$(CC) -o $@ -c Othello/Othello.cpp
Puissance4.o : Puissance4/Puissance4.h Plateau/Plateau.h Puissance4/Puissance4.cpp
	$(CC) -o $@ -c Puissance4/Puissance4.cpp
Puissance4Var.o : Puissance4/Puissance4.h structure/Stack.h Puissance4Var/Puissance4Var.h Puissance4Var/Puissance4Var.cpp
	$(CC) -o $@ -c Puissance4Var/Puissance4Var.cpp
Collection.o : Plateau/ListeCouleur.h structure/Iterateur.h structure/Collection.h structure/Collection.cpp
	$(CC) -o $@ -c structure/Collection.cpp
FiveOrMore.o : structure/Collection.h structure/Iterateur.h Plateau/Plateau.h FiveOrMore/FiveOrMore.h FiveOrMore/FiveOrMore.cpp
	$(CC) -o $@ -c FiveOrMore/FiveOrMore.cpp
FiveOrMoreVar.o : FiveOrMore/FiveOrMore.h FiveOrMoreVar/FiveOrMoreVar.h FiveOrMoreVar/FiveOrMoreVar.cpp
	$(CC) -o $@ -c FiveOrMoreVar/FiveOrMoreVar.cpp
main.o : Plateau/Plateau.h Othello/Othello.h Puissance4/Puissance4.h Puissance4Var/Puissance4Var.h structure/Collection.h \
FiveOrMore/FiveOrMore.h FiveOrMoreVar/FiveOrMoreVar.h main.cpp
	$(CC) -o $@ -c main.cpp

clean:
	find . -name '*.o' -exec rm -f {} ';'
	find . -name '*.a' -exec rm -f {} ';'
	find . -name '*~' -exec rm -f {} ';'
	find . -name '#*#' -exec rm -f {} ';'
	find . -name '.#*' -exec rm -f {} ';'
	find . -name 'core' -exec rm -f {} ';'
	find . -name '*.core' -exec rm -f {} ';'
	find . -name '*.swp' -exec rm -f {} ';'
	-rm -rf $(PRGS)
