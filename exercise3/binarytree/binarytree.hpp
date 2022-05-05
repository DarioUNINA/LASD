
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/lst/queuelst.hpp"

#include "../stack/lst/stacklst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public PreOrderMappableContainer<Data>,
                  virtual public PostOrderMappableContainer<Data>,
                  virtual public InOrderMappableContainer<Data>,
                  virtual public BreadthMappableContainer<Data>,
                  virtual public PreOrderFoldableContainer<Data>,
                  virtual public PostOrderFoldableContainer<Data>,
                  virtual public InOrderFoldableContainer<Data>,
                  virtual public BreadthFoldableContainer<Data>{

private:

  // ...

protected:

  using BreadthFoldableContainer<Data>::size;

public:

  struct Node {

  private:

    // ...

  protected:

    Data key;

    /* ********************************************************************** */

    bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&) noexcept = delete; // Move assignment of abstract types should not be possible.


    /* ********************************************************************** */

    // Specific member functions

    // Element potrebbe essere implementata se si implementa il campo key
    Data& Element() noexcept; // Mutable access to the element (concrete function should not throw exceptions)
    const Data& Element() const noexcept; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual Node& LeftChild()  = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)

    virtual Node& LeftChild() const = 0; // Unmutable function
    virtual Node& RightChild() const = 0; // Unmutable function

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree<Data>& operator=(const BinaryTree<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree<Data>& operator=(BinaryTree<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree<Data>&) const noexcept; // Comparison of abstract binary tree is possible. /IL CONFRONTO TRA NODI DEVE CONFRONTARE ANCHE I FIGLI
  bool operator!=(const BinaryTree<Data>&) const noexcept; // Comparison of abstract binary tree is possible. /DI CONSEGUENZA BASTA CONFRONTARE LE DUE RADICI

  /* ************************************************************************ */

  // Specific member functions

  virtual Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

   using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  virtual void MapPreOrder(MapFunctor, void*) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const override; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  virtual void MapPostOrder(MapFunctor, void*) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const override; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

  virtual void MapInOrder(MapFunctor, void*) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

  virtual void FoldInOrder(FoldFunctor, const void*, void*) const override; // Override InOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  virtual void MapBreadth(MapFunctor, void*) override; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  virtual void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member



protected:

  // Auxiliary member functions (for PreOrderMappableContainer)

  virtual void MapPreOrder(MapFunctor, void*, Node&); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer)

  virtual void FoldPreOrder(FoldFunctor, const void*, void*, Node&) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderMappableContainer)

  virtual void MapPostOrder(MapFunctor, void*, Node&); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderFoldableContainer)

  virtual void FoldPostOrder(FoldFunctor, const void*, void*, Node&) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  virtual void MapInOrder(MapFunctor, void*, Node&); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  virtual void FoldInOrder(FoldFunctor, const void*, void*, Node&) const; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data>{

private:

  // ...

protected:

  // ... puntatore al nodo corrente (current)
  struct BinaryTree<Data>::Node* current = nullptr;

  struct BinaryTree<Data>::Node* root = nullptr;

  // StackLst<struct BinaryTree<Data>::Node*>* stack = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stack;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator<Data>&);

  // Move constructor                               
  BTPreOrderIterator(BTPreOrderIterator<Data>&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator<Data>& operator=(const BTPreOrderIterator<Data>&);

  // Move assignment
  BTPreOrderIterator<Data>& operator=(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator<Data>&)const noexcept;
  bool operator!=(const BTPreOrderIterator<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual Data& operator* ()const; // (throw std::out_of_range when terminated) accesso a element del nodo che sta puntando current

  virtual bool Terminated() const noexcept; // (should not throw exceptions) se il puntatore a current e' nullptr 

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator<Data>& operator++(); // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept; // (should not throw exceptions) ricordati di svuotare lo stack o la coda

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data>{

private:

  // ...

protected:

  
  struct BinaryTree<Data>::Node* current = nullptr;

  struct BinaryTree<Data>::Node* root = nullptr;

  // StackLst<struct BinaryTree<Data>::Node*>* stack = nullptr;
    StackLst<struct BinaryTree<Data>::Node*> stack;



  // Auxiliary Member Function

  virtual void Explore() noexcept;

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator<Data>&);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator<Data>&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator<Data>& operator=(const BTPostOrderIterator<Data>&);

  // Move assignment
  BTPostOrderIterator<Data>& operator=(BTPostOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator<Data>&)const noexcept;
  bool operator!=(const BTPostOrderIterator<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual Data& operator*() const; // (throw std::out_of_range when terminated) accesso a element del nodo che sta puntando current

  virtual bool Terminated() const noexcept; // (should not throw exceptions) se il puntatore a current e' nullptr 

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator<Data>& operator++(); // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept; // (should not throw exceptions) ricordati di svuotare lo stack o la coda



};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data>,
                         virtual public ResettableIterator<Data>{

private:

  // ...

protected:

  struct BinaryTree<Data>::Node* current = nullptr;

  struct BinaryTree<Data>::Node* root = nullptr;

  // StackLst<struct BinaryTree<Data>::Node*>* stack = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stack;


  // Auxiliary Member Function

  virtual void Explore() noexcept;

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator<Data>&);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator<Data>&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTInOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator<Data>& operator=(const BTInOrderIterator<Data>&);

  // Move assignment
  BTInOrderIterator<Data>& operator=(BTInOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator<Data>&)const noexcept;
  bool operator!=(const BTInOrderIterator<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual Data& operator*() const; // (throw std::out_of_range when terminated) accesso a element del nodo che sta puntando current

  virtual bool Terminated() const noexcept; // (should not throw exceptions) se il puntatore a current e' nullptr 

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator<Data>& operator++(); // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept; // (should not throw exceptions) ricordati di svuotare lo stack o la coda

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator: virtual public ForwardIterator<Data>,
                         virtual public ResettableIterator<Data>{

private:

  // ...

protected:

  struct BinaryTree<Data>::Node* current = nullptr;

  struct BinaryTree<Data>::Node* root = nullptr;

  // QueueLst<struct BinaryTree<Data>::Node*>* queue = nullptr;
  QueueLst<struct BinaryTree<Data>::Node*> queue{};


public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator<Data>&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator<Data>&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTBreadthIterator();

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator<Data>& operator=(const BTBreadthIterator<Data>&);

  // Move assignment
  BTBreadthIterator<Data>& operator=(BTBreadthIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator<Data>&)const noexcept;
  bool operator!=(const BTBreadthIterator<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual Data& operator*() const; // (throw std::out_of_range when terminated) accesso a element del nodo che sta puntando current

  virtual bool Terminated() const noexcept; // (should not throw exceptions) se il puntatore a current e' nullptr 

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator<Data>& operator++(); // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept; // (should not throw exceptions) ricordati di svuotare lo stack o la coda

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
