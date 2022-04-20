
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : public virtual Stack<Data>,
                 protected virtual Vector<Data>{

private:

  // ...

protected:

  ulong head = 0;

  using Vector<Data>:: Elements;
  using Vector<Data>:: size;

public:

  // Default constructor
  StackVec():Vector<Data>(1){};

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const LinearContainer<Data>& container):Vector<Data>(container), head(size){};

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec<Data>& stack):Vector<Data>(stack), head(stack.head){};

  // Move constructor
  StackVec(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec<Data>&);

  // Move assignment
  StackVec<Data>& operator=(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec<Data>&) const noexcept;
  bool operator!=(const StackVec<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  virtual Data& Top() const override;
  virtual Data& Top() override;
  virtual void Pop() override;
  virtual Data TopNPop() override;
  virtual void Push(const Data&) override;
  virtual void Push(Data&&) noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual bool Empty() const noexcept override;
  virtual ulong Size() const noexcept override;
  virtual void Clear() override;

protected:

  // Auxiliary member functions

  virtual void Expand();
  virtual void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
