/*************************************************************************
    > File Name: classHuffmanTree.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月29日 星期一 19时35分05秒
	> Content : Define the HuffmanTree Class 
 ************************************************************************/
#ifndef _CLASSHUFFMANTREE_CPP
#define _CLASSHUFFMANTREE_CPP
#include "structs.h"
#include "comm.h"
class HuffmanTree{
	private:
		void createHuffmanTree();
		void countFreq();
		void generateCodingTable();
		void pr_encoding();
		void pr_decoding();
		int root;
		vector<StaticHuffmanNode> HuffmanT;
		string codingTable[300];
		string fileStr;
	public:
		void encoding();
		void decoding();
		void open();
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

void HuffmanTree::encoding()
{

}

void HuffmanTree::decoding()
{
	//open
}

void open()
{

}


#endif
