
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"

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

    void OrderChoice(uint&);

    template <typename Data>
    ulong Resize(lasd::Vector<Data>&);

    template <typename Data>
    void Print(uint& choice, lasd::BinaryTree<Data>&);


    bool CheckExistence(lasd::BinaryTree<int>&);

    bool CheckExistence(lasd::BinaryTree<float>&);

    bool CheckExistence(lasd::BinaryTree<std::string>&);


/* ************************************************************************ */

// Random values generators    

    int getRandomInt();

    float getRandomFloat();

    std::string getRandomString();


/* ************************************************************************ */

// Filling Data Structure functions

    template <typename Data>
    void IntFill(lasd::Vector<Data>&);


    template <typename Data>
    void FloatFill(lasd::Vector<Data>&);


    template <typename Data>
    void StringFill(lasd::Vector<Data>&);


/* ************************************************************************ */

// Fold functions and Auxliary functions

    void FoldFunctInt(const int& , const void* , void*);

    void FoldFunctFloat(const float& , const void* , void* );

    void FoldFunctString(const std::string&, const void*, void*);


    void Fold(lasd::FoldableContainer<int>&);

    void Fold(lasd::FoldableContainer<float>& );

    void Fold(lasd::FoldableContainer<std::string>&);


/* ************************************************************************ */

// Specific Map functions and Auxliary functions

    void MapFunctInt(int&, void*);

    void MapFunctFloat(float&, void*);

    void MapFunctString(std::string& , void*);


    void Map(lasd::BinaryTree<int>&);

    void Map(lasd::BinaryTree<float>&);

    void Map(lasd::BinaryTree<std::string>&); 

    // template <typename Data>
    // void MapPrint(const Data&, void*);

    void MapPrint(const int&, void*);


/* ************************************************************************ */

// Tests

    template <typename Data>
    void Test(lasd::BinaryTree<Data>&);
   

/* ************************************************************************ */

// Data Structure Initialization

    void BTVec();

    void BTLnk();


/* ************************************************************************ */

// Main Menu

    void myTest();

    void Menu();

/* ************************************************************************** */

#endif
