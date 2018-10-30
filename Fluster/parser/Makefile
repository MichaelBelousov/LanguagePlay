CPPC=c++
# I'm working on my android phone in termux so these locations
# will be pretty strange
INCLUDE=
LIBS=
CPPFLAGS=
OUT=

all: $(objs)
	$(CPPC) lex.yy.cpp $^ $(CPPFLAGS)

%.o: lex_src, %.cpp
	$(CPPC) -o $^ $(CPPFLAGS)

lex_src:
	@reflex Fluster.l #-o

clean:
	@rm *.o

ultraclean: clean
	@rm $(OUT)
