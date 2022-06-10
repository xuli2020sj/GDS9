#pragma once
#include "CellCalculation.h"
#include "TriData.h"

class DEPost {
public:
    DEPost();
    ~DEPost();
    TriData TriDataB;
    CellCalculation CellB;
    TriDNodeHeadDefine *EHead;
    std::string m_Folder;
    GPoint _PA;
    GPoint _PB;
    GPoint _PGe;
    GPoint _PWaste;
    GCell _WD1;
    GCell _WD2;
    bool Process();
    void EProcess2(int key);
    std::string m_SavingFolder;
};
