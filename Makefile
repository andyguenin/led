program_NAME := led
program_C_SRCS := $(wildcard src/*.c)
program_C_OBJS := $(addprefix obj/,$(notdir ${program_C_SRCS:.c=.o}))
program_OBJS := $(program_C_OBJS)
program_INCLUDE_DIR := include
program_LIBRARY_DIR := lib
program_LIBRARIES :=


CFLAGS += $(foreach includedir,$(program_INCLUDE_DIR), -I$(includedir))
CFLAGS += -Wall -Wextra -pedantic -DDEBUG -g --std=c99
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIR),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))

.PHONY: all clean distclean

all: $(program_NAME)


echo:
	echo $(foreach sdir,$(addprefix $(program_LIBRARY_DIR),$(program_LIBRARIES)), echo $(sdir))
	echo $(addprefix ,$(program_LIBRARIES))
	echo $(CFLAGS)

test: 
	gcc src/test.cpp $(CFLAGS) -o test
	rm -r test.dSYM

$(program_NAME): $(program_OBJS)
	gcc $(program_OBJS) -o $(program_NAME)

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $^


clean:
	    @- $(RM) bin/$(program_NAME)
	    @- $(RM) $(program_OBJS)

distclean: clean

.PHONY: test
