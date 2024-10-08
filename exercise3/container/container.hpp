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
       return (Size() == 0);
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
  class MappableContainer : public virtual Container
  {

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
  class InOrderFoldableContainer : public virtual FoldableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~InOrderFoldableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    InOrderFoldableContainer &operator=(const InOrderFoldableContainer &) = delete;

    // Move assignment
    InOrderFoldableContainer &operator=(InOrderFoldableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const InOrderFoldableContainer &) const noexcept = delete;
    bool operator!=(const InOrderFoldableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename FoldableContainer<Data>::FoldFunctor;

    virtual void FoldInOrder(FoldFunctor, const void *, void *) const = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void*, void*) const override;
  };

  /* ************************************************************************** */

template <typename Data>
  class InOrderMappableContainer : public virtual MappableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~InOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    InOrderMappableContainer &operator=(const InOrderMappableContainer &) = delete;

    // Move assignment
    InOrderMappableContainer &operator=(InOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const InOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const InOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapInOrder(MapFunctor, void *) = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void *) override;
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthMappableContainer : public virtual MappableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~BreadthMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    BreadthMappableContainer &operator=(const BreadthMappableContainer &) = delete;

    // Move assignment
    BreadthMappableContainer &operator=(BreadthMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BreadthMappableContainer &) const noexcept = delete;
    bool operator!=(const BreadthMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapBreadth(MapFunctor, void *) = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void *) override;
  };

  /* ************************************************************************** */

   template <typename Data>
  class BreadthFoldableContainer : public virtual FoldableContainer<Data>
  {

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~BreadthFoldableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    BreadthFoldableContainer &operator=(const BreadthFoldableContainer &) = delete;

    // Move assignment
    BreadthFoldableContainer &operator=(BreadthFoldableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BreadthFoldableContainer &) const noexcept = delete;
    bool operator!=(const BreadthFoldableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    using typename FoldableContainer<Data>::FoldFunctor;

    virtual void FoldBreadth(FoldFunctor, const void*, void *) const = 0;

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void*, void*) const override;
  };

  /* ************************************************************************** */

}

#include "container.cpp"

#endif