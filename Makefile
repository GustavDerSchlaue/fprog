TARGET  = word-counter

CC      = g++
SRCDIR  = src
OBJDIR  = output
CONF 	= -std=c++17 -lstdc++fs

test: word-counter
	$(OBJDIR)/word-counter $(arg1) $(arg2)

run: word-counter
	$(OBJDIR)/word-counter

word-counter: FRPOG.cpp
	mkdir -p $(OBJDIR)
	$(CC) -o $(OBJDIR)/word-counter FRPOG.cpp $(CONF)