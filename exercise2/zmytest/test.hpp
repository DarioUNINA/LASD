
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../container/container.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"


 /* ************************************************************************** */
   // Print option functions

    void DataStructureChoose(ushort&);

    void TypeChoose(ushort&);

    void OperationChoose(ushort&);

/* ************************************************************************ */

// Auxiliary functions

    int SetInt();

    float SetFloat();

    ulong SetLenght();

/* ************************************************************************ */

// Random values generators    

    int getRandomInt();

    float getRandomFloat();

    std::string getRandomString();

/* ************************************************************************ */

// Specific Insert Auxiliary FUnctions

    void Insert(lasd::Stack<int>&);

    void Insert(lasd::Stack<float>&);

    void Insert(lasd::Stack<std::string>&);

    void Insert(lasd::Queue<int>&);

    void Insert(lasd::Queue<float>&);

    void Insert(lasd::Queue<std::string>&);

/* ************************************************************************ */

// Filling Data Structure functions

    void Fill(lasd::Stack<int>&);

    void Fill(lasd::Queue<int>&);

    void Fill(lasd::Stack<float>&);

    void Fill(lasd::Queue<float>&);

    void Fill(lasd::Stack<std::string>&);

    void Fill(lasd::Queue<std::string>&);

/* ************************************************************************ */

// Tests

    template <typename Data>
    void StackTest(lasd::Stack<Data>&);

    template <typename Data>
    void QueueTest(lasd::Queue<Data>&);


/* ************************************************************************ */

// Data Structure Initialization

    void StackVec();

    void StackLst();

    void QueueVec();

    void QueueLst();

/* ************************************************************************ */

// Main Menu

    void myTest();

    void Menu();

/* ************************************************************************** */

#endif
