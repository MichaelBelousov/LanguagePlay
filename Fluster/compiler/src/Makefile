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
OBJS= lexer_core.o parse.o parse_bison.o

# compiler vars
CPPC=c++
CC=cc
INCLUDE=
LIBS=
OPTLVL= 2
CPPFLAGS= -O$(OPTLVL) $(LIBS) $(INCLUDE)
CFLAGS= -O$(OPTLVL) $(LIBS) $(INCLUDE)

# generator vars
LEXNAME= lexer_core
YACCNAME= parser_core
LEXOUT= lexer_core.cpp lexer_core.h lex.yy.cpp lex.yy.c
YACCOUT= parser_core.c parser_core.h Fluster.tab.c


###########################
########## Rules ##########
###########################


all: $(OBJS)
	$(CPPC) -o $(OUTBIN) $(CPPFLAGS) $^ 

%.o: %.cpp
	$(CPPC) -o $@ -g $(CPPFLAGS) $^ 


####### Generators Rules


lexer_core.o: lexer_core.cpp
	$(CPPC) -o $@ -g $(CPPFLAGS) $^

lexer_core.cpp:
	reflex Fluster.l

parser_core.o:
	$(CPPC) -o $@ -g $(CPPFLAGS) $^

parser_core.cpp:
	bison Fluster.y


####### Utility Rules


clean:
	rm -f *.o $(LEXOUT) $(YACCOUT)

ultraclean: clean
	rm $(OUT)

