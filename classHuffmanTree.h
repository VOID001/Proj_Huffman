#ifndef CLASSHUFFMANTREE_H
#define CLASSHUFFMANTREE_H
#include"comm.h"
using namespace std;


class HuffmanTree{
private:
	int addNode(int laddr,int raddr);
	Status createHuffmanTree();
	Status countFreq();
	Status generateCodingTable();
	void recur_gen_table(int root,string encodigStr);
	void pr_encoding();
	void pr_decoding();
	int root;
	vector<StaticHuffmanNode> HuffmanT;
	string codingTable[charNodeSize];
	charNode charFreq[charNodeSize];
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
