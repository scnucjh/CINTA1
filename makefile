mul:
	@ gcc -o temp SimpleMultiplication.c
	@ ./temp
	@ rm temp

bgcd:
	@ gcc -o temp binary_gcd.c
	@ ./temp
	@ rm temp
egcdn:
	@ g++ -o temp egcdn.cpp
	@ ./temp
	@ rm temp
