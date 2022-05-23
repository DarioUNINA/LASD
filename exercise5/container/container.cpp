
namespace lasd {

/* ************************************************************************** */

// Comparison operators (LinearContainer)

template <typename Data>
bool LinearContainer<Data>:: operator==(const LinearContainer<Data>& container) const noexcept{

    if(size != container.size)
        return false;
    else
        for(ulong i=0; i<size ; ++i)
            if(operator[](i) != container[i])
                return false;

    return true;
    }


template <typename Data>
bool LinearContainer<Data>:: operator!=(const LinearContainer<Data>& container) const noexcept{
    return !(*this == container);
}


// Specific member functions (LinearContainer)

template <typename Data>
Data& LinearContainer<Data>:: Front() const{

    if(size == 0)
        throw std::length_error("Empty Linear Container");
    else
        return operator[](0);
}

template <typename Data>
Data& LinearContainer<Data>:: Back() const{

    if(size == 0)
        throw std::length_error("Empty Linear Container");
    else
        return operator[](size-1);
}


// Quick Sort functions

template <typename Data>
ulong  LinearContainer<Data>::Partition(ulong first, ulong last) const noexcept{

  Data& x = operator[](first);
  ulong i = first-1;
  ulong j = last+1;

  do {
    do
      j--;
    while (x < operator[](j));

    do
      i++;
    while (x > operator[](i));

    if (i < j)
      std::swap(operator[](i), operator[](j));
      
  } while (i < j);

  return j;
}


template <typename Data>
void LinearContainer<Data>::Sort() const noexcept{
  if(size>1)
    QuickSort(0, size-1);
}


template <typename Data>
void LinearContainer<Data>::QuickSort(ulong first, ulong last) const noexcept{
  if (first < last) {
    ulong pivot = Partition(first, last);

    QuickSort(first, pivot);
    QuickSort(pivot + 1, last);
  }
}



/* ************************************************************************** */
/* ************************************************************************** */

// Specific memeber Functions (DictionaryContainer)

template <typename Data>
void DictionaryContainer<Data>::Insert(const LinearContainer<Data>& container){
    for(ulong i=0; i<container.Size(); ++i)
        Insert(container[i]);
}


template <typename Data>
void DictionaryContainer<Data>::Insert(LinearContainer<Data>&& container){
    for(ulong i=0; i<container.Size(); ++i)
        Insert(std::move(container[i]));
}


template <typename Data>
void DictionaryContainer<Data>::Remove(const LinearContainer<Data>& container){
    for(ulong i=0; i<container.Size(); ++i)
        Remove(container[i]);
}


/* ************************************************************************** */
/* ************************************************************************** */


// Specific member functions (FoldableContainer)

template <typename Data>
void FoldExists(const Data& data1, const void* data2, void* exists) noexcept{
     if (data1 == *(static_cast<const Data*>(data2)))
        *(static_cast<bool*>(exists)) = true;
}


template <typename Data>
bool FoldableContainer<Data>:: Exists(const Data& data) const noexcept{

    bool exists = false;
    Fold(FoldExists<Data>, &data, &exists);
    return exists;
}

/* ************************************************************************** */

// Specific member functions (PreOrderMappableContainer)

template <typename Data>
void PreOrderMappableContainer<Data>:: Map(MapFunctor function, void* value){
    MapPreOrder(function, value);
}


/* ************************************************************************** */

// Specific member functions (PreOrderFoldableContainer)

template <typename Data>
void PreOrderFoldableContainer<Data>:: Fold(FoldFunctor function, const void* data, void* value) const{
    FoldPreOrder(function, data, value);
}

/* ************************************************************************** */

// Specific member functions (PostOrderMappableContainer)

template <typename Data>
void PostOrderMappableContainer<Data>:: Map(MapFunctor function, void* value){
    MapPostOrder(function, value);
}

/* ************************************************************************** */

// Specific member functions (PostOrderFoldableContainer)

template <typename Data>
void PostOrderFoldableContainer<Data>:: Fold(FoldFunctor function, const void* data, void* value) const{
    FoldPostOrder(function, data, value);
}

/* ************************************************************************** */

// Specific member functions (InOrderFoldableContainer)

template <typename Data>
void InOrderFoldableContainer<Data>:: Fold(FoldFunctor function, const void* data, void* value) const{
    FoldInOrder(function, data, value);
}
/* ************************************************************************** */

// Specific member functions (BreadthOrderFoldableContainer)

template <typename Data>
void BreadthFoldableContainer<Data>:: Fold(FoldFunctor function, const void* data, void* value) const{
    FoldBreadth(function, data, value);
}

/* ************************************************************************** */

// Specific member functions (InOrderMappableContainer)

template <typename Data>
void InOrderMappableContainer<Data>:: Map(MapFunctor function, void* value){
    MapInOrder(function, value);
}

/* ************************************************************************** */

// Specific member functions (BreadthOrderMappableContainer)

template <typename Data>
void BreadthMappableContainer<Data>:: Map(MapFunctor function, void* value){
    MapBreadth(function, value);
}

}