
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
  using HashTable<Data>::A;
  using HashTable<Data>::B;


  ulong a = HashTable<Data>::getRandom(0);
  ulong b = HashTable<Data>::getRandom(1);
  ulong p = 4001;

  ulong ts = 0;

  Vector<Data> elements {dim};
  Vector<ushort> flag {dim};


public:

  // Default constructor
  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors

  HashTableOpnAdr(const ulong& newSize){
      dim = FindSize(newSize);
      elements.Resize(dim);
      flag.Resize(dim);
  };
  

  HashTableOpnAdr(const LinearContainer<Data>& container){
        DictionaryContainer<Data>::Insert(container);
  };


  HashTableOpnAdr(const ulong& newSize, const LinearContainer<Data>& container): HashTableOpnAdr(newSize){
    DictionaryContainer<Data>::Insert(container);

};

  
  /* ************************************************************************ */

  // Copy constructor

  HashTableOpnAdr(const HashTableOpnAdr<Data>& table): elements(table.elements), flag(table.flag), ts(table.ts), a(table.a), b(table.b){
    A = table.A;
    B = table.B;
    dim = table.dim;
    size = table.size;
  }


  // Move constructor

  HashTableOpnAdr(HashTableOpnAdr<Data>&& table): HashTable<Data>::HashTable(std::move(table)){
    std::swap(elements, table.elements);
    std::swap(flag, table.flag);
    std::swap(ts, table.ts);
    std::swap(a, table.a);
    std::swap(b, table.b);
}


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

  bool Exists(const Data&) const noexcept;

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

  ulong  Find(const Data&, ulong&) const noexcept;

  ulong FindEmpty(const Data&, ulong&) const noexcept;
  
  bool Remove(const Data&, ulong&);
  
  ulong HashKey(const Data&, const ulong&) const noexcept;

  ulong HashKey(const Data&, const ulong&, const ulong&) const noexcept;

  ulong FindSize(const ulong&) const noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
