
namespace lasd {

/* ************************************************************************** */

//Specific constructors

template <typename Data>
Vector<Data>:: Vector(const ulong newSize){

    size = newSize;
    Elements = new Data[newSize];
}

template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& container){

    size = container.Size();
    Elements = new Data[size];

    for(ulong i = 0; i<size; ++i)
        Elements[i] = container[i];
}


//Copy constructor

template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vector){

    size = vector.size;
    Elements = new Data[size];

    std::copy(vector.Elements, (vector.Elements + vector.size) , Elements);
}


//Move constructor


template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vector) noexcept{

    std::swap(Elements, vector.Elements);
    std::swap(size, vector.size);
}


//Destructor

template<typename Data>
Vector<Data>:: ~Vector() noexcept{
    delete[] Elements;
    Elements = nullptr;
}


/* ************************************************************************** */

//Copy assignment

template<typename Data>
Vector<Data>& Vector<Data>:: operator=(const Vector<Data>& vector){
    Vector<Data>* temp = new Vector<Data>(vector);

    std::swap(*temp, *this);
    delete temp;
    return *this;
}


//Move assignment


template<typename Data>
Vector<Data>& Vector<Data>:: operator=(Vector<Data>&& vector) noexcept{

    std::swap(Elements, vector.Elements);
    std::swap(size, vector.size);

    return *this;
}



//Comparison operator

template<typename Data>
bool Vector<Data>:: operator==(const Vector<Data>& vector) const noexcept{

    if(size != vector.size)
        return false;
    else
        for(ulong i=0; i<size; i++)
            if(operator[](i) != vector[i])
                return false;
    return true;
}


template<typename Data>
bool Vector<Data>:: operator!=(const Vector<Data>& vector) const noexcept{
    return !(*this == vector);
}

/* ************************************************************************ */

  // Specific member functions

template<typename Data>
void Vector<Data>:: Resize(const ulong newSize){

    if(newSize == 0)
       Clear();
    else
        if(size!= newSize){
               
            Data* newElements = new Data[newSize];
            ulong limit = newSize;

            if(size < newSize)
                limit = size;
            
            for(ulong i=0; i<limit; ++i)
                std::swap(newElements[i], Elements[i]);
                
            std::swap(newElements, Elements);

            delete[] newElements;
            size = newSize;
        }
}


template<typename Data>
void Vector<Data>::Clear(){
    size = 0;
    delete[] Elements;
    Elements = nullptr;
}

template<typename Data>
Data& Vector<Data>:: Front() const{

    if(size == 0)
        throw std::length_error("Vector is Empty");
    else
        return Elements[0];
}

template<typename Data>
Data& Vector<Data>:: Back() const{

    if(size == 0)
        throw std::length_error("Vector is Empty");
    else
        return Elements[size-1];
}


template<typename Data>
Data& Vector<Data>::operator[](const ulong index) const{
    
    if(index>=size)
        throw std::out_of_range("Index out of bounds. Vector size: " + std::to_string(size));
    else
        return Elements[index];
}

template<typename Data>
void Vector<Data>:: Map(MapFunctor function, void* value){
    MapPreOrder(function, value);
}

template<typename Data>
void Vector<Data>:: MapPreOrder(MapFunctor function, void* value){

    for(ulong i=0; i<size; ++i)
        function(Elements[i], value);
}

template<typename Data>
void Vector<Data>:: MapPostOrder(MapFunctor function, void* value){

    for(ulong i=size-1; i<-1; --i)
        function(Elements[i], value);
}

template<typename Data>
void Vector<Data>:: Fold(FoldFunctor function, const void* data, void* value) const{
    FoldPreOrder(function, data, value);
}

template<typename Data>
void Vector<Data>:: FoldPreOrder(FoldFunctor function, const void* data, void* value) const{

    for(ulong i=0; i<size; ++i)
        function(Elements[i], data, value);
}

template<typename Data>
void Vector<Data>:: FoldPostOrder(FoldFunctor function, const void* data, void* value) const{

    for(ulong i=size-1; i<-1; --i)
        function(Elements[i], data, value);
}

}