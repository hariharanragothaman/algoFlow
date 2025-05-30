# +--------------------+
# |                    |
# |   GENERAL CONFIG   |
# |                    |
# +--------------------+

pname := A
DEBUG := true
lang := cpp

uname_p := $(shell uname -p)
ifeq ($(uname_p),x86_64)
	CXX := g++
else ifeq ($(uname_p), arm)
	CXX := g++
endif

ifeq ($(lang),cpp)
TARGET := $(pname)
EXECUTE := ./$(TARGET)
CLEAN_TARGETS := $(TARGET)

else ifeq ($(lang),python)
TARGET := $(pname).py
EXECUTE := python3 $(TARGET)
CLEAN_TARGETS :=

else
endif

CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion
DEBUG_CXXFLAGS := -fsanitize=address -fsanitize=undefined -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize-recover=all -fstack-protector-all -D_FORTIFY_SOURCE=2
DEBUG_CXXFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
PRECOMPILE_HEADERS := bits/stdc++.h


# +-------------------+
# |                   |
# |   GENERAL RULES   |
# |                   |
# +-------------------+


.PHONY: default
default: run

.PHONY: build
build:
ifeq ($(lang),cpp)
	${CXX} ${CXXFLAGS}  ${pname}.cpp -o $(TARGET)

else ifeq ($(lang),python)
	@echo "Running Python Code"
else
endif

.PHONY: run
run: build
ifeq ($(lang),cpp)
	timeout 1.0s $(EXECUTE)

else ifeq ($(lang),python)
	timeout 1.0s $(EXECUTE)
else
endif


.PHONY: clean
clean:
	rm -rf $(CLEAN_TARGETS)
