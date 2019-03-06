# Specify the target file and build directory
OUTPUTFILE = libpsd.a
BUILDDIR   = src

SOURCES = $(wildcard src/*.c)
# Get list of object files, with paths
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:src/%.c=%.o))

CFLAGS := $(CFLAGS) -I include

# Default target
.PHONY: all
all: $(OUTPUTFILE)

# Build libjohnpaul.a from john.o, paul.o, and johnpaul.o
$(OUTPUTFILE): $(OBJECTS)
	$(AR) -rcs $@ $^

# Specify extensions of files to delete when cleaning
CLEANEXTS  = o a 

.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -f *.$$file; done

# Indicate dependencies of .c files on .h files
$(BUILDDIR)/%.o: include/libpsd.h
