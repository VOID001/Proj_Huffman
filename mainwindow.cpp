#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classHuffmanTree.h"
//using namespace std;
//mainWindow::mainWindow(QWidget *parent) :
//        QMainWindow(parent),
//        ui(new Ui::mainWindow)
//{
//	ui->setupUi(this);
//}
//
//mainWindow::~mainWindow()
//{
//	delete ui;
//}
//
//void mainWindow::on_btnCompress_clicked(const QString&)
//{
//    txtToCompress->text();
//}
mainWindow::mainWindow()
{
	setupUi(this);
	btnCompress->setEnabled(false);
	btnExtract->setEnabled(false);
	txtTree->setEnabled(false);
	connect(btnCompress,SIGNAL(clicked()),this,SLOT(compressFile()));
	connect(btnExtract,SIGNAL(clicked()),this,SLOT(extractFile()));
	connect(txtToCompress,SIGNAL(textChanged(QString)),this,SLOT(enableCompressBtn(const QString& )));
	connect(txtHuff,SIGNAL(textChanged(QString)),this,SLOT(enableExtractBtn()));
	connect(txtTree,SIGNAL(textChanged(QString)),this,SLOT(enableExtractBtn()));
	connect(txtHuff,SIGNAL(textChanged(const QString&)),this,SLOT(setTreeName(const QString&)));
	connect(btnFileSel,SIGNAL(clicked()),this,SLOT(openFile()));
	
}

void mainWindow::compressFile()
{
	HuffmanTree HT;
	QString qsFile=txtToCompress->text();
	int flag=HT.compress(qsFile.toStdString());
	if(flag==OK)
	{
		lblStatus->setText("<font color=green>Compress OK! File save as "+qsFile+".huff</font>");
	}
	else
	{
		lblStatus->setText("<font color=red>Compress Failed! File Open Error</font>");
	}
	return ;
}

void mainWindow::extractFile()
{
	HuffmanTree HT;
	QString qhuff=txtHuff->text();
	QString qtree=txtTree->text();
	QString qsave=QFileDialog::getSaveFileName(this,"Select the place to save File","./","allFiles(*)");
	int flag=HT.extract(qhuff.toStdString(),qtree.toStdString(),qsave.toStdString());
	if(flag==OK)
	{
		lblStatus->setText("<font color=green>Extract OK!</font>");
	}
	else
	{
		lblStatus->setText("<font color=red>Extract Failed!</font>");
	}
	return ;
}

void mainWindow::enableCompressBtn(const QString& qs)
{
	btnCompress->setEnabled(!qs.isEmpty());
}

void mainWindow::enableExtractBtn()
{
	btnExtract->setEnabled(!(txtHuff->text().isEmpty() || txtTree->text().isEmpty()));
}

void mainWindow::setTreeName(const QString& qs)
{
	string tmp=qs.toStdString();
	int len=tmp.length();
	int k=9999;
	for(int i=len;i>=0;i--)
	{
		if(tmp[i]=='.') 
		{
			k=i;
			break;
		}
	}
	if(qs.isEmpty())
	{
		tmp="";
	}
	else
	{
		if(k!=9999)tmp.erase(k,len);
		tmp+=".treetable";
	}
	QString stmp;
	stmp=tmp.c_str();
	txtTree->setText(stmp);
}

void mainWindow::openFile()
{
	QString strFile=QFileDialog::getOpenFileName(this,"Select The File to Compress","./","allFiles(*)");
	txtToCompress->setText(strFile);
}

void mainWindow::on_btnHuffSel_clicked()
{
	QString strFile=QFileDialog::getOpenFileName(this,"Select The File to Extract","./","voidHuffFiles(*.huff)");
	txtHuff->setText(strFile);
}

void mainWindow::on_btnCompress_clicked()
{
    
}
