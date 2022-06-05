
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../bst/bst.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : public HashTable<Data>{

private:

  // ...

protected:


  using HashTable<Data>::size;
  using HashTable<Data>::dim;

  Vector<BST<Data>> elements {dim};


public:

  // Default constructor
  HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const ulong&);

  HashTableClsAdr(const LinearContainer<Data>&);

  HashTableClsAdr(const ulong&, const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr<Data>& operator=(const HashTableClsAdr<Data>&);

  // Move assignment
  HashTableClsAdr<Data>& operator=(HashTableClsAdr<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr<Data>&) const noexcept;
  bool operator!=(const HashTableClsAdr<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)

  void Resize(const ulong&);

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override;

  bool Insert(Data&&) override;

  bool Insert(const LinearContainer<Data> container) { return DictionaryContainer<Data>::Insert(container);};

  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override;


protected:

  void FoldEx(FoldFunctor, const void*, void*) const;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
