//
//  questions.cpp
//  
//
//  Created by NStretford on 9/10/14.
//
//

#include "questions.h"
#include <iostream>
#include <string>
using namespace std;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
typedef struct linkedlist
{
    int data;
    linkedlist *next;
}node;

void print_ll(node *head)
{
    node *p = head;
    while(p)
    {
        cout<< p->data << "->";
        p = p->next;
    }
}

node *create_ll()
{
    node *head = (node *)malloc(sizeof(linkedlist));
    node *p1 = (node *)malloc(sizeof(linkedlist));
    p1->data = 21;
    node *p2 = (node *)malloc(sizeof(linkedlist));
    p2->data = 2;
    head->next = p1;
    p1->next = p2;
    p2->next = NULL;
    return head;
}



node *reverse_LL(node *head)
{
    node *p = head, *p1 = p->next, *p2;
    if(head == NULL || head->next == NULL)
        return head;
    while(p1)
    {
        p2 = p1->next;
        p1->next = p;
        p = p1;
        p1 = p2;
    }
    head->next = NULL;
    head = p;
    return head;
}

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
    if(t == NULL || d == NULL)
        return;
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

void print_str(char *p)
{
    while(*p)
    {
        cout<< *p;
        p++;
    }
}

char* reverse_word(char *word)
{
    char *last = word, *first = word;
    if(first == NULL)
        return word;
    int count = 0;
    while(*last)
    {
        last++;
        
    }
    last--;
    char c;
    while(*first != *last)
    {
        c = *first;
        *first = *last;
        *last = c;
        first++;
        last--;
    }
    first = word;
    print_str(first);
    cout<< "\n";
    return word;
}

void loopMove(char *str, int step)
{
    if(str == NULL)
        return;
    int n = strlen(str) - step;
    char temp[strlen(str)];
    memcpy(temp, str + n, step);
    memcpy(temp + step, str, n);
    print_str(temp);
}

int LCS(char *s1, char *s2)     //Longest Common Substring, time:O(m*n) storage:O(min(m,n))
{
    if(s1 == NULL || s2 == NULL)
        return 0;
    char *p1 = s1, *p2 = s2;
    int len1 = strlen(s1), len2 = strlen(s2), result = 0;
    int m1[len1];
    for(int i = 0;i < len1;i++)
        m1[i] = 0;
    
    for(int i = 0;i < len2;i++)
    {
        for(int j = len1 - 1;j >= 0;j--)
        {
            if(i == 0 || j == 0)
            {
                if(*(p1 + j) == *(p2 + i))
                    m1[j] = 1;
                else
                    m1[j] = 0;
            }
            else
            {
                if(*(p1 + j) == *(p2 + i))
                {
                    m1[j] = m1[j - 1] + 1;
                    if(m1[j] > result)
                        result = m1[j];
                }
                else
                    m1[j] = 0;
            }
        }
    }
    return result;
}

int LRS(char *s)        //Longest Recursive Substring
{
    char reverse[strlen(s)];
    char *r = reverse;
    strcpy(r, s);
    r = reverse_word(r);
    print_str(r); cout<<"\n";
    return LCS(s, r);
}

void test()
{
    char word[] = "abcde";
    char *p = word;
    char s1[] = "1abbba2";
    cout<<"LRS:" <<LRS(s1) <<"\n";
}


