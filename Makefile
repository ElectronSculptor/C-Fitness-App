# Nom de l'exécutable
EXEC = fitness_app

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Fichiers sources
SRC = main.cpp Utilisateur.cpp Seance.cpp Progres.cpp

# Fichiers d'objets (générés automatiquement à partir des sources)
OBJ = $(SRC:.cpp=.o)

# Règle par défaut : compilation complète
all: $(EXEC)

# Génération de l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers sources en fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour tout nettoyer (y compris les fichiers temporaires)
distclean: clean

# Indiquer que "clean" et "distclean" ne sont pas des fichiers
.PHONY: all clean distclean
