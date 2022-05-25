
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
class HashTableClsAdr : HashTable<Data>{

private:

  // ...

protected:


  using HashTable<Data>::size;
  using HashTable<Data>::dim;


  Vector<BST<Data>> elements = Vector(dim);


public:

  // Default constructor
  HashTableClsAdr() = default;
                              // da rivedere la questione del vettore
  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const ulong&); // A hash table of a given size //questa serve per il resize
  HashTableClsAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer
  HashTableClsAdr(const LinearContainer<Data>& container, const ulong& newSize);/*: HashTableClsAdr(newSize){} HashTableClsAdr(container){}; // A hash table of a given size obtained from a LinearContainer //questa la usa 100%

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
  bool operator==(const HashTableClsAdr<Data>&) const noexcept; //prendi ogni valore e fai la exists nell' altra mappa, non sai come sono conservate in memoria (tipo cambia la funzione di pairing)
                                                               // fallo attraverso la map
  
  bool operator!=(const HashTableClsAdr<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)

  void Resize(const ulong&); // Resize the hashtable to a given size , fallo attraverso la map inserendo nella nuova hash ogni elemento

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value) //chiama hashkey protetta e inserisci il dato
  bool Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&)const noexcept; // Override TestableContainer member //tramite le map

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

  // type Clear() specifiers; // Override Container member


protected:

  void MapExists()

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
