#ifndef CLASSHUFFMANTREE_H
#define CLASSHUFFMANTREE_H
#include"comm.h"
#include"struct.h"

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

#endif // CLASSHUFFMANTREE_H
