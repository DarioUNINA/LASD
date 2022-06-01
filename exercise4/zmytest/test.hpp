
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../bst/bst.hpp"

 /* ************************************************************************** */
   // Print option functions

    void TypeChoose(ushort&);

    void OperationChoose(ushort&);

    void IOperationChoose(ushort&);

    void OrderChoice(uint&);


/* ************************************************************************ */

// Auxiliary functions

    int SetInt();

    double SetFloat();

    ulong SetLenght();


    template <typename Data>
    void MapPrint(const Data&, void*);

    template <typename Data>
    void Print(uint&, lasd::BST<Data>&);


    bool CheckExistence(lasd::BST<int>&);

    bool CheckExistence(lasd::BST<float>&);

    bool CheckExistence(lasd::BST<std::string>&);


    int setValue(lasd::BST<int>&);

    float setValue(lasd::BST<float>&);

    std::string setValue(lasd::BST<std::string>&);


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

// Tests
   
    template <typename Data>
    void Test(lasd::BST<Data>&);

    template <typename Data>
    void Test(lasd::Iterator<Data>&);


/* ************************************************************************ */

// Data Structure Initialization

    template <typename Data>
    void Iterator(lasd::BST<Data>&);

    void BST();


/* ************************************************************************ */

// Main Menu

    void Menu();

/* ************************************************************************** */

#endif
