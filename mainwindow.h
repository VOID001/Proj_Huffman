#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include"classHuffmanTree.h"
#include"ui_mainwindow.h"
namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow,public Ui_mainWindow
{
	Q_OBJECT

public:
	mainWindow();

	//~mainWindow();

private slots:
	
	void compressFile();
	void extractFile();
	void enableCompressBtn(const QString&);
	void enableExtractBtn();
	void setTreeName(const QString&);
	void openFile();
    
    void on_btnHuffSel_clicked();
    
    void on_btnCompress_clicked();
    
private:
	Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
