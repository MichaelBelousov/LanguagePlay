CPPC=c++
CC=cc
INCLUDE=
LIBS=
OPTLVL=2
CPPFLAGS= -O$(OPTLVL) $(LIBS) $(INCLUDE)
OUTBIN= fc
LEXOUT= lexer_core.cpp lexer_core.h
YACCOUT= ParserCore.c ParserCore.h
OBJS=lexer_core.o parse.o parse_bison.o

all: $(OBJS)
	$(CPPC) -o $(OUTBIN) $(CPPFLAGS) $^ 

%.o: %.cpp
	$(CPPC) -o $@ -g $(CPPFLAGS) $^ 

lexer_core.o: lexer_core.cpp
	$(CPPC) -o $@ -g $(CPPFLAGS) $^

lexer_core.cpp:
	reflex Fluster.l

clean:
	rm -f *.o $(LEXOUT) $(YACCOUT)

ultraclean: clean
	rm $(OUT)
