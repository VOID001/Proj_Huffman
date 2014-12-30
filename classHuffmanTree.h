#ifndef CLASSHUFFMANTREE_H
#define CLASSHUFFMANTREE_H
#include"comm.h"
using namespace std;


class HuffmanTree{
private:
	void createHuffmanTree();
	Status countFreq();
	void generateCodingTable();
	void pr_encoding();
	void pr_decoding();
	int root;
	vector<StaticHuffmanNode> HuffmanT;
	//string codingTable[300];
	charNode charFreq[300];
	string fileStr;
public:
	void encoding();
	void decoding();
	Status open(const string& addr);
	HuffmanTree();
	~HuffmanTree();
	HuffmanTree(const HuffmanTree& T);

	//******For Debug********
	//Delete when the project Done
#ifdef DEBUG
	void debug();
#endif
	//******END FOR DEBUG****
};

#endif // CLASSHUFFMANTREE_H
