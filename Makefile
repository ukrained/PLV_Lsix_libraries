CC=gcc
AR=ar

CFLAGS=-Wall -Werror -Wextra -fpic
MATH_LIB_FLAGS=-rcs
TEXT_LIB_FLAGS=-shared


INCLUDES=mymath.h mylower.h myupper.h

MATH_LIB_SOURCES=mymath.o
TEXT_LIB_SOURCES=mylower.o myupper.o

TARGET_SOURCES=main.c

LIB_INSTALL_DIR=/usr/lib

MATH_LIBNAME=mymath
MATH_LIB=lib$(MATH_LIBNAME).a
TEXT_LIBNAME=mytext
TEXT_LIB=lib$(TEXT_LIBNAME).so

TARGET=main


all: $(TARGET)

# compile program
$(TARGET):$(TARGET_SOURCES) $(INCLUDES) $(MATH_LIB) $(TEXT_LIB)
	@echo Running target $@ ...
	$(CC) $(TARGET_SOURCES) -L . -l $(MATH_LIBNAME) -l $(TEXT_LIBNAME) -Wall -o $@

# compile static library
$(MATH_LIB): $(MATH_LIB_SOURCES) $(INCLUDES)
	@echo Running static lib $@ ...
	$(AR) $(MATH_LIB_FLAGS) $(MATH_LIB) $(MATH_LIB_SOURCES)

# compile dynamic library
$(TEXT_LIB): $(TEXT_LIB_SOURCES) $(INCLUDES)
	@echo Running shared lib $@ ...
	$(CC) $(TEXT_LIB_FLAGS) -o $(TEXT_LIB) $(TEXT_LIB_SOURCES)
	cp `pwd`/$(TEXT_LIB) $(LIB_INSTALL_DIR)
	chmod 0755 $(LIB_INSTALL_DIR)/$(TEXT_LIB)
	ldconfig

# compile all C-files to object files
%.o: %.c
	@echo Running object $@ ...
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo Cleaning all that shit ...
	rm -rf *.o *.so *.a $(TARGET)
	rm -f $(LIB_INSTALL_DIR)/$(TEXT_LIB)
	ldconfig
