#include "comm.h"
#include "classHuffmanTree.h"
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
	HuffmanTree htree;
	Status flag=htree.open("test.in");
	htree.debug();
	printf("%d\n",sizeof(char));
	return 0;
}
