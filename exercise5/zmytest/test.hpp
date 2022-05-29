
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"



 /* ************************************************************************** */
   // Print option functions

    void TypeChoose(ushort&);

    void OperationChoose(ushort&);

    void ImplementationChoose(ushort&);


/* ************************************************************************ */

// Auxiliary functions

    int SetInt();

    float SetFloat();

    ulong SetLenght();

    template <typename Data>
    void MapPrint(const Data&, void*);

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
    void Test(lasd::HashTable<Data>&);


/* ************************************************************************ */

// Data Structure Initialization

    void HashTable();

    void OpnAdr();

    void ClsAdr();


/* ************************************************************************ */

// Main Menu

    void Menu();

/* ************************************************************************** */

#endif
