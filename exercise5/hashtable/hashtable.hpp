
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../bst/bst.hpp"

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
class HashTable : public DictionaryContainer<Data>{

private:
-
  // ...

protected:

  using DictionaryContainer<Data>::size = std::pow(2, 7);

  Hash<Data> hash{};

  const ulong prime = 65537;

  ulong A = getRandom(1);
  ulong B = getRandom(0);

public:

  // Destructor
  ~HashTable() = default;

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

  bool Resize(const ulong&) = 0;

protected:

  // Auxiliary member functions

  ulong HashKey(const Data&) const noexcept; // prende il dato, fa la hash di codifica e poi inserendolo nella funzione di indirizzamento e ritorna il valore

  ulong getRandom(const ushort& start) const noexcept{
    std::default_random_engine genx(std::random_device{}());
    std::uniform_int_distribution<ulong> distx(start, prime-1);
    return distx(genx);
  }

  HashTable(const HashTable<Data>& table) : prime(table.prime), A(table.A), B(table.B) {size = table.size};

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
