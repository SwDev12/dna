all: dna

dna: dna.cpp
	g++ dna.cpp -Wall -Wextra -Werror -O0 -o dna

clean:
	rm dna
