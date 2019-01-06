//
//  SudokuGenerator.h
//  SudokuCalculator
//
//  Created by 张益玮 on 2017/8/30.
//  Copyright © 2017年 张益玮. All rights reserved.
//

#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "SudokuCalculator.h"

class SudokuGenerator
{
    int problem[80];
    int solution[80];
    SudokuCalculator* calculator;
    int level;
public:
    SudokuGenerator();
    int* getProblem();
    void setlevel(int m){level = m;}
    int getSolution(int);
};

#endif /* SudokuGenerator_h */
