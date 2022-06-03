
namespace lasd {

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
    std::swap(ts, table.ts);
    std::swap(a, table.a);
    std::swap(b, table.b);

    return *this;
}


/* ************************************************************************** */

// Comparison Operators

template <typename Data>
void ExistsFunct(const Data& data, const void* table, void* result) noexcept{
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
            FoldEx(ExistsFunct<Data>, &table, &result);

            if(result)
                table.FoldEx(ExistsFunct<Data>, this, &result);

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
void MapIns(const Data& data, void* table){
    (static_cast<HashTableOpnAdr<Data>*>(table))->Insert(data);
}


template <typename Data>
ulong HashTableOpnAdr<Data>:: FindSize(const ulong& newSize) const noexcept{
    ushort i=7;

    while(std::pow(2,i) < newSize || std::pow(2,i) < size*2)
        ++i;
    
    return std::pow(2,i);
}


template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong& newSize){
    ulong nSize = FindSize(newSize);

    HashTableOpnAdr<Data>* temp = new HashTableOpnAdr(nSize);

    Map(MapIns<Data>, temp);

    std::swap(*this, *temp);

    delete temp;
}


/* ************************************************************************ */

// Specific member functions (inherited from DictionaryContainer)

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data){
    if((size+ts) > dim/2)
        Resize(dim+1);

    if(ts > size/2)
        Resize(dim);

    ulong i = 0;

    ulong index = FindEmpty(data, i);

    if(index == dim)
        return false;

    ulong position = HashKey(data, index);

    elements[position] = data;
    ++size;    

    if(flag[position] == 0){
        flag[position] = 1;
        return true;

    }else{
        flag[position] = 1;
        return !Remove(data, ++index);
    }
}


template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data){
    if((size+ts) > dim/2)
        Resize(dim+1);

    if(ts > size/2)
        Resize(dim);

    ulong index = 0;

    index = FindEmpty(data, index);

    if(index == dim)
        return false;

    ulong position = HashKey(data, index);

    elements[position] = std::move(data);
    ++size;    

    if(flag[position] == 0){
        flag[position] = 1;
        return true;

    }else{
        flag[position] = 1;
        return !Remove(data, ++index);
    }
}


template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data){
    ulong i=0;
    return Remove(data, i);
}


/* ************************************************************************** */

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept{
    ulong i = 0;
    ulong index = Find(data, i);

    return (index!=dim);
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


/* ************************************************************************ */

// Auxiliary Member Function

template <typename Data>
ulong HashTableOpnAdr<Data>::Find(const Data& data, ulong& i) const noexcept{
    ulong curr;
    while(i<(size+ts)){
        curr = HashKey(data, i);

        if(elements[curr] == data && flag[curr] == 1)
            return curr;

        ++i;
    }
    
    return dim;
}


template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const Data& data, ulong& i) const noexcept{
    ulong curr;

    do{
        curr = HashKey(data, i);
        ++i;

        if(elements[curr] == data && flag[curr]==1)
            return dim;

    }while(flag[curr] == 1);

    return --i;
}


template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data, ulong& i){
    ulong position = Find(data, i);
    bool result;

    if(position == dim)
        result = false;
    else{
        flag[position] = 2;
        size--;
        ts++;

        result = true;
    }

    if((size+ts) < dim/8 && dim >= std::pow(2,8))
        Resize(dim/2);

    return result;
}


template <typename Data>
ulong HashTableOpnAdr<Data>::HashKey(const Data& data, const ulong& i) const noexcept{
    return ((HashTable<Data>::HashKey(data))+ i*(HashKey(data, a, b)))%dim;
}


template <typename Data>
ulong HashTableOpnAdr<Data>::HashKey(const Data& data, const ulong& x, const ulong& y) const noexcept {
    ulong result = ((x*(hash(data))+y)%p)%dim;

    if(result%2 == 0)
        return --result;
    else
        return result;
}


}
