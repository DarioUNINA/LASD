
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>
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
class HashTable : virtual public DictionaryContainer<Data>,
                  virtual public MappableContainer<Data>,
                  virtual public FoldableContainer<Data>{

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;
  ulong dim = std::pow(2, 7);

  Hash<Data> hash{};

  const ulong prime = 65537;
  ulong A = getRandom(1);
  ulong B = getRandom(0);

public:

  // Constructor

  HashTable() = default;

  // Destructor
  ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable<Data>& operator=(const HashTable<Data>&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable<Data>&) const noexcept = delete;
  bool operator!=(const HashTable<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  virtual void Resize(const ulong&) = 0;

  /* ************************************************************************ */

  // Print Function

  virtual void Print() noexcept;

protected:


// Copy and Move Constructors

  HashTable(const HashTable<Data>& table) : A(table.A), B(table.B), dim(table.dim) {size = table.size;};


  HashTable(HashTable<Data>&& table) {std::swap(A, table.A); std::swap(B, table.B); std::swap(size, table.size); std::swap(dim, table.dim); };


/* ************************************************************************** */

// Move Assignment

  HashTable& operator=(HashTable<Data>&& table) noexcept {std::swap(A, table.A); std::swap(B, table.B); std::swap(size, table.size); std::swap(dim, table.dim); return *this; };


/* ************************************************************************** */

  // Auxiliary member functions

  ulong HashKey(const Data&) const noexcept;

  ulong getRandom(const ushort& start) const noexcept{
    std::default_random_engine genx(std::random_device{}());
    std::uniform_int_distribution<ulong> distx(start, prime-1);
    return distx(genx);
  };


};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
