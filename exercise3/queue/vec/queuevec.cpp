
namespace lasd {

/* ************************************************************************** */

// Constructors
template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& container){
    size = container.Size()+1;
    tail = size-1;
    Elements = new Data[size];

    for(ulong i=0; i< container.Size(); i++)
        Elements[i] = container[i];
}


template<typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& queue) noexcept:Vector<Data>(std::move(queue)){
    std::swap(tail, queue.tail);
    std::swap(head, queue.head);
}

/* ************************************************************************** */

// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& queue){
    Vector<Data>::operator=(queue);
    head = queue.head;
    tail = queue.tail;

    return *this;
}

// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queue) noexcept{
    Vector<Data>::operator=(std::move(queue));
    std::swap(head, queue.head);
    std::swap(tail, queue.tail);

    return *this;
}


/* ************************************************************************ */

// Comparison operators
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& queue) const noexcept{
    if(Size() != queue.Size())
        return false;
    else{
        ulong index = queue.head;

        for(ulong i = head; i!=tail; i = (i+1)%(size))
            if(Elements[i] != queue[index])
                return false;
            else
                index = (++index)%queue.size;

        return true;
    }
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& queue) const noexcept{
    return !(*this==queue);
}


/* ************************************************************************ */

// Specific member functions (inherited from Queue)

template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(head == tail)
        throw std::length_error("Queue is empty!");
    else
        return Elements[head];
}


template <typename Data>
Data& QueueVec<Data>::Head(){
    if(head == tail)
        throw std::length_error("Queue is empty!");
    else
        return Elements[head];
}


template <typename Data>
void QueueVec<Data>::Dequeue(){
    if(head == tail)
        throw std::length_error("Queue is empty!");

    else{
        head = (++head)%size;

        if(Size()<=size/4)
            Reduce();
    }
}



template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if(head == tail)
        throw std::length_error("Queue is empty!");
    else{
        Data temp = Elements[head];

        head = (++head)%size;
        if(Size()<=size/4)
            Reduce();

        return temp;
    }
}

template <typename Data>
void QueueVec<Data>:: Enqueue(const Data& data){
    if(tail == (head-1)%size)
        Expand();

    Elements[tail] = data;
    tail = (++tail)%size;
}

template <typename Data>
void QueueVec<Data>:: Enqueue(Data&& data){
    if(tail == (head-1)%size)
        Expand();

    std::swap(Elements[tail],data);
    tail = (++tail)%size;
}


/* ************************************************************************ */

//Specific member functions (inherited from Container)
template <typename Data>
bool QueueVec<Data>:: Empty() const noexcept{
   return tail == head;
}


template <typename Data>
ulong QueueVec<Data>:: Size() const noexcept{
     if(head <= tail) 
        return tail-head;
    else
        return size-(head-tail);
}


template <typename Data>
void QueueVec<Data>:: Clear(){
    if(head != tail){
        Vector<Data>::Resize(1);
        head=0;
        tail=0;
    }
    
    
}


/* ************************************************************************ */

//Auxiliary member functions
template <typename Data>
void QueueVec<Data>::Expand(){
    QueueVec<Data>* temp = new QueueVec<Data>();
    temp->Resize(size*2);

    SwapVectors(*temp);
    delete temp;
}

template <typename Data>
void QueueVec<Data>::Reduce(){
    QueueVec<Data>* temp = new QueueVec<Data>();
    temp->Resize(size/2);

    SwapVectors(*temp);
    delete temp;
}


template <typename Data>
void QueueVec<Data>:: SwapVectors(QueueVec<Data>& queue){
    ulong index = 0;
    for(ulong i = head; i!=tail; i = (i+1)%(size)){
        std::swap(Elements[i], queue.Elements[index]);
        ++index;
    }
    queue.tail = index;
    queue.head = 0;

    std::swap(*this, queue);
}

/* ************************************************************************ */

}
