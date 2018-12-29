###############################################################
# @file    Makefile                                           #
# @author  Filip Kocica <xkocic01@stud.fit.vutbr.cz>          #
# @date    15/11/2018                                         #
#                                                             #
# IMS project Makefile                                        #
###############################################################

################## Build constants ##############
BIN_NAME   = IMS-xkocic01-xvasic25

DOC        = doc.pdf
README     = README

QMAKE      = qmake
CC         = g++
CFLAGS     = -std=c++17

LDFLAGS    =
LIBS       =
#DOXYGEN    = doxygen

SRC        = src
GUI        = $(SRC)/gui

HEADERS    = $(wildcard $(SRC)/*.h)
SOURCES    = $(wildcard $(SRC)/*.cpp)
OBJS       = $(patsubst %.cpp, %.o, $(SOURCES))

GUI_SOURCES = $(wildcard $(GUI)/*.cpp)
GUI_HEADERS = $(wildcard $(GUI)/*.h)
GUI_OBJS    = $(patsubst %.cpp, %.o, $(GUI_SOURCES))


################## Compilation ##################

all: $(BIN_NAME)

$(BIN_NAME): $(HEADERS) $(SOURCES) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

debug: CFLAGS += -DDEBUG -g -DIMS_DEBUG
debug: all

gui: $(HEADERS) $(SOURCES) $(OBJS) $(GUI_SOURCES) $(GUI_HEADERS)
	@cd $(GUI) && $(QMAKE) && make
	@mv $(shell pwd)/$(GUI)/$(BIN_NAME)_gui .

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

################## Pack/Clean ##################

.PHONY: clean

#doxygen:
#	$(DOXYGEN) $(SRC)/doxyConf

pack:
	zip -r 07_xvasic25_xkocic01.zip Makefile $(README) ./src/* ./doc/$(DOC)

clean:
	-@cd $(GUI) && make clean && rm -f moc_*
	rm -f $(BIN_NAME) $(BIN_NAME)_gui $(SRC)/*.o

run:
	./$(BIN_NAME)

rungui:
	./$(BIN_NAME)_gui
