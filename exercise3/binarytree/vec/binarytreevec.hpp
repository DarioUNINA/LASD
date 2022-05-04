
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data>{


private:

  // ...

protected:


  /* ************************************************************************ */
  /* ************************************************************************ */

  struct NodeVec : virtual public BinaryTree<Data>::Node{

  private:

    // ...

  protected:

    ulong index;

    using BinaryTree<Data>::Node:: key;

    Vector<NodeVec*>* vector = nullptr;

  public:

    // Constructors
    NodeVec(Vector<NodeVec*>* vector, const ulong position, const Data& data) { this->vector = vector;  key = data; index = position; };

    // NodeVec(const NodeVec&);


    // Destructor
    virtual ~NodeVec() ;


    /* ************************************************************************** */

    // Copy Assignment
    NodeVec& operator=(const NodeVec&) = delete;

    // Move Assignment
    NodeVec& operator=(NodeVec&&) noexcept = delete;

  /* ************************************************************************** */

    // Specific Member Functions

    virtual bool IsLeaf() const noexcept; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept; // (concrete function should not throw exceptions)

    virtual struct BinaryTree<Data>::Node& LeftChild() override; // (concrete function must throw std::out_of_range when not existent)
    virtual struct BinaryTree<Data>::Node& RightChild() override; // (concrete function must throw std::out_of_range when not existent)

    virtual struct BinaryTree<Data>::Node& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
    virtual struct BinaryTree<Data>::Node& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */
  /* ************************************************************************ */

  using BinaryTree<Data>::size;

  Vector<NodeVec*>* vector = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();


  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  BinaryTreeVec<Data>& operator=(BinaryTreeVec<Data>&&)noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual struct BinaryTree<Data>::Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void MapBreadth(MapFunctor, void*) override; // Override BreadthMappableContainer member


  // Specific member functions (inherited from BreadthFoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member
  
};


}

#include "binarytreevec.cpp"

#endif
