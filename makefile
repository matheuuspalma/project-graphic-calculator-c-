# Rio de Janeiro - Federal University of Rio de Janeiro
# Dependency file to build the current project code.

CC = gcc
CPP = g++
RM = rm -rf
TARGET = main
INCLUDE_DIR = include -I/usr/include/python3.8
SRC_DIR = src
OBJ_DIR = obj
SRC_CPP = $(SRC_DIR)/cpp/$(TARGET).cpp
SRC_PY = $(SRC_DIR)/python/main.c
OBJ_CPP = $(OBJ_DIR)/$(TARGET)
LIB_PY = $(OBJ_DIR)/main.so
CFLAGS = -I$(INCLUDE_DIR) -lstdc++ -lpython3.8
LDFLAGS = -pthread -lpthread -lrt

all: python cpp

cpp: $(OBJ_CPP) 
$(OBJ_CPP): $(SRC_CPP) $(LIB_PY)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

python: $(LIB_PY)
$(LIB_PY): $(SRC_PY)
	$(CC) -shared -o $@ -fPIC $(shell python3-config --cflags) $^ $(shell python3-config --ldflags) $(CFLAGS)

clean:
	$(RM) $(OBJ_DIR) $(LIB_DIR)
