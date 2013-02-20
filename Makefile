all: camera.o main.o
	g++ main.o camera.o -o world-explorer -lglut -lGLU

main.o: main.cpp
	g++ -c main.cpp 
    
camera.o: camera.cpp
	g++ -c camera.cpp
	
clean:
	rm -rf *.o world-explorer
