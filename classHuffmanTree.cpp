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

Status HuffmanTree::compress(const string& fileName)
{
	IIF(open(fileName));
	IIF(countFreq());
	IIF(createHuffmanTree());
	IIF(generateCodingTable());
	IIF(pr_compress(fileName));
	fileStr.clear();
	return OK;
}

Status HuffmanTree::extract(const string& fileName,const string& treeName,const string& destName)
{
	HuffmanT.clear();
	//Clear codingTable;
	readTreefromFile(treeName);
	open(fileName);
	pr_extract(destName);
}

Status HuffmanTree::pr_compress(const string& fileName)
{
	//Open the output File
	string newName=fileName;
	ofstream of(newName.c_str(),ios_base::binary);			//use binary IO
	if(of)
	{
		//Compress the Tree
		char ch=0;
		int head=0;
		int fileStrlen=fileStr.length();
		for(long long i=0;i<fileStrlen;i++)
		{
			string tmpcodestr=codingTable[fileStr[i]+128];
			int encodeLen=tmpcodestr.length();
			for(int j=0;j<encodeLen;j++)
			{
				if(head==8)
				{
					of.put(ch);
					head=0;
					ch=0;
				}
				if(tmpcodestr[j]=='0')
				{
					ch|=0;
					if(head!=7) ch<<=1;
					head++;
				}
				else if(tmpcodestr[j]=='1')
				{
					ch|=1;
					if(head!=7) ch<<=1;
					head++;
				}
			}
		}
		if(ch)
		{
			ch<<=(7-head);
			of.put(ch);
		}
		of.close();
		//Write the StaticHuffmanTree into File
		//First to an array
		//then to file
		//StaticHuffmanNode *tmpHuffT=new StaticHuffmanNode[1500];
		//int* ptest=new int[root];
		StaticHuffmanNode tmpHuffT[treeLength];
		memset(tmpHuffT,0,sizeof(tmpHuffT));
		printf("%d\n",sizeof(tmpHuffT));
		int counter=0;
		for(vector<StaticHuffmanNode>::iterator si=HuffmanT.begin();si!=HuffmanT.end();si++)
		{
			tmpHuffT[counter]=*si;
			counter++;
		}
		tmpHuffT[treeLength-1].data=root;
		tmpHuffT[treeLength-1].left=tmpHuffT[treeLength-1].right=root;
		newName=fileName+".treetable";
		FILE *ofp;
		ofp=fopen(newName.c_str(),"wb");			//use binary IO
		fwrite(tmpHuffT,sizeof(StaticHuffmanNode),treeLength,ofp);
		fclose(ofp);
		//of.open(newName.c_str());
		//of.write(tmpHuffT,counter-1);
		
		printf("OK");
		return OK;
	}
	else
	{
		return ERR;
	}

}

Status HuffmanTree::pr_extract(const string& fileName)
{
	char ch=0;
	int ptr=root;
	int head=0;
	char chmask=0x80;			//binary mode 1000 0000
	long long len=fileStr.length();
	ofstream of(fileName.c_str(),ios_base::binary);
	if(of)
	{
		for(long long i=0;i<len;i++)
		{
			ch=fileStr[i];
			head=0;
			while(head<=7)
			{
				if(HuffmanT[ptr].left==HuffmanT[ptr].right && HuffmanT[ptr].left==-1)
				{
					of.put(char(HuffmanT[ptr].data-128));
					ptr=root;
				}
				if(ch&chmask)
				{
					ptr=HuffmanT[ptr].right;
				}
				else
				{
					ptr=HuffmanT[ptr].left;
				}
				ch<<=1;
				head++;
			}
		}
		of.close();
		return OK;
	}
	else
	{
		return ERR;
	}
}

Status HuffmanTree::open(const string& addr)
{
	//Open with fstream

	ifstream fs(addr.c_str(),ios_base::binary);		//use binary IO
	if(fs.is_open())
	{
		char ch;									//Some char in binary files exclude the size of char How to deal with it ??????
		while(fs.peek()!=EOF)
		{
			fs.get(ch);
			//printf("%5d\t",ch);
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
	return OK;
}

void HuffmanTree::recur_gen_table(int root,string encodingStr)
{
	if(HuffmanT[root].left==HuffmanT[root].right && HuffmanT[root].left==-1)
	{
		int tmpid=HuffmanT[root].data<0?HuffmanT[root].data+256:HuffmanT[root].data;
		//codingTable[HuffmanT[root].data]=encodingStr;
		codingTable[tmpid]=encodingStr;
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
		//charFreq[fileStr[i]].freq++;		//??fileStr[i] maybe a negative number
		charFreq[fileStr[i]+128].freq++;		//??fileStr[i] maybe a negative number ,add 128 to the val so it will be positive
	}
	//Debug
	for(int i=0;i<charNodeSize;i++)
	{
		if(charFreq[i].freq)
		{
			printf("%c(%d)=%d\n",i-128,i,charFreq[i].freq);
		}
	}
	//End Debug
	return OK;
}


Status HuffmanTree::readTreefromFile(const string& treeName)
{
	FILE* fp=NULL;
	fp=fopen(treeName.c_str(),"rb");
	if(!fp)
	{
		return ERR;
	}
	else
	{
		StaticHuffmanNode tmpHuffT[treeLength];
		fread(tmpHuffT,sizeof(StaticHuffmanNode),treeLength,fp);
		fclose(fp);

		for(int i=0;i<treeLength;i++)
		{
			HuffmanT.push_back(tmpHuffT[i]);
		}
		root=tmpHuffT[treeLength-1].right;
	}

}


void HuffmanTree::debug()
{
	compress("test.in");
	extract("test.in.huff","test.in.treetable");
	return ;
}

HuffmanTree::HuffmanTree():fileStr("")
{

}

HuffmanTree::~HuffmanTree()
{

}

#endif
