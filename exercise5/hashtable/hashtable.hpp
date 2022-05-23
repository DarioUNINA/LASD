
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hash {

public:

  ulong operator()(const Data&) const noexcept;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : public DictionaryContainer<Data>,
                  public MappableContainer<Data>,
                  public FoldableContainer<Data>{

private:
-
  // ...

protected:

  using DictionaryContainer<Data>::size; //da settare come un primo abbastanza grande

  Hash<Data> hash;

  ulong A = 0;
  ulong B = 1;

public:

  // Destructor
  ~HashTable() default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable<Data> operator=(const HashTable<Data>&) = delete;

  // Move assignment
  HashTable<Data> operator=(HashTable<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable<Data>&) const noexcept = delete;
  bool operator!=(const HashTable<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  bool Resize(const ulong&); // Resize the hashtable to a given size

protected:

  // Auxiliary member functions

  ulong HashKey(const ulong&) const noexcept; // prende il dato, fa la hash di codifica e poi inserendolo nella funzione di indirizzamento e ritorna il valore

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
