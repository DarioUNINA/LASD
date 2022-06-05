
namespace lasd {

/* ************************************************************************** */

// Constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong& newSize){
    if(newSize>0){
        dim = newSize;
        elements.Resize(newSize);
    }

}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& container){
    DictionaryContainer<Data>::Insert(container);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong& newSize, const LinearContainer<Data>& container):HashTableClsAdr(newSize){
    DictionaryContainer<Data>::Insert(container);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& table): HashTable<Data>::HashTable(table){
    elements = table.elements;
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& table): HashTable<Data>::HashTable(std::move(table)){
    std::swap(elements, table.elements);
}


/* ************************************************************************** */

// Copy and Move Assignment

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>:: operator=(const HashTableClsAdr<Data>& table){
    HashTableClsAdr* temp = new HashTableClsAdr(table);
    std::swap(*this, *temp);

    delete temp;
    return *this;
}


template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>:: operator=(HashTableClsAdr<Data>&& table){
    HashTable<Data>::operator=(std::move(table));

    std::swap(elements, table.elements);
    return *this;
}


/* ************************************************************************** */

// Comparison Operators

template <typename Data>
void ExistsFunc(const Data& data, const void* table, void* result) noexcept{
    if(!((static_cast<const HashTableClsAdr<Data>*>(table))->Exists(data)))
        *(static_cast<bool*>(result)) = false;
}


template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& table) const noexcept{
    bool result = true;

    FoldEx(ExistsFunc<Data>, &table, &result);

    if(result)
        table.FoldEx(ExistsFunc<Data>, this, &result);

    return result;
}


template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& table) const noexcept{
    return !(*this == table);
}


/* ************************************************************************** */

// Specific member functions (inherited from HashTable)

template <typename Data>
void MapInsert(const Data& data, void* table){
    (static_cast<HashTableClsAdr<Data>*>(table))->Insert(data);
}


template <typename Data>
void HashTableClsAdr<Data>::Resize(const ulong& newSize){
    HashTableClsAdr<Data>* temp = new HashTableClsAdr(newSize);

    Map(MapInsert<Data>, temp);

    std::swap(*this, *temp);
    delete temp;
}


/* ************************************************************************ */

// Specific member functions (inherited from DictionaryContainer)

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    if((elements[HashTable<Data>::HashKey(data)]).Insert(data)){
        size++;
        return true;
    }else
        return false;

}


template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data){
    if((elements[HashTable<Data>::HashKey(data)]).Insert(std::move(data))){
        size++;
        return true;
    }else
        return false;
}


template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    if((elements[HashTable<Data>::HashKey(data)]).Remove(data)){
        size--;
        return true;
    }else
        return false;
}


/* ************************************************************************** */

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept{
    return (elements[HashTable<Data>::HashKey(data)]).Exists(data);
}


/* ************************************************************************** */

// Specific member functions (inherited from FoldableContainer and MappableContainer)


template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor function, const void* data, void* value) const{
    for(ulong i=0; i<dim; ++i)
        (elements[i]).Fold(function, data, value);
}


template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor function, void* value){
    for(ulong i=0; i<dim; ++i)
        elements[i].Map(function, value);
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
void HashTableClsAdr<Data>::FoldEx(FoldFunctor function, const void* table, void* result) const{
    ulong i=-1;

    while(++i<dim && *(static_cast<bool*>(result)))
        elements[i].Fold(function, table, result);
}



}
