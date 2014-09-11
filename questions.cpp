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

void reverse_word(char word[])
{
    char *last = word, *first = word;
    if(first == NULL)
        return;
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
    while(*first)
    {
        cout<< *first;
        first++;
    }
    cout<< "\n";
}

char *space(char *c)
{
    c = (char *)malloc(100);
    return c;
}

void test()
{
    char word[] = "abcde";
    char *p = word;
    //reverse_word(word);
    char *s = NULL;
    s = space(s);
    strcpy(s, "hello");
    printf("%s", s);
}


