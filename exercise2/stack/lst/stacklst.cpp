namespace lasd {

/* ************************************************************************** */

 // Constructors
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& container){
    for(ulong i=0; i<container.Size(); ++i)
        List<Data>::InsertAtBack(container[i]);
}


template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stack){
    struct List<Data>::Node* temp = stack.head;

    while(temp!=nullptr){
        List<Data>::InsertAtBack(temp->key);
        temp = temp->next;
    }
}


template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stack) noexcept{
    std::swap(head, stack.head);
    std::swap(size, stack.size);
}


/* ************************************************************************ */

// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>:: operator=(const StackLst<Data>& stack){
    StackLst<Data>* temp = new StackLst<Data>(stack);

    std::swap(size, temp->size);
    std::swap(head, temp->head);

    delete temp;
    return *this;
}

// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>:: operator=(StackLst<Data>&& stack) noexcept{

    std::swap(size, stack.size);
    std::swap(head, stack.head);

    return *this;
}

/* ************************************************************************ */

  // Comparison operators
template <typename Data>
bool StackLst<Data>:: operator==(const StackLst<Data>& stack) const noexcept{
    return List<Data>::operator==(stack);
}


template <typename Data>
bool StackLst<Data>:: operator!=(const StackLst<Data>& stack) const noexcept{
    return !(*this == stack);
}


/* ************************************************************************ */

// Specific member functions (inherited from Stack)

template <typename Data>
const Data& StackLst<Data>:: Top() const{
    return List<Data>:: Front();
}


template <typename Data>
Data& StackLst<Data>:: Top(){
    return List<Data>:: Front();
}


template <typename Data>
void StackLst<Data>:: Pop(){
    List<Data>:: RemoveFromFront();
}


template <typename Data>
Data StackLst<Data>:: TopNPop(){
    return List<Data>:: FrontNRemove();
}


template <typename Data>
void StackLst<Data>:: Push(const Data& data){
    List<Data>:: InsertAtFront(data);
}


template <typename Data>
void StackLst<Data>:: Push(Data&& data){
    List<Data>:: InsertAtFront(std::move(data));
}


template <typename Data>
void StackLst<Data>:: Clear(){
    delete head;

    head = nullptr;
    size = 0;
}

/* ************************************************************************** */

}
