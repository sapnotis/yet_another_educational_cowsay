CC=g++

all: cowsay

clean:
	rm *.o
	rm cowsay

ASCIIpicture.o: ASCIIpicture.cpp ASCIIpicture.hpp
	$(CC) -c ASCIIpicture.cpp -o ASCIIpicture.o

Cloud.o: Cloud.cpp Cloud.hpp
	$(CC) -c Cloud.cpp -o Cloud.o

Cow.o: Cow.cpp Cow.hpp
	$(CC) -c Cow.cpp -o Cow.o

Field.o: Field.cpp Field.hpp Parser.hpp
	$(CC) -c Field.cpp -o Field.o

Parser.o: Parser.cpp Parser.hpp
	$(CC) -c Parser.cpp -o Parser.o

main.o: main.cpp Parser.hpp Field.hpp
	$(CC) -c main.cpp -o main.o

cowsay: ASCIIpicture.o Cloud.o Cow.o Field.o Parser.o main.o
	$(CC) ASCIIpicture.o Cloud.o Cow.o Field.o Parser.o main.o -o cowsay

install: cowsay
	install ./cowsay /usr/local/bin
	mkdir /usr/share/alt-cowsay/
	cp -r cows /usr/share/alt-cowsay/
	cp -r clouds /usr/share/alt-cowsay/

uninstall:
	rm /usr/local/bin/cowsay
	rm -r /usr/share/alt-cowsay