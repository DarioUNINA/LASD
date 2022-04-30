
namespace lasd {

/* ************************************************************************** */

// Copy Constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec& node){
    vector = node.vector;
    key = node.key;
    index = node.index;
}


/* ************************************************************************** */

// Copy and Move Assignment
template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node){
    index = node.index;
    key = node.key;
    vector = node.vector;

    return *this;
}


template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept{
    std::swap(index, node.index);
    std::swap(vector, node.vector);
    std::swap(key, node.key);

    return *this;
}

/* ************************************************************************** */


// Specific member Functions (inherited from Node)
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec:: IsLeaf() const noexcept{
    return ((2*index)+1 < vector->Size()  && 2*(index+1) < vector->Size());
}


template <typename Data>
bool BinaryTreeVec<Data>::NodeVec:: HasLeftChild() const noexcept{
    return ((2*index)+1 < vector->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec:: HasRightChild() const noexcept{
    return (2*(index+1) < vector->Size());
}


template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec:: RightChild(){
    if(2*(index+1) >= vector->Size())
        throw std::out_of_range("The node has no right child!\n");

    return *((*vector)[2*(index+1)]);
}


template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec:: LeftChild(){
    if((2*index)+1 >= vector->Size())
        throw std::out_of_range("The node has no right child!\n");

    return *((*vector)[(2*index)+1]);
}


template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec:: RightChild() const{
    if(2*(index+1) >= vector->Size())
        throw std::out_of_range("The node has no right child!\n");

    return *((*vector)[2*(index+1)]);
}


template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec:: LeftChild() const{
    if((2*index)+1 >= vector->Size())
        throw std::out_of_range("The node has no right child!\n");

    return *((*vector)[(2*index)+1]);
}


/* ************************************************************************** */
/* ************************************************************************** */

// Contructors
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& container){
    vector = new Vector<NodeVec*>(container.Size());

    for(ulong i = 0; i<container.Size();i++)
       (*vector)[i] = new NodeVec(vector, i, container[i]);

    size = container.Size();
    root = (*vector)[0];
}


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree){
    vector = new Vector<NodeVec*>(tree.size);

    for(ulong i = 0; i< tree.size; i++)
        (*vector)[i] = new NodeVec(*((*(tree.vector))[i]));

    size = tree.Size();
    root = (*vector)[0];
}


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept{
    std::swap(vector, tree.vector);
    std::swap(size, tree.size);
    std::swap(root, tree.root);
}


// Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    delete root;

    delete vector;
}


/* ************************************************************************** */

//  Copy and Move Assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& tree){
    BinaryTreeVec<Data>* temp = new BinaryTreeVec<Data>(tree);

    std::swap(*this, *temp);
    delete temp;

    return *this;
}


//  Copy and Move Assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& tree) noexcept{
    std::swap(size, tree.size);
    std::swap(root, tree.root);
    std::swap(vector, tree.vector);

    return *this;
}

/* ************************************************************************** */

//  Specific Member Functions
template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>:: Root() const{
    if(size == 0)
        throw std::length_error("The tree is empty!\n");

    return *root;
}


//  Specific Member Functions
template <typename Data>
void BinaryTreeVec<Data>:: Clear(){
    size = 0;
    
    delete vector;
    delete root;

    root = nullptr;
    vector = nullptr;
}


template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor function, const void* value, void* data) const{
    for(ulong i = 0; i<size; i++)
        function((*vector)[i]->Element(), value, data);
}


template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor function, void* value) {
    for(ulong i = 0; i<size; i++)
        function((*vector)[i]->Element(), value);
}



}
