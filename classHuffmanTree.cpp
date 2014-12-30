/*************************************************************************
    > File Name: classHuffmanTree.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2014年12月29日 星期一 19时35分05秒
    > Content : Define the HuffmanTree Class
 ************************************************************************/
#ifndef CLASSHUFFMANTREE_CPP
#define CLASSHUFFMANTREE_CPP
#include "classHuffmanTree.h"

using namespace std;

void HuffmanTree::encoding()
{

}

void HuffmanTree::decoding()
{

}

Status HuffmanTree::open(const string& addr)
{
	//Open with fstream
	ifstream fs(addr.c_str());
	if(fs.is_open())
	{
		char ch;
		while(fs.good())
		{
			fs.get(ch);
			fileStr+=ch;
		}
		fs.close();
	}
	else
	{
		return ERR;
	}

	//Output the File
	return OK;
}

void HuffmanTree::debug()
{

	return ;
}

HuffmanTree::HuffmanTree():fileStr("")
{
	
}

HuffmanTree::~HuffmanTree()
{

}

#endif
