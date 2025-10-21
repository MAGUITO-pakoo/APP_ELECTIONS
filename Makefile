TARGET = Election.exe
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)	# Détecter tous les fichiers source (.c) dans le dossier SRC_DIR (wildcards trouve tous les fichiers qui correspondent au motif)
CC = gcc
CFLAGS = -Wall -g -std=c23 

all: $(TARGET)
	@echo "✅ Compilation terminée !"

$(TARGET): $(SRC)
	$(CC) $(SRC) $(LDFLAGS) -o $(TARGET)  

clean:
	rm -f $(TARGET)
	@echo "Fichier $(TARGET) supprimer"

run:
	./$(TARGET)
