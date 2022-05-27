
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
                              // da rivedere la questione del vettore
  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const ulong&); // A hash table of a given size //questa serve per il resize
  HashTableClsAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer
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

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value) //chiama hashkey protetta e inserisci il dato
  bool Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

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

  void FoldEx(FoldFunctor, const void*, void*) const;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
