//
//  SudokuCalculator.h
//  SudokuCalculator
//
//  Created by 张益玮 on 2017/8/30.
//  Copyright © 2017年 张益玮. All rights reserved.
//

#ifndef SudokuCalculator_h
#define SudokuCalculator_h

#include <array>

class SudokuCalculator
{
    int problem[81];
    bool randomGenerate = false;
public:
    void initialize(int*);
    int* calculator();
    void setRandomGenerate(bool is){randomGenerate = is;}
private:
    bool check(int, int, int);
    bool dfs(int);
};

#endif /* SudokuCalculator_h */
