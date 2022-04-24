
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : public virtual Queue<Data>,
                 protected virtual List<Data>{

private:

  // ...

protected:

  using List<Data>:: size;
  using List<Data>:: head;
  using List<Data>:: tail;


public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst<Data>&);

  // Move constructor
  QueueLst(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst<Data>& operator=(const QueueLst<Data>&);

  // Move assignment
  QueueLst<Data>& operator=(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst<Data>&) const noexcept;
  bool operator!=(const QueueLst<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  virtual const Data& Head() const override; // Override Queue member (constant version; must throw std::length_error when empty)
  virtual Data& Head() override; // Override Queue member (must throw std::length_error when empty)
  virtual void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  virtual Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  virtual void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  virtual void Enqueue(Data&&) override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
