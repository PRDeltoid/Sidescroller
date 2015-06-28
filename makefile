all: Chess 

Chess: main.o obj/json.o obj/jsondoc.o
	g++  obj/main.o obj/json.o obj/jsondoc.o -o Sidescroller -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c -g main.cpp -o obj/main.o -ISFML/include -Iinclude

obj/json.o: include/jsoncpp.cpp
	g++ -c -g include/jsoncpp.cpp -o obj/json.o

obj/jsondoc.o: src/jsondoc.cpp
	g++ -c -g src/jsondoc.cpp -o obj/jsondoc.o -Iinclude

clean:
	del obj /q
	del Sidescroller.exe
