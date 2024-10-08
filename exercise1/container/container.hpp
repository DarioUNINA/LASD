#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  class Container
  {

  private:
    // ...

  protected:
    ulong size = 0;

  public:
    // Destructor
    virtual ~Container() = default;

    /* ************************************************************************ */

    // Copy assignment
    Container& operator=(const Container &) = delete;

    // Move assignment
    Container& operator=(Container &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Container &) const noexcept = delete;
    bool operator!=(const Container &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual bool Empty() const noexcept
    {
       return (size == 0);
    }

    virtual ulong Size() const noexcept
    {
      return size;
    }

    virtual void Clear() = 0;
  };

  /* ************************************************************************** */

  template <typename Data>
  class LinearContainer : virtual public Container
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~LinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    LinearContainer & operator = (const LinearContainer &) = delete;

    // Move assignment
    LinearContainer & operator = (LinearContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const LinearContainer &) const noexcept;
    bool operator!=(const LinearContainer &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    virtual Data& Front() const;
    virtual Data& Back() const;

    virtual Data& operator[](ulong) const = 0;
  };

  /* ************************************************************************** */

  template <typename Data>
  class TestableContainer : public virtual Container
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~TestableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    TestableContainer& operator = (const TestableContainer &) = delete;

    // Move assignment
    TestableContainer& operator = (TestableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(TestableContainer &) const noexcept = delete;
    bool operator!=(TestableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions
    virtual bool Exists(const Data &) const noexcept = 0;
  };

  /* ************************************************************************** */

  template <typename Data>
  class MappableContainer : public virtual Container{

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~MappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    MappableContainer &operator=(const MappableContainer &) = delete;

    // Move assignment
    MappableContainer &operator=(MappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(MappableContainer &) const noexcept = delete;
    bool operator!=(MappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    typedef std::function<void(Data &, void *)> MapFunctor;

    virtual void Map(MapFunctor, void *) = 0;
  };

  /* ************************************************************************** */

  template <typename Data>
  class FoldableContainer : public virtual TestableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~FoldableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    FoldableContainer &operator=(const FoldableContainer &) = delete;

    // Move assignment
    FoldableContainer &operator=(FoldableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(FoldableContainer &) const noexcept = delete;
    bool operator!=(FoldableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    typedef std::function<void(const Data &, const void *, void *)> FoldFunctor;

    virtual void Fold(FoldFunctor, const void *, void *) const = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from TestableContainer)

    virtual bool Exists(const Data &) const noexcept override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderMappableContainer : public virtual MappableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PreOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;

    // Move assignment
    PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PreOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PreOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPreOrder(MapFunctor, void *) = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void *) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderFoldableContainer : public virtual FoldableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PreOrderFoldableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PreOrderFoldableContainer &operator=(const PreOrderFoldableContainer &) = delete;

    // Move assignment
    PreOrderFoldableContainer &operator=(PreOrderFoldableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PreOrderFoldableContainer &) const noexcept = delete;
    bool operator!=(const PreOrderFoldableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename FoldableContainer<Data>::FoldFunctor;

    virtual void FoldPreOrder(FoldFunctor, const void*, void*) const = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void *, void *) const override;
  };

  /* ************************************************************************** */

    template <typename Data>
  class PostOrderMappableContainer : public virtual MappableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PostOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

    // Move assignment
    PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PostOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPostOrder(MapFunctor, void *) = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void *) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderFoldableContainer : public virtual FoldableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PostOrderFoldableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PostOrderFoldableContainer &operator=(const PostOrderFoldableContainer &) = delete;

    // Move assignment
    PostOrderFoldableContainer &operator=(PostOrderFoldableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PostOrderFoldableContainer &) const noexcept = delete;
    bool operator!=(const PostOrderFoldableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename FoldableContainer<Data>::FoldFunctor;

    virtual void FoldPostOrder(FoldFunctor, const void *, void *) const = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void*, void*) const override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class InOrderMappableContainer
  { // Must extend MappableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~InOrderMappableContainer() specifiers

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

    // using typename MappableContainer<Data>::MapFunctor;

    // type MapInOrder(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    // type Map(argument) specifiers; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class InOrderFoldableContainer
  { // Must extend FoldableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~InOrderFoldableContainer() specifiers

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

    // using typename FoldableContainer<Data>::FoldFunctor;

    // type FoldInOrder(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    // type Fold(argument) specifiers; // Override FoldableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthMappableContainer
  { // Must extend MappableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~BreadthMappableContainer() specifiers

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

    // using typename MappableContainer<Data>::MapFunctor;

    // type MapBreadth(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    // type Map(argument) specifiers; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthFoldableContainer
  { // Must extend FoldableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    // ~BreadthFoldableContainer() specifiers

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

    // using typename FoldableContainer<Data>::FoldFunctor;

    // type FoldBreadth(arguments) specifiers;

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    // type Fold(argument) specifiers; // Override FoldableContainer member
  };

  /* ************************************************************************** */

}

#include "container.cpp"

#endif
