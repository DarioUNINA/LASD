
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  Iterator<Data>& operator=(const Iterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Iterator<Data>& operator=(Iterator<Data>&&) noexcept = delete; // Copy assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Iterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Iterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& operator*() const = 0; // (concrete function must throw std::out_of_range when terminated)
                                  //Usato come un puntatore

  virtual bool Terminated() const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data>{ // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  Iterator<Data>& operator=(const Iterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Iterator<Data>& operator=(Iterator<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(Iterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(Iterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Iterator<Data>& operator++() = 0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BackwardIterator { // Must extend Iterator<Data> //non va implementato

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BackwardIterator() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator--() specifiers; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BidirectionalIterator {//non va implementato
                              // Must extend ForwardIterator<Data>,
                              //             BackwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BidirectionalIterator() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Terminated() specifiers; // Override Iterator member

  // type ForwardTerminated() specifiers; // (concrete function should not throw exceptions)

  // type BackwardTerminated() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : virtual public Iterator<Data>{

private:

protected:

public:

  // Destructor
  virtual ~ResettableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResettableIterator<Data>& operator=(const ResettableIterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ResettableIterator<Data>& operator=(ResettableIterator<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResettableIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ResettableIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Reset() noexcept = 0; // (concrete function should not throw exceptions)
                              // torna in posizione iniziale
                              // necessita quindi di sapere qual e' la root ( nel caso degli alberi)
                              // l' impelementazione con creta sta in binarytree

};

/* ************************************************************************** */

}

#endif
