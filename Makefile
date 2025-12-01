.PHONY: clean run

bin/app: build/main.o build/StudentManager.o build/Student.o
	mkdir -p bin
	g++ build/main.o build/StudentManager.o build/Student.o -o ./bin/app

build/main.o: src/main.cpp
	mkdir -p build
	g++ -c src/main.cpp -o build/main.o

build/StudentManager.o: src/StudentManager.cpp include/StudentManager.hpp include/Student.hpp 
	mkdir -p build
	g++ -c src/StudentManager.cpp -o build/StudentManager.o

build/Student.o: src/Student.cpp include/Student.hpp
	mkdir -p build
	g++ -c src/Student.cpp -o build/Student.o

clean:
	rm -rf build/*.o ./bin/app

run: bin/app
	./bin/app