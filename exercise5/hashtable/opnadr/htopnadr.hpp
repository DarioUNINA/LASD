
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr { // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;

  // ...

  // Bisogna avere un vettore della stessa grandezza ma che contiene byte per sapere se l' elemento c'e' , non c' e' o e' stato eliminato


public:

  // Default constructor
  // HashTableOpnAdr() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a LinearContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

public:

  // Auxiliary member functions

  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers; //prende in input un indice
  // type Remove(argument) specifiers; //prende un indice
  // type HasKey(argument) specifiers; // a due parametri

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
