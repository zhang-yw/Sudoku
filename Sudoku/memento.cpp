#include "memento.h"

Memento::Memento()
{
    index = -1;
}

void Memento::clear()
{
    index = -1;
    action.clear();
}

int Memento::addAction(int position, int kind, vector<int> vec)
{
    Action a;
    a.index = position;
    a.enumOfAction = kind;
    a.nums = vec;
    if(index == action.size()-1)
    {
        if(action.size()<10)
        {
            action.push_back(a);
            index++;
        }
        else
        {
            if(action.size() == 10)
            {
                action.erase(action.begin());
                action.push_back(a);
            }
        }
    }
    else{
        vector<Action>::iterator itr = action.begin() + index + 1;
        while(itr != action.end())
        {
            itr = action.erase(itr);
        }
        action.push_back(a);
        index++;
    }
}


bool Memento::undo()
{
    if(index >= 0)
    {
        index = index - 1;
        return true;
    }
    return false;
}


bool Memento::redo()
{
    int m = action.size();
    if(index <  m - 1 && m != 0)
    {
        index = index + 1;
        return true;
    }
    return false;
}

bool Memento::checkAbleUndo()
{
    if(index >= 0)
    {
        return true;
    }
    return false;
}

bool Memento::checkAbleRedo()
{
    int m = action.size();
    if(index < m-1)
    {
        return true;
    }
    return false;
}
