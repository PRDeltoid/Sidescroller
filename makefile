all: Chess 

Chess: main.o json.o
	g++  obj/main.o obj/json.o -o Sidescroller -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c -g main.cpp -o obj/main.o -ISFML/include -Iinclude

json.o: include/jsoncpp.cpp
	g++ -c -g include/jsoncpp.cpp -o obj/json.o

clean:
	del obj /q
	del Sidescroller.exe
