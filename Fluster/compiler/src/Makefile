###########################
# A simple Makefile before I
# move to a more dynamic environment,
# by Michael Belousov
###########################

###########################
###### Variables ##########
###########################

# project vars
OUTBIN= fc
OBJS= lexer.o parse.o parse_bison.o

# compiler vars
CPPC=c++
CC=cc
INCLUDE=
LIBS=
OPTLVL= 2
CPPFLAGS= -O$(OPTLVL) $(LIBS) $(INCLUDE)
CFLAGS= -O$(OPTLVL) $(LIBS) $(INCLUDE)

# generator vars
LEXNAME= lexer
YACCNAME= parser
LEXOUT= lexer.cpp lexer.h
YACCOUT= parser.cpp parser.h stack.hh


###########################
########## Rules ##########
###########################


all: $(OBJS)
	$(CPPC) -o $(OUTBIN) $(CPPFLAGS) $^ 

%.o: %.cpp
	$(CPPC) -o $@ -g $(CPPFLAGS) $^ 


####### Generators Rules


lexer.o: lexer.cpp
	$(CPPC) -o $@ -g $(CPPFLAGS) $^

lexer.cpp:
	reflex lexer.l

parser.o:
	$(CPPC) -o $@ -g $(CPPFLAGS) $^

parser.cpp:
	bison parser.y


####### Utility Rules


clean:
	rm -f *.o $(LEXOUT) $(YACCOUT)

ultraclean: clean
	rm $(OUT)

