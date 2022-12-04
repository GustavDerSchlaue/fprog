compiler      = g++
src  = FRPOG
obj  = output
cnf 	= -std=c++17 -lstdc++fs

test: word-counter
	$(obj)/word-counter $(arg_1) $(arg_2)

run: word-counter
	$(obj)/word-counter

word-counter: FRPOG/FRPOG.cpp
	mkdir -p $(obj)
	$(compiler) -o $(obj)/word-counter $(src)/FRPOG.cpp $(cnf)