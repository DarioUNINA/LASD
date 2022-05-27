
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

// Comparison Operators

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& table) const noexcept{
    bool result = true;

    FoldEx(ExistsFunc<Data>, table, result);

    if(result)
        table.FoldEx(ExistsFunc<Data>, *this, result);

    return result;
}


template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& table) const noexcept{
    return !(*this == table);
}


/* ************************************************************************** */

// Specific member functions (inherited from DictionaryContainer)

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    if((elements[HashTable::HashKey(data)]).Insert(data)){
        size++;
        return true;
    }else
        return false;

}


template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data){
    if((elements[HashTable::HashKey(data)]).Insert(std::move(data))){
        size++;
        return true;
    }else
        return false;}


template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    if((elements[HashTable::HashKey(data)]).Remove(data)){
        size--;
        return true;
    }else
        return false
}


/* ************************************************************************** */

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept{
    return elements[HashTable::HashKey(data)].Exists(data);
}


/* ************************************************************************** */

// Specific member functions (inherited from FoldableContainer and MappableContainer)


template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor function, const void* data, void* value) const{
    for(ulong i=0; i<dim; ++i)
        elments[i].Fold(function, data, value);
}


template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor function, void* value){
    for(ulong i=0; i<dim; ++i)
        elments[i].Map(function, value);
}


/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
void HashTableClsAdr<Data>:: Clear(){
    HashTableClsAdr<Data>* temp = new HashTableClsAdr<Data>();

    std::swap(*this, *temp);
    delete temp;
}


/* ************************************************************************** */

// Auxiliary member functions

template <typename Data>
void HashTableClsAdr<Data>::ExistsFunc(const Data& data, const void* table, void* result) const noexcept{
    if(!(*(<static_cast(const HashTableClsAdr<BST<Data>>*)(table)).Exists(data)))
        *<static_cast(bool*)(result) = false;
}


template <typename Data>
void HashTableClsAdr<Data>::FoldEx(FoldFunctor function, const void* data, void* result) const{
    ulong i=-1;

    while(++i<dim && *(<static_cast(bool*)>(result)))
        elments[i].Fold(function, data, result);
}



}
