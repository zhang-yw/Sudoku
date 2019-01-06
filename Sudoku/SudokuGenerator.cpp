//
//  SudokuGenerator.cpp
//  SudokuCalculator
//
//  Created by 张益玮 on 2017/8/30.
//  Copyright © 2017年 张益玮. All rights reserved.
//

#include <stdio.h>
#include <memory.h>
#include <array>
#include <iostream>
#include <random>
#include "SudokuGenerator.h"

SudokuGenerator::SudokuGenerator()
{
    level = 1;
    calculator = new SudokuCalculator;
    calculator->setRandomGenerate(true);
}

int* SudokuGenerator::getProblem()
{
    int initializer[81] = {0};
    std::array<int,9> numbers = {1,2,3,4,5,6,7,8,9};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(numbers.begin(),numbers.end(), std::default_random_engine(seed));
    for(int i = 0; i < 9; i++)
    {
        initializer[i] = numbers[i];
    }
    calculator->initialize(initializer);
    int* p = calculator->calculator();
    for(int i =0 ;i < 81;i++)
    {
        solution[i] = p[i];
    }
    std::array<int,81> random;
    for(int i = 0; i<81;i++)
    {
        random[i] = i;
    }
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(random.begin(),random.end(), std::default_random_engine(seed));
    int nums[4] = {0, 9, 49, 53};
    int exactNum = nums[level];
    for(int i = 0; i<exactNum; i++)
    {
        p[random[i]]=0;
    }
    return p;
}

int SudokuGenerator::getSolution(int i)
{
    return solution[i];
}

