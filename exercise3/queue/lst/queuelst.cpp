
namespace lasd {

/* ************************************************************************** */

//Constructors
template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& container){
    for(ulong i=0; i<container.Size(); ++i)
        List<Data>::InsertAtBack(container[i]);
}


template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& queue){
    struct List<Data>::Node* temp = queue.head;

    for(; temp!=nullptr; temp = temp->next)
        List<Data>::InsertAtBack(temp->key);
}



template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& queue) noexcept{
    std::swap(head, queue.head);
    std::swap(tail, queue.tail);
    std::swap(size, queue.size);
}


/* ************************************************************************ */

// Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queue){
    QueueLst<Data>* temp = new QueueLst<Data>(queue);

    std::swap(head, temp->head);
    std::swap(tail, temp->tail);
    std::swap(size, temp->size);

    delete temp;
    return *this;
}


//Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queue) noexcept{

    std::swap(head, queue.head);
    std::swap(tail, queue.tail);
    std::swap(size, queue.size);

    return *this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& queue) const noexcept{
    return List<Data>::operator==(queue);
}


template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst<Data>& queue) const noexcept{
    return !(*this==queue);
}

/* ************************************************************************ */

// Specific member functions (inherited from Queue)
template <typename Data>
const Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}

template <typename Data>
Data& QueueLst<Data>::Head(){
    if(size == 0)
        throw std::length_error("The Stack is Empty!");
    else
        return head->key;
}

template <typename Data>
void QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    return List<Data>::FrontNRemove();
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& data){
    List<Data>::InsertAtBack(data);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& data){
    List<Data>::InsertAtBack(std::move(data));
}


template <typename Data>
void QueueLst<Data>:: Clear(){
    List<Data>::Clear();
}

/* ************************************************************************** */

}
