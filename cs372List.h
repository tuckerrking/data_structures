//
//  cs372List.h
//  cs372_headers
//
//  Created by Tucker King on 9/20/21.
//

// NOTE: Based on code provided in class by professor

#ifndef cs372List_h
#define cs372List_h
#pragma once

#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
    class Node
    {
    public:
        T data;
        Node *prev;
        Node *next;
    };
    Node *head= nullptr;
    Node *tail= nullptr;
    
    void setupList()
    {
        Node *newNode= new Node();
        newNode->next= nullptr;
        newNode->prev= nullptr;
        head= newNode;
        tail= newNode;
    }
    
    void deleteListContents()
    {
        Node *temp= nullptr;
        Node *current= head;
        while(current!= nullptr)
        {
            temp= current->next;
            delete current;
            current= temp;
        }
    }
public:
    List() : head(nullptr), tail(nullptr) {}
    
    List(T newData)
    {
        setupList();
        head->data= newData;
    }
    
    List(List& rhs) //Copy constructor
    {
        deleteListContents();
        head= rhs.head;
        tail= rhs.tail;
    }
    
    ~List() //Destructor
    {
        deleteListContents();
    }
    
    bool empty()
    {
        return(head== nullptr);
    }
    
    void push_front(T data)
    {
        Node *newNode = new Node();
        newNode->data= data;
        newNode->next= head;
        newNode->prev= nullptr;
        
        if(empty())
        {
            head= newNode;
            tail= newNode;
        }
        else
        {
            head->prev= newNode;
            head= newNode;
        }
    }
    
    void push_back(T data)
    {
        Node *newNode= new Node();
        newNode->data= data;
        newNode->next= nullptr;
        newNode->prev= tail;
        
        if(empty())
        {
            tail= newNode;
            head= newNode;
        }
        else
        {
            tail->next= newNode;
            tail= newNode;
        }
    }
    
    void pop_back()
    {
        Node *lastNode= tail;
        
        if(lastNode!= nullptr)
        {
            tail= tail->prev;
            tail->next= nullptr;
            delete lastNode;
        }
    }
    
    T front()
    {
        if(!empty())
        {
            return head->data;
        }
        else
        {
            cout << "Exception: list is empty." << endl;
            exit(1);
        }
    }
    
    T back()
    {
        if(!empty())
        {
            return tail->data;
        }
        else
        {
            cout << "Exception: list is empty." << endl;
            exit(1);
        }
    }
    
    void traverse(void(*doIt)(T data))
    {
        Node *current= head;
        
        while(current!= nullptr)
        {
            doIt(current->data);
            current= current->next;
        }
    }
};

#endif /* cs372List_h */
