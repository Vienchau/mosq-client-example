.PHONY: clean, flash
# CROSS_COMPILE =/opt/cross-pi-gcc/bin/arm-linux-gnueabihf-
# LIBRARY_PATH=/home/vienchau/build-example/pi/lib
# INCLUDE_PATH=/home/vienchau/build-example/pi/include
CC = $(CROSS_COMPILE)gcc
LIBRARY_PATH=/home/vienct3/build/local/lib
INCLUDE_PATH=/home/vienct3/build/local/include

STD = gnu99
CFLAGS =-Wall \
	-g \
	-I./include \
	-I$(INCLUDE_PATH) \
	-fsanitize=address \
	-fsanitize=leak \

	
LDFLAGS =-L$(LIBRARY_PATH) \
	-lmosquitto \
	-ljansson \
	# -lssl \
	# -lcrypto \
	# -lasan


vpath %.c ./src/
vpath %.h ./include/

EXEDIR=./bin
OBJDIR=./obj

OBJ+=$(OBJDIR)/main.o \
	$(OBJDIR)/publisher.o

EXEC=publisher-client
RM=rm

########################################################################
####################### Targets beginning here #########################
########################################################################
# Builds the app
$(EXEDIR)/$(EXEC): $(OBJ)
	@echo =============EXE PROCESS=============
	[ -d "./bin" ] && echo "Directory /path/to/dir exists." || mkdir ./bin	
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)


# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: %.c 
	@echo =============OBJ PROCESS=============
	[ -d "./obj" ] && echo "Directory /path/to/dir exists." || mkdir ./obj	
	$(CC)  $(CFLAGS) -c $< -o  $@  

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project

clean:
	$(RM) $(EXEDIR)/$(EXEC) $(OBJ) $(DEP)
 
flash: clean all
	@./$(EXEDIR)/$(EXEC)