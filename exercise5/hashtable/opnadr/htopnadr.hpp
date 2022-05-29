
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{

private:

  // ...

protected:

  using HashTable<Data>::size;
  using HashTable<Data>::dim;
  using HashTable<Data>::prime;
  using HashTable<Data>::hash;

  ulong ts = 0;

  Vector<Data> elements {dim};
  Vector<ushort> flag {dim};


public:

  // Default constructor
  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const ulong&);
  HashTableOpnAdr(const LinearContainer<Data>&);
  HashTableOpnAdr(const ulong&, const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr<Data>&);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr<Data>& operator=(const HashTableOpnAdr<Data>&);

  // Move assignment
  HashTableOpnAdr<Data>& operator=(HashTableOpnAdr<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr<Data>&) const noexcept;
  bool operator!=(const HashTableOpnAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)

  void Resize(const ulong&);

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override;
  bool Insert(Data&&) override;
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor, void *) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override;

protected:

  // Auxiliary member functions

  virtual void FoldEx(FoldFunctor, const void*, void*) const;

  long int Find(const Data&, ulong&) const noexcept;

  ulong FindEmpty(const Data&, ulong&) const noexcept;
  
  bool Remove(const Data&, ulong&);
  
  ulong HashKey(const Data&, const ulong&) const noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
