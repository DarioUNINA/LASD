
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : public virtual Queue<Data>,
                 protected virtual Vector<Data>{

private:

  // ...

protected:

  using Vector<Data>:: size;
  using Vector<Data>:: Elements;

  ulong head = 0;
  ulong tail = 0;

public:


  // Default constructor
  QueueVec():Vector<Data>(1){};

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const LinearContainer<Data>& container):Vector<Data>(container), tail(container.Size()){};

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec<Data>& queue):Vector<Data>(queue), tail(queue.tail), head(queue.head){};

  // Move constructor
 QueueVec(QueueVec<Data>&& queue) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec<Data>& operator=(const QueueVec&);

  // Move assignment
  QueueVec<Data>& operator=(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec<Data>&) const noexcept;
  bool operator!=(const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  virtual Data& Head() const override; // Override Queue member (constant version; must throw std::length_error when empty)
  virtual Data& Head() override; // Override Queue member (must throw std::length_error when empty)
  virtual void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  virtual Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  virtual void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  virtual void Enqueue(Data&&) override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual bool Empty() const noexcept override; // Override Container member

  virtual ulong Size() const noexcept override; // Override Container member

  virtual void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  virtual void Expand();
  virtual void Reduce();
  virtual void SwapVectors(QueueVec<Data>&);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
