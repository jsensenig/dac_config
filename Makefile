########################################################################
## Simple Makefile for compiling DAC setup test application
########################################################################
CC = g++

DEF_CFLAGS = -std=c++11 -Wall 

#Compiled for Microzed
CFLAGS = -g $(DEF_CFLAGS)
INCLUDES = -I./ 
SRCS = dac_setup.cc test_dacsetup.cc
OBJS = $(SRCS:.c=.o)
MAIN = test_dacsetup

.PHONY: depend clean

all:	$(MAIN)
	@echo  DAC program $(MAIN) has been compiled!
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) 
.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -rf *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
