
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../container/container.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

 /* ************************************************************************** */
   // Print option functions

    void DataStructureChoose(ushort&);

    void TypeChoose(ushort&);

    void VecOperationChoose(ushort&);

    void ListOperationChoose(ushort&);

/* ************************************************************************ */

// Auxiliary functions

    int SetInt();

    float SetFloat();

    ulong SetLenght();

    void SetIndex(ulong&, const ulong&);

    template <typename Data>
    ulong Resize(lasd::Vector<Data>&);


/* ************************************************************************ */

// Random values generators    

    int getRandomInt();

    float getRandomFloat();

    std::string getRandomString();


/* ************************************************************************ */

// Filling Data Structure functions

    void IntFill(lasd::Vector<int>&);


    void FloatFill(lasd::Vector<float>&);


    void StringFill(lasd::Vector<std::string>&);


/* ************************************************************************ */

// Fold functions and Auxliary functions

    void FoldFunctInt(const int& , const void* , void*);

    void FoldFunctFloat(const float& , const void* , void* );

    void FoldFunctString(const std::string&, const void*, void*);

    template <typename Data>
    void FoldInt(lasd::FoldableContainer<Data>&);

    template <typename Data>
    void FoldFloat(lasd::FoldableContainer<Data>& );

    template <typename Data>
    void FoldString(lasd::FoldableContainer<Data>&);


/* ************************************************************************ */

// Specific Map functions

    void MapFunctInt(int&, void*);

    void MapFunctFloat(float&, void* );

    void MapFunctString(std::string& , void* );

    void MapPrintInt(const int&, void* );

    void MapPrintFloat(const float&, void*);

    void MapPrintString(const std::string&, void*); 

/* ************************************************************************ */

// Vector Tests


    void IntTest(lasd::Vector<int>&);

    void FloatTest(lasd::Vector<float>&);

    void StringTest(lasd::Vector<std::string>&);

//List Tests

    void IntTest(lasd::List<int>&);

    void FloatTest(lasd::List<float>&);

    void StringTest(lasd::List<std::string>&);

    void Vector();

    void List();


/* ************************************************************************ */

// Main Menu

    void myTest();

    void Menu();

/* ************************************************************************** */

#endif
