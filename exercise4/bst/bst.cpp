
namespace lasd {
    

/* ************************************************************************** */

// Specific Constructor

 template <typename Data>
 BST<Data>::BST(const LinearContainer<Data>& container){
     for(ulong i =0; i< container.Size(); ++i)
        Insert(container[i]);
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

     NodeLnk* const& result = FindPointerTo(root, data);
     return result!=nullptr;
 }


 template <typename Data>
 const Data& BST<Data>::Min() const{
    if(size==0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk* const& node = FindPointerToMin(root);
    
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
    
    NodeLnk* const& node = FindPointerToMax(root);
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
    
     NodeLnk* const* node = FindPointerToPredecessor(root, data);
     
     if(node ==nullptr)
        throw std::length_error("Predecessor not found!\n");
     else
        return (*node)->key;
 }

 
 template <typename Data>
 Data BST<Data>::PredecessorNRemove(const Data& data){
    if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk** temp = FindPointerToPredecessor(root, data);

    if(temp != nullptr){
        NodeLnk* pred = Detach(*temp);
        Data result = pred->key;

        delete pred;
        return result;
    }else
        throw std::length_error("Predecessor of given value note found!\n");
 }


 template <typename Data>
 void BST<Data>::RemovePredecessor(const Data& data){
    if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk** temp = FindPointerToPredecessor(root, data);

    if(temp != nullptr){
        NodeLnk* pred = Detach(*temp);
        delete pred;
    }else
        throw std::length_error("Predecessor of given value not found!\n");
 }
 
 
 template <typename Data>
 const Data& BST<Data>::Successor(const Data& data) const{
    if(size == 0)
        throw std::length_error("The BST is empty!\n");
    
     NodeLnk* const* succ = FindPointerToSuccessor(root, data);
     
     if(succ == nullptr)
        throw std::length_error("Successor not found!\n");
     else
        return (*succ)->key;
 }


 template <typename Data>
 Data BST<Data>::SuccessorNRemove(const Data& data){
    if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk** temp = FindPointerToSuccessor(root, data);

    if(temp != nullptr){
        NodeLnk* succ = Detach(*temp);
        Data result = succ->key;

        delete succ;
        return result;
    }else
        throw std::length_error("Successor of given value not found!\n");
 }


 template <typename Data>
 void BST<Data>::RemoveSuccessor(const Data& data){
    if(size == 0)
        throw std::length_error("The BST is empty!\n");

    NodeLnk** temp = FindPointerToSuccessor(root, data);

    if(temp != nullptr){
        NodeLnk* succ = Detach(*temp);
        delete succ;
    }else
        throw std::length_error("Successor of given value not found!\n");
 }


/* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

 template <typename Data>
 bool BST<Data>:: Insert(const Data& data){

    NodeLnk*& temp = FindPointerTo(root, data);
    if(temp ==nullptr){
        NodeLnk* newNode = new NodeLnk(data, nullptr, nullptr);
        temp = newNode;
        size++;
        
        return true;
    }else
        return false;
 }


 template <typename Data>
 bool BST<Data>:: Insert(Data&& data){
    NodeLnk*& temp = FindPointerTo(root, data);
    if(temp ==nullptr){
        temp = new NodeLnk(std::move(data));
        size++;

        return true;
    }else
        return false;
 }

 
 template <typename Data>
 bool BST<Data>:: Remove(const Data& data){
     NodeLnk* node = Detach(FindPointerTo(root, data));

     if(node==nullptr)
        return false;

     delete node;
     return true;
}

 
 /* ************************************************************************** */

//  Auxiliary Member Function

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>:: FindPointerToMin(NodeLnk* const& node) const noexcept{
    NodeLnk* const* parent = &node;
    NodeLnk* current = node;

    if(current!=nullptr)
        while(current->HasLeftChild()){
            parent = &current->leftChild;
            current = current->leftChild;
        }

    return *parent; //torna un riferimento a current->leftChild
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
            parent = &current->rightChild;
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

        while(current!=nullptr){
            if(current->key > data ){
                parent = &current->leftChild;
                current = current->leftChild;
            }else
                if(current->key < data){
                    parent = &current->rightChild;
                    current = current->rightChild;
                }else
                    break;}
    
    return *parent;    
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>:: FindPointerTo(NodeLnk*& node, const Data& data) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk* const*  BST<Data>:: FindPointerToSuccessor(NodeLnk* const& node, const Data& data) const noexcept{
    NodeLnk* const* current = &node;
    NodeLnk* const* successor = nullptr;

    while(*current != nullptr)
        if((*current)->key == data)
            if((*current)->HasRightChild())
                return &FindPointerToMin((*current)->rightChild);
            else
                return successor;
        else
            if((*current)->key > data){
                successor = current;
                if((*current)->HasLeftChild())
                    current = &(*current)->leftChild;
                else
                    return successor;
            }else
                if((*current)->HasRightChild())
                    current = &(*current)->rightChild;
                else
                    return successor;
    
    return nullptr;
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
            if((*current)->HasLeftChild())
                return &FindPointerToMax((*current)->leftChild);
            else
                return predecessor;
        else
            if((*current)->key < data){
                predecessor = current;
                if((*current)->HasRightChild())
                    current = &(*current)->rightChild;
                else
                    return predecessor;
            }else
                if((*current)->HasLeftChild())
                    current = &(*current)->leftChild;
                else
                    return predecessor;

    return nullptr;
}


template <typename Data>
typename BST<Data>::NodeLnk**  BST<Data>:: FindPointerToPredecessor(NodeLnk*& node, const Data& data) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: Skip2Left(NodeLnk* & node) noexcept{
    NodeLnk* temp = nullptr;
    if(node!=nullptr){
        std::swap(temp, node->leftChild);
        std::swap(temp, node);
        size--;
    }

    return temp;
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: Skip2Right(NodeLnk* & node) noexcept{
    NodeLnk* temp = nullptr;
    if(node!=nullptr){
        std::swap(temp, node->rightChild);
        std::swap(temp, node);
        size--;
    }

    return temp;
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: DetachMin(NodeLnk* & node) noexcept{
    return Skip2Right(FindPointerToMin(node));
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: DetachMax(NodeLnk* & node) noexcept{
    return Skip2Left(FindPointerToMax(node));        
}


template <typename Data>
typename BST<Data>::NodeLnk*  BST<Data>:: Detach(NodeLnk* & node) noexcept{
    if(node!=nullptr){
        if(node->HasLeftChild() && node->HasRightChild()){
            NodeLnk* min = DetachMax(node->leftChild);
            std::swap(node->key, min->key);
            return min;
        }
    
        if(!node->HasLeftChild())
            return Skip2Right(node);
        else
            return Skip2Left(node);
    }else
        return DetachMin(node);
    
}       


template <typename Data>
Data  BST<Data>:: DataNDelete(NodeLnk* & node) noexcept{
    NodeLnk* temp = Detach(node);

    Data result = temp->key;

    delete temp;
    return result;
}


}


