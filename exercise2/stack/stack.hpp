
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack :public virtual Container{

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack<Data>& operator=(const Stack<Data>&) = delete;

  // Move assignment
  Stack<Data>& operator=(Stack<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Stack<Data>&) const noexcept = delete;
  bool operator!=(const Stack<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Top() const = 0; // (constant version; concrete function must throw std::length_error when empty)
  virtual Data& Top() = 0; // (concrete function must throw std::length_error when empty)
  virtual void Pop() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data TopNPop() = 0; // (concrete function must throw std::length_error when empty)
  virtual void Push(const Data&) = 0;
  virtual void Push(Data&&) = 0;

};

/* ************************************************************************** */

}

#endif
