
namespace lasd {


/* ************************************************************************** */

//Node Specific constructors
template <typename Data>
List<Data>::Node::Node(const Data& data){
    key = data;
}

template <typename Data>
List<Data>::Node::Node(Data&& data) noexcept{
    std::swap(key, data);
}

//Node Copy constructor

template <typename Data>
List<Data>::Node:: Node(const Node& nodo){

    key = nodo.key;
    next = nodo.next;
}


//Node Move constructor

template <typename Data>
List<Data>::Node:: Node(Node&& nodo) noexcept{

    swap(key, nodo.key);
    swap(next, nodo.next);
}


//Node Destructor
template <typename Data>
List<Data>::Node:: ~Node() noexcept{

    delete next;
}


//Node Comparison operators

template <typename Data>
bool List<Data>::Node:: operator==(const Node& nodo) const noexcept{

    return (key == nodo.key && next == nodo.next);
} 


template <typename Data>
bool List<Data>::Node:: operator!=(const Node& nodo) const noexcept{

    return !(*this==nodo);
}


/* ************************************************************************** */

//Specific constructor

template <typename Data>
List<Data>:: List(const LinearContainer<Data>& container){

    for(ulong i = 0; i<container.Size(); ++i)
        InsertAtBack(container[i]);
}

//Copy constructor

template <typename Data>
List<Data>:: List(const List& list){

    Node* tempNode = list.head;

    while(tempNode!= nullptr){

        InsertAtBack(tempNode->key);
        tempNode = tempNode->next;
    }
}

//Move constructor

template <typename Data>
List<Data>:: List(List&& list)  noexcept{

    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
}

//Destructor

template <typename Data>
List<Data>:: ~List() {

    delete head;
    head = nullptr;
    tail = nullptr;
}

/* ************************************************************************** */

// Copy assignment

template <typename Data>
List<Data>& List<Data>:: operator=(const List<Data>& list){

    List<Data>* temp = new List<Data>(list);

    std::swap(head, temp->head);
    std::swap(tail, temp->tail);
    std::swap(size, temp->size);

    delete temp;
    return *this;
}


//Move assignment

template <typename Data>
List<Data>& List<Data>:: operator=(List<Data>&& list) noexcept{

    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);

    return *this;
}

/* ************************************************************************** */

//Comparison operators

template <typename Data>
bool List<Data>:: operator==(const List<Data>& list) const noexcept{

    if(size != list.Size())
        return false;
    else
        {
            Node* t1 = head;
            Node* t2 = list.head;

            while(t1 != nullptr)
                if(t1->key != t2->key)
                    return false;
                else{
                    t1 = t1->next;
                    t2 = t2->next;
                }
        }

    return true;
}



template <typename Data>
bool List<Data>:: operator!=(const List<Data>& list) const noexcept{

    return !(*this == list);
}


/* ************************************************************************** */

// Specific member functions

template <typename Data>
void List<Data>:: InsertAtFront(const Data& data){

    Node* newNode = new Node();
    size++;

    newNode->key = data;
    newNode->next = head;
    head = newNode;

    if(size==1)
        tail = head;
  }


template <typename Data>
void List<Data>:: InsertAtFront(Data&& data){

    Node* newNode = new Node();
    size++;

    std::swap(newNode->key, data);
    newNode->next = head; 
    head = newNode;

    if(size == 1)
        tail = head;
}




template <typename Data>
void List<Data>:: RemoveFromFront(){

    if(size == 0)
        throw std::length_error("List is empty");
    else{

        size--;
        Node* temp = head;

        head = head->next;
        temp->next = nullptr;

        if(size < 2)
            tail = head;

        delete temp;
    }
} 


template <typename Data>
Data List<Data>:: FrontNRemove(){

    if(size ==0)
        throw std::length_error("List is empty");
    else{

        size--;
        Node* temp = head;
        Data data = head->key;

        head = head->next;
        temp->next = nullptr;

        if(size == 0)
            tail = nullptr;

        delete temp;
    
        return data;
    }
}


template <typename Data>
void List<Data>:: InsertAtBack(const Data& data){

    if(size == 0)
        InsertAtFront(data);
    else{
        size++;
        Node* newNode = new Node(data);
        
        tail->next = newNode;
        tail = newNode;
    }
    
}


template <typename Data>
void List<Data>:: InsertAtBack(Data&& data){

    if(size == 0)
        InsertAtFront(data);
    else{
        size++;
        Node* newNode = new Node(data);

        tail->next = newNode;
        tail = newNode;
    }


}


template <typename Data>
void List<Data>:: Clear(){

    delete head;

    head = nullptr;
    tail = nullptr;
    size = 0;
}


template <typename Data>
Data& List<Data>:: Front() const{

    if(size == 0)
        throw std::length_error("List is empty");
    else
        return head->key;
}


template <typename Data>
Data& List<Data>:: Back() const{

    if(size == 0)
        throw std::length_error("List is empty");
    else
        return tail->key;
}


template <typename Data>
Data& List<Data>:: operator[](const ulong index) const{

    if(index >= size)
        throw std::out_of_range("Index out of range. Vector size is " + std::to_string(size));
    else{

        Node* temp = head;

        for(ulong i=0; i<index; ++i)
            temp = temp->next;

        Data& data = temp->key;

        return data;
    }
}

/* ************************************************************************** */

// inherited from MappableContainer

template <typename Data>
void List<Data> :: Map(MapFunctor function, void* value){

    MapPreOrder(function, value);
} 


// inherited from PreOrderMappableContainer
template <typename Data>
void List<Data> :: MapPreOrder(MapFunctor function, void* value){

    MapPreOrder(function, value, head);
} 


// inherited from PostOrderMappableContainer

template <typename Data>
void List<Data> :: MapPostOrder(MapFunctor function, void* value){

    MapPostOrder(function, value, head);
} 



// inherited from FoldableContainer
template <typename Data>
void List<Data> :: Fold(FoldFunctor function, const void* data, void* value) const{

    FoldPreOrder(function, data, value);
} 


// inherited from PreOrderFoldableContainer
template <typename Data>
void List<Data> :: FoldPreOrder(FoldFunctor function, const void* data, void* value) const{

    FoldPreOrder(function, data, value, head);
} 

// inherited from PostOrderFoldableContainer
template <typename Data>
void List<Data> :: FoldPostOrder(FoldFunctor function, const void* data, void* value) const{

    FoldPostOrder(function, data, value, head);
}

/* ************************************************************************** */

// Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)


template <typename Data>
void List<Data> :: MapPostOrder(MapFunctor function, void* value, Node* node){

    if(node != nullptr){
 
        MapPostOrder(function, value, node->next);
        function(node->key, value);
    }
}


template <typename Data>
void List<Data> :: MapPreOrder(MapFunctor function, void* value, Node* node){

    if(node != nullptr){
 
        function(node->key, value);
        MapPreOrder(function, value, node->next);
    }
}

/* ************************************************************************** */

// Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)


template <typename Data>
void List<Data> :: FoldPostOrder(FoldFunctor function, const void* data, void* value, const Node* node) const{

    if(node != nullptr){

        FoldPostOrder(function, data, value, node->next);
        function(node->key, data, value);
    }
}


template <typename Data>
void List<Data> :: FoldPreOrder(FoldFunctor function, const void* data, void* value, const Node* node) const{

    if(node != nullptr){

        function(node->key, data, value);
        FoldPreOrder(function, data, value, node->next);
    }
}

}