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

Status HuffmanTree::createHuffmanTree()
{
	//create a priority queue
	//and push all the elem used into it
	priority_queue<charNode,vector<charNode>,cmp> pq;
	StaticHuffmanNode hfnode;
	for(int i=0;i<charNodeSize;i++)
	{
		if(charFreq[i].freq)
		{
			hfnode.left=hfnode.right=-1;
			hfnode.data=i;
			charFreq[i].addr=HuffmanT.size();
			HuffmanT.push_back(hfnode);
			pq.push(charFreq[i]);
		}
	}
	while(!pq.empty())
	{
		charNode tmpa,tmpb,tmpc;
		tmpa=pq.top();
		pq.pop();
		if(pq.empty())			//what if there is only one character
		{
			//return ERR;
		}
		else
		{
			tmpb=pq.top();
			pq.pop();
			int tmpaddr=addNode(tmpa.addr,tmpb.addr);
			tmpc.freq=tmpa.freq+tmpb.freq;
			tmpc.addr=tmpaddr;
			pq.push(tmpc);
		}
	}
	root=HuffmanT.size()-1;
	return OK;
}

Status HuffmanTree::generateCodingTable()
{
	string encodingStr="";
	recur_gen_table(root,encodingStr);
}

void HuffmanTree::recur_gen_table(int root,string encodingStr)
{
	if(HuffmanT[root].left==HuffmanT[root].right && HuffmanT[root].left==-1)
	{
		codingTable[HuffmanT[root].data]=encodingStr;
		return ;
	}
	else
	{
		recur_gen_table(HuffmanT[root].left,encodingStr+'0');
		recur_gen_table(HuffmanT[root].right,encodingStr+'1');
	}
}

int HuffmanTree::addNode(int laddr,int raddr)
{
	StaticHuffmanNode hfnode;
	hfnode.left=laddr;
	hfnode.right=raddr;
	hfnode.data='#';
	int pos=HuffmanT.size();
	HuffmanT.push_back(hfnode);
	
	return pos;
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
	//for(int i=0;i<charNodeSize;i++)
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
	createHuffmanTree();
	generateCodingTable();
	return ;
}

HuffmanTree::HuffmanTree():fileStr("")
{
	
}

HuffmanTree::~HuffmanTree()
{

}

#endif
