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

Status HuffmanTree::countFreq()
{
	memset(charFreq,0,sizeof(charFreq));
	long long len=fileStr.length();
	for(long long i=0;i<len;i++)
	{
		charFreq[(int)fileStr[i]].freq++;
	}
	//Debug
	//for(int i=0;i<300;i++)
	//{
	//	if(charFreq[i].freq)
	//	{
	//		printf("%c=%d\n",i,charFreq[i].freq);
	//	}
	//}
	//End Debug
	return OK;
}

void HuffmanTree::debug()
{
	countFreq();
	return ;
}

HuffmanTree::HuffmanTree():fileStr("")
{
	
}

HuffmanTree::~HuffmanTree()
{

}

#endif
