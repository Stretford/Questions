//
//  questions.cpp
//  
//
//  Created by NStretford on 9/10/14.
//
//

#include "questions.h"
#include <iostream>
using namespace std;

bool AllOccurred(bool occur[], int n)
{
    for(int j = 0;j < n;j++)
    {
        if(occur[j] == false)
            return false;
    }
    return true;
}

bool NoneOccurred(bool occur[], int n)
{
    for(int j = 0;j < n;j++)
    {
        if(occur[j] == true)
            return false;
    }
    return true;
}

void findSubString(char text[], char dest[])
{
    char *t = text, *start = text, *d = dest, *temp = dest;
    int count = 0, length = 0;
    while(*temp)
    {
        count++;
        temp++;
    }
    bool occur[count];
    temp = dest;
    for(int i = 0;i < count;i++)
        occur[i] = false;
    
    while(*t)
    {
        bool in = false;
        for(int i = 0;i < count;i++)
        {
            if(*t == dest[i])
            {
                occur[i] = true;
                in = true;
            }
        }
        if(!in)
        {
            if(NoneOccurred(occur, count))
            {
                start++;
                t++;
                continue;
            }
        }
        
        length++;
        if(AllOccurred(occur, count))
        {
            for(int j = 0;j < length;j++, start++)
                cout<< *start;
            cout<<"\n";
            return;
        }
        t++;
            
    }
    cout<< "cannot find \n";
}



int test()
{
    return 777;
}