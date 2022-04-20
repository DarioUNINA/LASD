
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List  :  public virtual LinearContainer<Data>,
               public virtual PreOrderMappableContainer<Data>, 
               public virtual PreOrderFoldableContainer<Data>,
               public virtual PostOrderMappableContainer<Data>,
               public virtual PostOrderFoldableContainer<Data>{

private:

  // ...

protected:

  using LinearContainer<Data>:: size;


  struct Node {

    Node* next = nullptr;

    Data key;

    /* ********************************************************************** */

    // Specific constructors
      Node() = default;

      Node(const Data&);

      Node(Data&&) noexcept;

    /* ********************************************************************** */

    // Copy constructor
      Node(const Node&);

    // Move constructor
      Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() noexcept;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

  };

  Node* head = nullptr;
  Node* tail = nullptr;


public:

  // Default constructor
   List() = default;

  /* ************************************************************************ */

  // Specific constructor
   List(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  List(const List<Data>&);

  // Move constructor
  List(List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  List<Data>& operator=(const List<Data>&);

  // Move assignment
  List<Data>& operator=(List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List<Data>&) const noexcept;
  bool operator!=(const List<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual void InsertAtFront(const Data&);
  virtual void InsertAtFront(Data&&);
  virtual void RemoveFromFront();
  virtual Data FrontNRemove();

  virtual void InsertAtBack(const Data&);
  virtual void InsertAtBack(Data&&);

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override;
  Data& Back() const override;

  Data& operator[](const ulong) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor, void*) override; 

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  virtual void MapPreOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  virtual void MapPostOrder(MapFunctor, void*) override;

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


protected:

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  virtual void MapPreOrder(MapFunctor, void*, Node*);
  virtual void MapPostOrder(MapFunctor, void*, Node*);

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  virtual void FoldPreOrder(FoldFunctor, const void*, void*, const Node*) const;
  virtual void FoldPostOrder(FoldFunctor, const void*, void*, const Node*) const;
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
