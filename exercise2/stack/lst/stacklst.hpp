
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : public Stack<Data>,
                 protected virtual List<Data>{

private:

  // ...

protected:

  using List<Data>:: size;
  using List<Data>:: head;


public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst<Data>&);

  // Move constructor
  StackLst(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst<Data>& operator=(const StackLst<Data>&);

  // Move assignment
  StackLst<Data>& operator=(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst<Data>&) const noexcept;
  bool operator!=(const StackLst<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  virtual Data& Top() const override; // Override Stack member (constant version; must throw std::length_error when empty)
  virtual Data& Top() override; // Override Stack member (must throw std::length_error when empty)
  virtual void Pop() override; // Override Stack member (must throw std::length_error when empty)
  virtual Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  virtual void Push(const Data&) override; // Override Stack member (copy of the value)
  virtual void Push(Data&&) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
