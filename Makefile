SRC_DIR := src
OBJ_DIR := obj

EXE := necasy
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

VALFLAGS := -v --track-origins=yes --show-reachable=yes --leak-check=full
CXXFLAGS := -std=c++17 -Wall -pedantic -Iinclude -MMD -MP -fopenmp
LDFLAGS := $(shell pkg-config --cflags opencv) -Llib 
LDLIBS := -lm $(shell pkg-config --libs opencv)

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -cpp $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(EXE) $(OBJ_DIR)

valgrind: $(EXE)
	valgrind $(VALFLAGS) ./$(EXE) 


