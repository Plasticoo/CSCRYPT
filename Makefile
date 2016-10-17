CC := gcc
CCL := clang
CFLAGS := -Wall -Wextra -std=c11
COPT := -O2
COPTD := -O0
CDEBUG := -pg -ggdb3 -fno-inline
CLDEBUG := -fsanitize=address
GPERF:= -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free -ltcmalloc -lprofiler
GCOV := -fprofile-arcs -ftest-coverage

BUILD_DIR := build

SOURCES := $(wildcard src/*.c)
OBJS := $(addprefix $(BUILD_DIR)/, main.o)

TARGET := CAESAR_CIPHER

$(TARGET): $(OBJS)
			$(CC) $(CFLAGS) $(COPT) $(OBJS) -o bin/$(TARGET)

gperf: $(OBJS)
	   $(CC) $(CFLAGS) $(COPTD) $(GPERF) $(OBJS) -o bin/$(TARGET)

clangd: $(OBJS)
		$(CCL) $(CFLAGS) $(COPTD) $(CLDEBUG) $(OBJS) -o bin/$(TARGET)

gccd: $(OBJS)
	  $(CC) $(CFLAGS) $(COPTD) $(CDEBUG) $(OBJS) -o bin/$(TARGET)

$(BUILD_DIR)/%.o: src/%.c
				   $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(BUILD_DIR)/*.o
