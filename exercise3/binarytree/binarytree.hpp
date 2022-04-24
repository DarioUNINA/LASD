
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

// #include "..."  potrebbero servire stack e queue

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree {
                   // Must extend PreOrderMappableContainer<Data>,
                   //             PostOrderMappableContainer<Data>,
                   //             InOrderMappableContainer<Data>,
                   //             BreadthMappableContainer<Data>,
                   //             PreOrderFoldableContainer<Data>,
                   //             PostOrderFoldableContainer<Data>,
                   //             InOrderFoldableContainer<Data>,
                   //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // using InOrder/BreadthMappableContainer<Data>::???;

  // ...

public:

  struct Node {

  private:

    // ...

  protected:

    // ...
    //Potrebbe gia' esserci il campo key

  public:

    // friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Comparison operators DEVONO ESSERRE PROTETTI (torna utile implementarli)
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.

    /* ********************************************************************** */

    // Specific member functions

    // Element potrebbe essere implementata se si implementa il campo key
    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions) CONST
    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions) NON CONST

    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible. /IL CONFRONTO TRA NODI DEVE CONFRONTARE ANCHE I FIGLI
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible. /DI CONSEGUENZA BASTA CONFRONTARE LE DUE RADICI

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  //FOld e Map vanno implementate qui, basta fare l' algoritmo ricorsivo ( possiamo scorrere tutto l' albero gia' qui)

  // Specific member functions (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;

  // type Map(arguments) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Override InOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Override BreadthFoldableContainer member

protected:

  // Auxiliary member functions (for PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator {
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:

  // ... puntatore al nodo corrente (current)

public:

  // Specific constructors
  // BTPreOrderIterator(riferimanto all' albero) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated) accesso a element del nodo che sta puntando current

  // type Terminated() specifiers; // (should not throw exceptions) se il puntatore a current e' nullptr 

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions) ricordati di svuotare lo stack o la coda

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator {
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;

  // Move constructor
  // BTInOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;

  // Move constructor
  // BTBreadthIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
