
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../bst/bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST;


template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{

private:

  // ...

protected:

  using BinaryTree<Data>::size;


  struct NodeLnk : virtual public BinaryTree<Data>::Node{



  private:

    // ...

  protected:

    using BinaryTree<Data>::Node:: key;

    NodeLnk* leftChild = nullptr;
    NodeLnk* rightChild = nullptr;

  public:

      friend class BST<Data>;


    // Constructor

    NodeLnk(const Data& data, NodeLnk* lnode, NodeLnk* rnode) { key = data; leftChild = lnode; rightChild = rnode; };

    NodeLnk(Data&& data) { std::swap(key, data); };
   
    // Destrcutor

    virtual ~NodeLnk();

  /* ************************************************************************** */

    // Copy Assignment

    NodeLnk& operator=(const NodeLnk&) = delete;

    // Move Assignment
    NodeLnk& operator=(NodeLnk&&) noexcept = delete;

  /* ************************************************************************** */

    // Specific Member Functions

    virtual bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept;
    virtual bool HasRightChild() const noexcept;

    virtual NodeLnk& LeftChild() override;
    virtual NodeLnk& RightChild() override;

    virtual NodeLnk& LeftChild() const override;
    virtual NodeLnk& RightChild() const override;

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
  BinaryTreeLnk(const LinearContainer<Data>&);

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

  virtual NodeLnk& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
