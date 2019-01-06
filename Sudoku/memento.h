#ifndef MEMENTO_H
#define MEMENTO_H

#include<vector>
using namespace std;

struct Action{
    int index;
    int enumOfAction;//0 means delete, 1 means insert.
    vector<int> nums;
};

class Memento
{
public:
    Memento();
    int count(){return action.size();}
    int getIndex(){return index;}
    int addAction(int,int,vector<int>);
    Action getAction(int i){return action[i];}
    bool redo();
    bool undo();
    bool checkAbleUndo();
    bool checkAbleRedo();
    void clear();

private:
    vector<Action> action;
    int index;
};

#endif // MEMENTO_H
