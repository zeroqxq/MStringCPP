CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

SRC_DIR = .
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

SOURCES = mstring.cpp include/include.cpp
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

STATIC_LIB = $(LIB_DIR)/libmstring.a
DYNAMIC_LIB = $(LIB_DIR)/libmstring.so

all: static dynamic

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/include
	mkdir -p $(LIB_DIR)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJECTS) | $(BUILD_DIR)
	ar rcs $@ $(OBJECTS)

dynamic: $(DYNAMIC_LIB)

$(DYNAMIC_LIB): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) -shared $(OBJECTS) -o $@

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: all

release: CXXFLAGS += $(RELEASE_FLAGS)
release: all

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

rebuild: clean all

install: all
	cp $(STATIC_LIB) /usr/local/lib/
	cp $(DYNAMIC_LIB) /usr/local/lib/
	cp mstring.h /usr/local/include/
	cp include/include.h /usr/local/include/

uninstall:
	rm -f /usr/local/lib/$(notdir $(STATIC_LIB))
	rm -f /usr/local/lib/$(notdir $(DYNAMIC_LIB))
	rm -f /usr/local/include/mstring.h
	rm -f /usr/local/include/include.h

info:
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Static lib: $(STATIC_LIB)"
	@echo "Dynamic lib: $(DYNAMIC_LIB)"

.PHONY: all static dynamic debug release clean rebuild install uninstall info
