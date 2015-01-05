#include "comm.h"
#include "classHuffmanTree.h"
#include<iostream>
#include<string>
#include<QApplication>
#include"mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication desktopApp(argc,argv);
	HuffmanTree htree;
	mainWindow mainw;
	mainw.show();
	//htree.debug();
	/*ofstream of("text_output",ios_base::binary);
	ifstream ifs("test.in",ios_base::binary);
	char ch;
	string str="";
	//ifs>>str;
	while(ifs.peek()!=EOF)
	//while(!ifs.eof())
	{
		ifs.get(ch);
		str+=ch;
	}
	int len=str.length();
	for(int i=0;i<len;i++)
	{
		of.put(str[i]);
	}
	of.close();
	ifs.close();*/
	return desktopApp.exec();
	return 0;
}
