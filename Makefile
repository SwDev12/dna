all: dna dna_c

dna: dna.cpp
	g++ dna.cpp -Wall -Wextra -Werror -O0 -o dna

dna_c: dna.cpp
	gcc dna.cpp -Wall -Wextra -Werror -O0 -o dna_c

clean:
	rm dna dna_c
