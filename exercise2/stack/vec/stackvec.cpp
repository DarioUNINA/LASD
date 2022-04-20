
namespace lasd {

/* ************************************************************************** */

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stack) noexcept: Vector<Data>::Vector(std::move(stack)){
    std::swap(stack.head, head);
}


/* ************************************************************************ */

// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stack){
    Vector<Data>::operator=(stack);
    head = stack.head;

    return *this;
}


// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stack) noexcept{
    Vector<Data>::operator=(std::move(stack));
    std::swap(stack.head, head);

    return *this;
}
    

/* ************************************************************************ */

// Comparison operators

template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stack) const noexcept{
    if(head != stack.head)
        return false;
    else
        for(ulong i=0; i<head; i++)
            if(Elements[i] != stack[i])
                return false;
    return true;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stack) const noexcept{
    return !(*this == stack);
}


 /* ************************************************************************ */

// Specific member functions (inherited from Stack)

template <typename Data>
Data& StackVec<Data>::Top() const{
    if(head == 0)
        throw std::length_error("Stack is empty!");
    else
        return Elements[head-1];
}


template <typename Data>
Data& StackVec<Data>::Top(){
    if(head == 0)
        throw std::length_error("Stack is empty!");
    else
        return Elements[head-1];
}


template <typename Data>
void StackVec<Data>::Pop(){
    if(head==0)
        throw std::length_error("Stack si empty!");
    if(head <= size/4)
        Reduce();
    head--;
}


template <typename Data>
void StackVec<Data>::Push(const Data& data){
    if(head == size)
        Expand();

    Elements[head] = data;
    head++;
}


template <typename Data>
void StackVec<Data>::Push(Data&& data) noexcept{
    if(head == size)
        Expand();

    std::swap(Elements[head],data);
    head++;
}


template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(head == 0)
        throw std::length_error("Stack is empty!");

    Data data = Elements[head-1];
    Pop();

    return data;
}


/* ************************************************************************ */

// Auxiliary member functions

template <typename Data>
void StackVec<Data>::Expand(){
    Vector<Data>::Resize(size*2);
}

template <typename Data>
void StackVec<Data>::Reduce(){
    Vector<Data>::Resize(size/2);
}


/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
    return head == 0;   
}


template <typename Data>
ulong StackVec<Data>::Size() const noexcept{
    return head;
}


template <typename Data>
void StackVec<Data>::Clear() {
    if(head == 0)
        throw std::length_error("Stack is empty!");
    
    Vector<Data>::Resize(1);
    head=0;
}

/* ************************************************************************** */

}
