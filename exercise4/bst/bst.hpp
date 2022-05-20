
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk;


template <typename Data>
class BST : virtual public BinaryTreeLnk<Data>, 
            virtual public DictionaryContainer<Data>{

private:

  // ...

protected:

  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;

  using typename BinaryTreeLnk<Data>::NodeLnk;

  // ...

public:

  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST<Data>& tree): BinaryTreeLnk<Data>(tree) {};

  // Move constructor
  BST(BST<Data>&& tree) noexcept: BinaryTreeLnk<Data>(std::move(tree)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST<Data>& operator=(const BST<Data>&);

  // Move assignment
  BST<Data>& operator=(BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST<Data>&) const noexcept; //usa gli iteratori in order (prima controlla la size)
  bool operator!=(const BST<Data>&) const noexcept; //usa gli iteratori in order (prima controlla la size)

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Min() const; // (concrete function must throw std::length_error when empty) // torna il riferimento al nodo
                                                                                                  // deve tornare un riferimento costante
                                                                                                  //Da controllare che il test lo permetta(dovrebbe)
                                                                                                  //se non lo permette, doppia impelementazione
  virtual Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  virtual void RemoveMin(); // (concrete function must throw std::length_error when empty)

  virtual const Data& Max() const; // (concrete function must throw std::length_error when empty)
  virtual Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  virtual void RemoveMax(); // (concrete function must throw std::length_error when empty)

  virtual const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when not found)
  virtual Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  virtual void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when not found)

  virtual const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when not found)
  virtual Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  virtual void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual void Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  virtual void Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  virtual void Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  void Print(NodeLnk* node){
    std::cout<<node->key<<"\n";
    if(node->HasLeftChild())
      Print(node->leftChild);
    if(node->HasRightChild())
      Print(node->rightChild);
  }

protected:

  // Auxiliary member functions

  virtual Data DataNDelete(NodeLnk*&) noexcept;

  virtual NodeLnk* Detach(NodeLnk*&) noexcept; //stacca il nodo senza distrggerlo

  virtual NodeLnk* DetachMin(NodeLnk*&) noexcept;
  virtual NodeLnk* DetachMax(NodeLnk*&) noexcept;

  virtual NodeLnk* Skip2Left(NodeLnk*&) noexcept;
  virtual NodeLnk* Skip2Right(NodeLnk*&) noexcept;

 virtual NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
 virtual NodeLnk* const& FindPointerToMin(NodeLnk* const&) const noexcept;

 virtual NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
 virtual NodeLnk* const& FindPointerToMax(NodeLnk* const&) const noexcept;

 virtual NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
 virtual NodeLnk* const& FindPointerTo(NodeLnk* const&, const Data&) const noexcept;

 virtual NodeLnk** FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept;
 virtual NodeLnk* const* FindPointerToPredecessor(NodeLnk* const&, const Data&) const noexcept;

 virtual NodeLnk** FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept;
 virtual NodeLnk* const* FindPointerToSuccessor(NodeLnk* const&, const Data&) const noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
