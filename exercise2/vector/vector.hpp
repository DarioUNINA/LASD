
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : public virtual LinearContainer<Data>,
               public virtual PreOrderMappableContainer<Data>, 
               public virtual PreOrderFoldableContainer<Data>,
               public virtual PostOrderMappableContainer<Data>,
               public virtual PostOrderFoldableContainer<Data>{

private:

  // ...

protected:

  using LinearContainer<Data>:: size;

  Data* Elements = nullptr;

public:

  // Default constructor
   Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong);
  Vector(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector<Data>&);

  // Move constructor
  Vector(Vector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  Vector<Data>& operator=(const Vector<Data>&);

  // Move assignment
  Vector<Data>& operator=(Vector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector<Data>&) const noexcept;
  bool operator!=(const Vector<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(const ulong);

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  virtual Data& Front() const override;
  virtual Data& Back() const override;

  Data& operator[](const ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  virtual void MapPreOrder(MapFunctor, void*) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  virtual void MapPostOrder(MapFunctor, void*) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const override;
};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
