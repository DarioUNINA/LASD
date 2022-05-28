
namespace lasd {

/* ************************************************************************** */

// Constructors

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong& newSize){
    dim = newSize;
    elements.Resize(newSize);
    flag.Resize(newSize);
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data>& container){
    DictionaryContainer<Data>::Insert(container);
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong& newSize, const LinearContainer<Data>& container):HashTableOpnAdr(newSize){
    DictionaryContainer<Data>::Insert(container);
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& table): HashTable<Data>::HashTable(table){
    elements = table.elements;
    flag = table.flag;
    deleted = table.deleted;
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& table): HashTable<Data>::HashTable(std::move(table)){
    std::swap(elements, table.elements);
    std::swap(flag, table.flag);
    std::swap(deleted, table.deleted);
}


/* ************************************************************************** */

// Copy and Move Assignment

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>:: operator=(const HashTableOpnAdr<Data>& table){
    HashTableOpnAdr* temp = new HashTableOpnAdr(table);
    std::swap(*this, *temp);

    delete temp;
    return *this;
}


template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>:: operator=(HashTableOpnAdr<Data>&& table){
    HashTable<Data>::operator=(std::move(table));

    std::swap(elements, table.elements);
    std::swap(flag, table.flag);
    std::swap(deleted, table.deleted);
    return *this;
}


/* ************************************************************************** */

// Comparison Operators

template <typename Data>
void ExistsFunc(const Data& data, const void* table, void* result) noexcept{
    if(!((static_cast<const HashTableOpnAdr<Data>*>(table))->Exists(data)))
        *(static_cast<bool*>(result)) = false;
}


template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& table) const noexcept{
    if(size == table.size)
        if(size == 0)
            return true;
        else{
            bool result = true;
            FoldEx(ExistsFunc<Data>, &table, &result);

            if(result)
                table.FoldEx(ExistsFunc<Data>, this, &result);

            return result;
        }
    else
        return false;

}


template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& table) const noexcept{
    return !(*this == table);
}


/* ************************************************************************** */

// Specific member functions (inherited from HashTable)

template <typename Data>
void MapInsert(const Data& data, void* table){
    (static_cast<HashTableOpnAdr<Data>*>(table))->Insert(data);
}


ulong FindSize(const ulong& size) noexcept{
    ulong i=7;
    ulong curr;

    while(curr = std::pow(2,i) <size)
        ++i;
    
    return curr;
}


template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong& newSize){
    newSize = FindSize(newSize);

    HashTableOpnAdr<Data>* temp = new HashTableOpnAdr(newSize);

    Map(MapInsert<Data>, temp);

    std::swap(*this, *temp);
    delete temp;
}


/* ************************************************************************ */

// Specific member functions (inherited from DictionaryContainer)

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data){
    ulong index = FindEmpty(data);

    if(flag[index]==1)
        return false;
    else{
        elements[index] = data;
        flag[index] = 1;
        size++;
        return true;
    }
}


template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data){
    ulong index = Find(data);

    if(flag[index] == 1)
        return false;
    else{
        elements[index] = std::move(data);
        flag[index] = 1;
        size++;
        return true;
    }
}


template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data){

}


/* ************************************************************************** */

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept{
    ulong i=0;

    for(ulong curr = HashKey(data, i); curr < dim; ++i)
        if(elements[curr] = data)
            if(flag[curr] == 1)
                return true;
            else
                return false;

    return false;
}


/* ************************************************************************** */

// Specific member functions (inherited from FoldableContainer and MappableContainer)


template <typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor function, const void* data, void* value) const{
    for(ulong i = 0; i<dim; ++i)
        if(flag[i]==1)
            function(elements[i], data, value);
}


template <typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor function, void* value){
    for(ulong i = 0; i<dim; ++i)
        if(flag[i]==1)
            function(elements[i], value);
}


template <typename Data>
void HashTableOpnAdr<Data>::FoldEx(FoldFunctor function, const void* table, void* result) const{
    ulong i=-1;

    while(++i<dim && *(static_cast<bool*>(result)))
        if(flag[i]==1)
            function(elements[i], table, result);
}


/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
void HashTableOpnAdr<Data>:: Clear(){
    HashTableOpnAdr<Data>* temp = new HashTableOpnAdr<Data>();

    std::swap(*this, *temp);
    delete temp;
}



}
