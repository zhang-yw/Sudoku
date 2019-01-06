//
//  SudokuCalculator.cpp
//  SudokuCalculator
//
//  Created by 张益玮 on 2017/8/30.
//  Copyright © 2017年 张益玮. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <array>
#include <random>
#include "SudokuCalculator.h"

void SudokuCalculator:: initialize(int *p)
{
    for(int i=0; i < 81; i++)
    {
        problem[i] = p[i];
    }
}

bool SudokuCalculator::check(int row, int column, int num)
{
    int rowStart = row*9;
    int index = row*9+column;
    for(int i = rowStart; i < rowStart+9; i++)
    {
        if(problem[i] == num && i != index)
            return false;
    }
    for(int i = column; i < 81; i = i+9)
    {
        if(problem[i] == num && i != index)
            return false;
    }
    int a = row/3;
    int b = column/3;
    for(int i = a*3; i <a*3+3; i++)
    {
        for(int j = b*3; j < b*3+3; j++)
        {
            if(problem[i*9+j] == num && i*9+j != index)
                return false;
        }
    }
    return true;
}

bool SudokuCalculator::dfs(int index)
{
    if(index > 80)
    {
        return true;
    }
    if(!problem[index])
    {
        std::array<int,9> numbers = {1,2,3,4,5,6,7,8,9};        
        if(randomGenerate)
        {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle(numbers.begin(),numbers.end(), std::default_random_engine(seed));
        }
        for(int i = 1; i <= 9; i++)
        {
            problem[index] = numbers[i-1];
            if(check(index/9, index%9, numbers[i-1]))
            {
                if(dfs(index+1))
                {
                    return true;
                }
            }
            problem[index] = 0;
        }
    }
    else{
        return dfs(index+1);
    }
    return false;
}

int* SudokuCalculator::calculator()
{
    dfs(0);
    return problem;
}
