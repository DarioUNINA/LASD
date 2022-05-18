namespace lasd {

/* ************************************************************************** */
/* ************************************************************************** */

// Comparison Operators
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
    if(key == node.Element())
        if(HasLeftChild() == node.HasLeftChild())
            if(!HasLeftChild() || LeftChild() == node.LeftChild())
                if(HasRightChild() == node.HasRightChild())
                    if(!HasRightChild() || RightChild() == node.RightChild())
                        return true;
return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept{
    return !(*this == node);
}


//Specific member Functions
template <typename Data>
Data& BinaryTree<Data>::Node::Element() noexcept{
    return key;
}

template <typename Data>
const Data& BinaryTree<Data>::Node::Element() const noexcept{
    return key;
}

/* ************************************************************************** */
/* ************************************************************************** */


// Comparison operators
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept{
    if(size == tree.Size())
        if(size == 0)
            return true;
        else
            return (Root() == tree.Root());

    return false;
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& tree) const noexcept{
    return !(*this == tree);
}


/* ************************************************************************** */

// Specific member functions
template <typename Data>
void BinaryTree<Data>::Map(MapFunctor function, void* value){
    if(size>0)
        MapBreadth(function, value);
}


template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor function, void* value){
    if(size>0)
        MapPreOrder(function, value, Root());
}


template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor function, void* value){
    if(size>0)
        MapPostOrder(function, value, Root());
}


template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor function, void* value){
    if(size>0)
        MapInOrder(function, value, Root());
}


template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor function, const void* value, void* data) const{
    if(size>0)
        FoldBreadth(function, value, data);
}


template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor function, const void* value, void* data) const{
    if(size>0)
        FoldPreOrder(function, value, data, Root());
}


template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor function, const void* value, void* data) const{
    if(size>0)
        FoldPostOrder(function, value, data, Root());
}


template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor function, const void* value, void* data) const{
    if(size>0)
        FoldInOrder(function, value, data, Root());
}


/* ************************************************************************** */

//Auxiliary member Functions for Map and Fold
template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor function, void* value, Node& node){
    function(node.Element(), value);
    if(node.HasLeftChild())
        MapPreOrder(function, value, node.LeftChild());
    if(node.HasRightChild())
        MapPreOrder(function, value, node.RightChild());
}


template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor function, void* value, Node& node){
    if(node.HasLeftChild())
        MapPostOrder(function, value, node.LeftChild());
    if(node.HasRightChild())
        MapPostOrder(function, value, node.RightChild());
    function(node.Element(), value);
}


template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor function, void* value, Node& node){
    if(node.HasLeftChild())
        MapInOrder(function, value, node.LeftChild());
        
    function(node.Element(), value);

    if(node.HasRightChild())
        MapInOrder(function, value, node.RightChild());   
}


template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor function, void* value){
    BTBreadthIterator<Data> i(*this);

    while(!(i.Terminated())){
        function(*i, value);
        ++i;
    }
}


template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor function, const void* value, void* data, Node& node) const{
    function(node.Element(), value, data);
    if(node.HasLeftChild())
        FoldPreOrder(function, value, data, node.LeftChild());
    if(node.HasRightChild())
        FoldPreOrder(function, value, data, node.RightChild());
}


template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor function, const void* value, void* data, Node& node) const{
    if(node.HasLeftChild())
        FoldPostOrder(function, value, data, node.LeftChild());
    if(node.HasRightChild())
        FoldPostOrder(function, value, data, node.RightChild());
    function(node.Element(), value, data);
}


template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor function, const void* value, void* data, Node& node) const{
    if(node.HasLeftChild())
        FoldInOrder(function, value, data, node.LeftChild());
        
    function(node.Element(), value, data);

    if(node.HasRightChild())
        FoldInOrder(function, value, data, node.RightChild());
}


template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor function, const void* value, void* data) const{
    BTBreadthIterator<Data> i(*this);

    while(!(i.Terminated())){
        function(*i, value, data);
        ++i;
    }
}

/* ************************************************************************** */
/* ************************************************************************** */


 // Constructors
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Size()>0){
        current = &(tree.Root());
        root = current;        
    }
}


template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator){
    current = iterator.current;
    root = iterator.root;
    stack = iterator.stack;
}


template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator) noexcept{
   std::swap(current, iterator.current);
   std::swap(root, iterator.root);
   std::swap(stack, iterator.stack);
}


/* ************************************************************************** */

// Copy and Move Assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iterator){
    BTPreOrderIterator<Data>* temp = new BTPreOrderIterator<Data>(iterator);

    std::swap(*this, temp);
    delete temp;

    return *this;
}


template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);

    return *this;
}


/* ************************************************************************** */

// Comparison operators
template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iterator) const noexcept{
    return (current == iterator.current && root == iterator.root && stack == iterator.stack);
}


template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iterator) const noexcept{
    return !(*this == iterator);
}


/* ************************************************************************** */

// Specific member functions
template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");

    return current->Element();
}


template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");

    if(stack.Empty() &&  current->IsLeaf())
        current = nullptr;
    else
        if(current->IsLeaf())
            current = stack.TopNPop();
        else
            if(current->HasLeftChild()){
                if(current->HasRightChild())
                     stack.Push(&(current->RightChild()));
                current = &(current->LeftChild());
            }else
                current = &(current->RightChild());

    return *this;
}


template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
    return current == nullptr;
}


template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept{
    current = root;
    stack.Clear();
}


/* ************************************************************************** */
/* ************************************************************************** */

// Constructors
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Size()>0){
        root = &(tree.Root());
        current = root;

        Explore();
    }
}


template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& iterator){
    current = iterator.current;
    root = iterator.root;
    stack = iterator.stack;
}


template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& iterator) noexcept{
   std::swap(current, iterator.current);
   std::swap(root, iterator.root);
   std::swap(stack, iterator.stack);
}


/* ************************************************************************** */

// Copy and Move Assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& iterator){
    BTPostOrderIterator<Data>* temp = new BTPostOrderIterator<Data>(iterator);

    std::swap(*this, temp);
    delete temp;

    return *this;
}


template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iterator) noexcept{
    BTPostOrderIterator<Data>* temp = new BTPostOrderIterator<Data>(std::move(iterator));

    std::swap(*this, temp);
    delete temp;

    return *this;
}


/* ************************************************************************** */

// Comparison operators
template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iterator) const noexcept{
    return (current == iterator.current && root == iterator.root && stack == iterator.stack);
}


template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iterator) const noexcept{
    return !(*this == iterator);
}


/* ************************************************************************** */

// Specific member functions
template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");

    return current->Element();
}


template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");

    if(stack.Empty())
        current = nullptr;
    else
        if(!(stack.Top()->HasRightChild()) || &(stack.Top()->RightChild()) == current)
            current = stack.TopNPop();
        else{
            current = &(stack.Top()->RightChild());
            Explore();
        }

    return *this;
}


template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
    return current == nullptr;
}


template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept{
    current = root;

    stack.Clear();
    Explore();
}


/* ************************************************************************** */

//Auxiliary Member Function
template <typename Data>
void BTPostOrderIterator<Data>::Explore() noexcept{
    while(current!= nullptr && !(current->IsLeaf())){
        stack.Push(current);

        if(current->HasLeftChild())
            current = &(current->LeftChild());
        else
            current = &(current->RightChild());
    }
}


/* ************************************************************************** */
/* ************************************************************************** */

// Constructors
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Size()>0){
        root = &(tree.Root());
        current = root;

        Explore();
    }
}


template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator){
    current = iterator.current;
    root = iterator.root;
    stack = iterator.stack;
}


template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator) noexcept{
   std::swap(current, iterator.current);
   std::swap(root, iterator.root);
   std::swap(stack, iterator.stack);
}


/* ************************************************************************** */

// Copy and Move Assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iterator){
    BTInOrderIterator<Data>* temp = new BTInOrderIterator<Data>(iterator);

    std::swap(*this, temp);
    delete temp;

    return *this;
}


template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator) noexcept{
    BTInOrderIterator<Data>* temp = new BTInOrderIterator<Data>(std::move(iterator));

    std::swap(*this, temp);
    delete temp;

    return *this;
}


/* ************************************************************************** */

// Comparison operators
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator) const noexcept{
    return (current == iterator.current && root == iterator.root && stack == iterator.stack);
}


template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator) const noexcept{
    return !(*this == iterator);
}


/* ************************************************************************** */

// Specific member functions
template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");

    return current->Element();
}


template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");
    
    if(stack.Empty() && !(current->HasRightChild()))
        current = nullptr;
    else
        if(current->HasRightChild()){
            current = &(current->RightChild());
            Explore();
        
        }else
            current = stack.TopNPop();
        
    return *this;
}


template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
    return current == nullptr;
}


template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept{
    current = root;

    stack.Clear();
    Explore();
}


/* ************************************************************************** */

//Auxiliary Member Function
template <typename Data>
void BTInOrderIterator<Data>::Explore() noexcept{
    while(current!=nullptr && current->HasLeftChild()){
        stack.Push(current);
        current = &(current->LeftChild());
    }
}


/* ************************************************************************** */
/* ************************************************************************** */


// Constructors
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree){
    if(tree.Size()>0){
        root = &(tree.Root());
        current = root;
    }
}


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator){
    current = iterator.current;
    root = iterator.root;
    queue = iterator.queue;
}


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iterator) noexcept{
   std::swap(current, iterator.current);
   std::swap(root, iterator.root);
   std::swap(queue, iterator.queue);
}


/* ************************************************************************** */

// Copy and Move Assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iterator){
    BTBreadthIterator<Data>* temp = new BTBreadthIterator<Data>(iterator);

    std::swap(*this, temp);
    delete temp;

    return *this;
}


template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iterator) noexcept{
    BTBreadthIterator<Data>* temp = new BTBreadthIterator<Data>(std::move(iterator));

    std::swap(*this, temp);
    delete temp;

    return *this;
}


/* ************************************************************************** */

// Comparison operators
template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept{
    return (current == iterator.current && root == iterator.root && queue == iterator.queue);
}


template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept{
    return !(*this == iterator);
}


/* ************************************************************************** */

// Specific member functions
template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");

    return current->Element();
}


template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
    if(Terminated())
        throw std::out_of_range("The iterator is pointing to NULL!\n");
    
    if(queue.Empty() && (current!= root || current->IsLeaf()))
        current = nullptr;
    else{
        if(current->HasLeftChild())
            queue.Enqueue(&(current->LeftChild()));        

        if(current->HasRightChild())
            queue.Enqueue(&(current->RightChild()));
    
        current = queue.HeadNDequeue();
    }

    return *this;
}


template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    return current == nullptr;
}


template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept{
    current = root;
    queue.Clear();
}


}