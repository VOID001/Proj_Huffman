/*************************************************************************
    > File Name: structs.h
    > Author: VOID_133 > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月29日 星期一 19时38分21秒
	> Content: Define the Node structs
	> LastModified:2014-12-29 19:38
 ************************************************************************/

#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef struct node{
	int left;
	int right;
	char data;
}StaticHuffmanNode;

typedef struct nodea{
	long long freq;
	int addr;
}CodingTable;

#endif
