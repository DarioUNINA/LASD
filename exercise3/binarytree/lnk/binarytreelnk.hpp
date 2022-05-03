
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{

private:

  // ...

protected:

  using BinaryTree<Data>::size;


  struct NodeLnk : virtual public BinaryTree<Data>::Node{ // Must extend Node

  private:

    // ...

  protected:


    using BinaryTree<Data>::Node:: key;

    NodeLnk* leftChild = nullptr;
    NodeLnk* rightChild = nullptr;

  public:

    // Constructor

    NodeLnk(const Data& data, NodeLnk* lnode, NodeLnk* rnode) { key = data; leftChild = lnode; rightChild = rnode; };

    // Destrcutor

    virtual ~NodeLnk();

  /* ************************************************************************** */

    // Copy Assignment

    NodeLnk& operator=(const NodeLnk&) = delete;

    // Move Assignment
    NodeLnk& operator=(NodeLnk&&) noexcept = delete;

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


  NodeLnk* root = nullptr;

  // Auxiliary member function

  NodeLnk* BuildTree(const LinearContainer<Data>&, const ulong) const;

  NodeLnk* CopyTree(const struct BinaryTree<Data>::Node&) const;



public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer (in ampiezza)

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk<Data>&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk<Data>& operator=(const BinaryTreeLnk<Data>&);

  // Move assignment
  BinaryTreeLnk<Data>& operator=(BinaryTreeLnk<Data>&&)noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual struct BinaryTree<Data>::Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
