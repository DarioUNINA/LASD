
namespace lasd {

/* ************************************************************************** */

// Constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong& newSize){
    size = newSize;
    elements = Vector(newSize);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& container){
    for(ulong i=0; i<container.Size(); ++i)
        Insert(container[i]);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& container, const ulong& newSize):HashTableClsAdr(newSize){
    HashTableClsAdr<Data>::HashTableClsAdr(container);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr& table){
    HashTable<Data>::HashTable(table);
    
    elements = table.elements;
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr&& table){
    HashTable(std::move(table));

    std::swap(elements, table.elements);
}


/* ************************************************************************** */

// Copy and Move Assignment

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>:: operator=(const HashTableClsAdr<Data>& table){
    HashTableClsAdr* temp = new HashTableClsAdr(table);
    std::swap(*this, *temp);

    delete temp;
    return this;
}


template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>:: operator=(HashTableClsAdr<Data>&& table){
    HashTable<Data>::operator=(std::move(table));

    std::swap(elements, table.elements);
}


/* ************************************************************************** */

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& table) const noexcept{

}




}
