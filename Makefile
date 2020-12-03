CPP_OPT = -std=c++11
cpp:
	@g++ $(CPP_OPT) main.cpp -o main.out
c:
	@gcc main.c -o main.out
clean:
	rm *.out