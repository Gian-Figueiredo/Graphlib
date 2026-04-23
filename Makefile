# Nome do executável final
TARGET = programa

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall -I include

# Diretórios
SRC_DIR = src
BIN_DIR = bin

# Localizar todos os arquivos .cpp em src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Definir os arquivos .o dentro de bin/ com base nos nomes em src/
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Regra principal (Default)
all: $(BIN_DIR) $(TARGET)

# Linkagem final: transforma os .o no executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilação: transforma cada .cpp em um .o dentro de bin/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar a pasta bin se ela não existir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BIN_DIR) $(TARGET)

# Recompilação forçada
rebuild: clean all

run: $(TARGET)
	./$(TARGET)

# Evita conflitos com arquivos de mesmo nome
.PHONY: all clean run rebuild