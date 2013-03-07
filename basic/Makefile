objects = list.o main.o
main:$(objects)
	c++ -o main $(objects)
clean:
	rm *.o
%.o:%.cpp
	cc -c $?
