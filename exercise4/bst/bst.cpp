
namespace lasd {
    

/* ************************************************************************** */

// Specific Constructor

 template <typename Data>
 BST<Data>::BST(const LinearContainer<Data>& container){
     container.Sort();

     root = BuildTree(container, 0, container.Size()-1);
     size = container.Size();
 }


/* ************************************************************************** */

// Copy and Move Assignment

 template <typename Data>
 BST<Data>& BST<Data>::operator=(const BST<Data>& tree){
     BinaryTreeLnk<Data>::operator=(tree);
     return *this;

 }

 template <typename Data>
 BST<Data>& BST<Data>::operator=(BST<Data>&& tree) noexcept{
    BinaryTreeLnk<Data>::operator=(std::move(tree));
    return *this;
 }

/* ************************************************************************** */

 template <typename Data>
 bool BST<Data>::operator==(const BST<Data>& tree) const noexcept{
    if(size == tree.Size()){
        if(size!=0){
            BTInOrderIterator i(*this);
            BTInOrderIterator it(tree);
        
            while(!(i.Terminated())){
                if((*i)!=(*it))
                    return false;
                
                ++i;
                ++it;
            }
        }
        return true;
    }else
        return false;
 }


 template <typename Data>
 bool BST<Data>::operator!=(const BST<Data>& tree) const noexcept{
    return !(*this==tree);
 }


/* ************************************************************************** */

// Specific member functions


 template <typename Data>
 bool BST<Data>::Exists(const Data& data) const noexcept{
     if(size == 0)
        return false;

     NodeLnk* result = FindPointerTo(root, data);

     return result!=nullptr;
 }


 template <typename Data>
 const Data& BST<Data>::Min() const{
    if(size==0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk* node = FindPointerToMin(root);
    
    return node->key;
}


 template <typename Data>
 Data BST<Data>::MinNRemove(){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

     NodeLnk* min = DetachMin(root);
     Data result = min->key;

     delete min;
     return result;
 }

  template <typename Data>
 void BST<Data>::RemoveMin(){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

     NodeLnk* min = DetachMin(root);
     delete min;
}


 template <typename Data>
 const Data& BST<Data>::Max() const{
     if(size == 0)
        throw std::length_error("The BST is empty!\n");
    
    NodeLnk* node = FindPointerToMax(root);
    return node->key;
 }


template <typename Data>
 Data BST<Data>::MaxNRemove(){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

     NodeLnk* max = DetachMax(root);
     Data result = max->key;

     delete max;
     return result;
 }


 template <typename Data>
 void BST<Data>::RemoveMax(){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

     NodeLnk* max = DetachMax(root);
     delete max;
}


 template <typename Data>
 const Data& BST<Data>::Predecessor(const Data& data) const{
    if(size == 0)
        throw std::length_error("The BST is empty!\n");
    
     NodeLnk** node = FindPointerToPredecessor(root, data);
     return (*node)->key;
 }

 
 template <typename Data>
 Data BST<Data>::PredecessorNRemove(const Data& data){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk* pred = Detach(FindPointerToPredecessor(data));
    Data result = pred->key;

    delete pred;
    return result;
 }


 template <typename Data>
 void BST<Data>::RemovePredecessor(const Data& data){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk* pred = Detach(Predecessor(data));
    delete pred;
 }
 
 
 template <typename Data>
 const Data& BST<Data>::Successor(const Data& data) const{
    if(size == 0)
        throw std::length_error("The BST is empty!\n");
    
     NodeLnk** succ = FindPointerToSuccessor(root, data);
     return (*succ)->key;
 }


 template <typename Data>
 Data BST<Data>::SuccessorNRemove(const Data& data){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk* pred = Detach(FindPointerToSuccessor(data));
    Data result = pred->key;

    delete pred;
    return result;
 }


 template <typename Data>
 void BST<Data>::RemoveSuccessor(const Data& data){
     if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk* succ = Detach(FindPointerToSuccessor(data));
    delete succ;
 }


/* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

 template <typename Data>
 void BST<Data>:: Insert(const Data& data){
     NodeLnk* newNode = new NodeLnk(data, nullptr, nullptr);

    NodeLnk* parent = FindPointerTo(root, data);

    if(parent->key > data)
        parent->leftChild = newNode;
    else
        parent->rightChild = newNode;
 }

 template <typename Data>
 void BST<Data>:: Insert(Data&& data){
     NodeLnk* newNode = new NodeLnk(std::move(data));

    NodeLnk* parent = FindPointerTo(root, data);

    if(parent->key > data)
        parent->leftChild = newNode;
    else
        parent->rightChild = newNode;
 }

 
 template <typename Data>
 void BST<Data>:: Remove(const Data& data){
     NodeLnk* node = Detach(FindPointerTo(root, data));

     delete node;
}

 
 /* ************************************************************************** */

//  Auxiliary Member Function

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>:: BuildTree(const LinearContainer<Data>& container, ulong first, ulong last){
     NodeLnk* left = nullptr;
     NodeLnk* right = nullptr;
     ulong middle = (first+last)/2;

     if(last>first){
        NodeLnk* left = BuildTree(container, first, middle-1);
        NodeLnk* right = BuildTree(container, middle+1, last);
     }
     
     NodeLnk* node = new NodeLnk(container[middle], left, right);

     return node;
 }


template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>:: FindPointerToMin(NodeLnk* const& node) const noexcept{
    NodeLnk* const* parent = &node;
    NodeLnk* current = node;

    if(current!=nullptr)
        while(current->HasLeftChild()){
            parent = &current->leftChild; //puntatore a leftChild (puntatore a puntatore a nodo)
            current = current->leftChild;
        }

    return *parent;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>:: FindPointerToMin(NodeLnk*& node) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>:: FindPointerToMax(NodeLnk* const& node) const noexcept{
    NodeLnk* const* parent = &node;
    NodeLnk* current = node;

    if(current!=nullptr)
        while(current->HasRightChild()){
            parent = &current->rightChild; //puntatore a leftChild (puntatore a puntatore a nodo)
            current = current->rightChild;
        }

    return *parent;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>:: FindPointerToMax(NodeLnk*& node) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>:: FindPointerTo(NodeLnk* const& node, const Data& data) const noexcept{
    NodeLnk* const* parent = &node;
    NodeLnk* current = node;

    if(current!=nullptr)
        while(current!=nullptr)
            if(current->key > data){
                parent = &current->leftChild;
                current = current->leftChild;
            }else
                if(current->key < data){
                    parent = &current->rightChild;
                    current = current->rightChild;
                }else
                    break;
    
    return *parent;    
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>:: FindPointerTo(NodeLnk*& node, const Data& data) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* const*  BST<Data>:: FindPointerToSuccessor(NodeLnk* const& node, const Data& data) const noexcept{
    NodeLnk* const* current = &node;
    NodeLnk* const* successor = nullptr;

    while(*current != nullptr)
        if((*current)->key == data)
            return &FindPointerToMin((*current)->rightChild);
        else
            if((*current)->key > data){
                successor = current;
                if((*current)->leftChild != nullptr)
                    current = &current->leftChild;
                else
                    return successor;
            }else
                if((*current)->rightChild != nullptr)
                    current = &current->rightChild;
                else
                    return successor;

}


template <typename Data>
typename BST<Data>::NodeLnk**  BST<Data>:: FindPointerToSuccessor(NodeLnk*& node, const Data& data) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk* const*  BST<Data>:: FindPointerToPredecessor(NodeLnk* const& node, const Data& data) const noexcept{
    NodeLnk* const* current = &node;
    NodeLnk* const* predecessor = nullptr;

    while(*current != nullptr)
        if((*current)->key == data)
            return &FindPointerToMax((*current)->leftChild);
        else
            if((*current)->key < data){
                predecessor = current;
                if((*current)->leftChild != nullptr)
                    current = &current->leftChild;
                else
                    return predecessor;
            }else
                if((*current)->rightChild != nullptr)
                    current = &current->rightChild;
                else
                    return predecessor;
}


template <typename Data>
typename BST<Data>::NodeLnk**  BST<Data>:: FindPointerToPredecessor(NodeLnk*& node, const Data& data) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: Skip2Left(NodeLnk* & node) noexcept{
    NodeLnk* temp = nullptr;
    if(node!=nullptr){
        size--;

        std::swap(temp, node->leftChild);
        std::swap(temp, node);
    }

    return temp;
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: Skip2Right(NodeLnk* & node) noexcept{
    NodeLnk* temp = nullptr;
    if(node!=nullptr){
        size--;

        std::swap(temp, node->rightChild);
        std::swap(temp, node);
    }

    return temp;
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: DetachMin(NodeLnk* & node) noexcept{
    NodeLnk* parent = FindPointerToMin(node);
    NodeLnk* min = parent->leftChild;

    if(min->IsLeaf()){
        parent->leftChild == nullptr;
        return min;
    }else
        return Skip2Right(parent);        
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: DetachMax(NodeLnk* & node) noexcept{
    NodeLnk* parent = FindPointerToMax(node);
    NodeLnk* max = parent->leftChild;

    if(max->IsLeaf()){
        parent->rightChild == nullptr;
        return max;
    }else
        return Skip2Left(parent);        
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: Detach(NodeLnk* & node) noexcept{



}


}


