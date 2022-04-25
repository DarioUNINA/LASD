
namespace lasd {

/* ************************************************************************** */

// Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
    delete leftChild;
    delete rightChild;
}


// Copy and Move Assignment
template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node){
    leftChild = node.leftChild;
    rightChild = node.rightChild;
    key = node.key;
}


template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept{
    std::swap(leftChild. node.leftChild);
    std::swap(rightChild, node.rightChild);
    std::swap(key, node.key);
}


// Specific member Functions (inherited from Node)
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk:: IsLeaf() const noexcept{
    return (leftChild == nullptr && rightChild == nullptr);
}


template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk:: HasLeftChild() const noexcept{
    return leftChild != nullptr;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk:: HasRightChild() const noexcept{
    return rightChild != nullptr;
}


template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::NodeLnk:: RightChild(){
    if(rightChild != nullptr)
        throw std::out_of_range("The node has no right child!\n");

    return rightChild;
}


template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::NodeLnk:: LeftChild(){
    if(leftChild != nullptr)
        throw std::out_of_range("The node has no left child!\n");

    return leftChild;
}


/* ************************************************************************** */
/* ************************************************************************** */

// Contructors
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& container){
    size = container.size;
    root = new NodeLnk(container[0]);

    for(ulong i = 0; i<containe.size;i++){

    }
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& container) noexcept{
    std::swap(size, tree.size);
    std::swap(root, tree.root);
}


// Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
    delete root;
}

/* ************************************************************************** */

//  Copy and Move Assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree){
    root = tree.root;
    size = tree.size;
}


template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree) noexcept{
    std::swap(size, tree.size);
    std::swap(root, tree.root);
}


/* ************************************************************************** */

//  Specific Member Functions
template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>:: Root(){
    if(size == 0)
        throw std::length_error("The tree is empty!\n");

    return root;
}

//  Specific Member Functions
template <typename Data>
void BinaryTreeLnk<Data>:: Clear(){
    size = 0;

    delete root;
    root = nullptr;
}

}
