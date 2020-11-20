CPP_OPT = -std=c++11
c:
	@gcc main.c -o main.out
cpp:
	c++ $(CPP_OPT) main.cpp -o main.out
clean:
	rm *.out