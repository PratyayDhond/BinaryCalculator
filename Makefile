final:
		gcc -g *.c -o binaryCalculator -lm
		./binaryCalculator

clear:
	cls
	make final