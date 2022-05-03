
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
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node){ // Da modificare
    delete leftChild;
    delete rightChild;

    leftChild = node.leftChild;
    rightChild = node.rightChild;
    key = node.key;

    return *this;
}


template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept{
    std::swap(leftChild. node.leftChild);
    std::swap(rightChild, node.rightChild);
    std::swap(key, node.key);

    return *this;
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
struct BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk:: RightChild(){
    if(rightChild == nullptr)
        throw std::out_of_range("The node has no right child!\n");

    return *rightChild;
}


template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk:: LeftChild(){
    if(leftChild == nullptr)
        throw std::out_of_range("The node has no left child!\n");

    return *leftChild;
}

template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk:: RightChild() const{
    if(rightChild == nullptr)
        throw std::out_of_range("The node has no right child!\n");

    return *rightChild;
}


template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk:: LeftChild() const{
    if(leftChild == nullptr)
        throw std::out_of_range("The node has no left child!\n");

    return *leftChild;
}


/* ************************************************************************** */
/* ************************************************************************** */

// Contructors
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& container){
    size = container.Size();

    if(size != 0)
        root = BuildTree(container, 0);
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& tree){
    size = tree.size;

    if(size != 0)
        root = CopyTree(tree.Root());
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& tree) noexcept{
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
    BinaryTreeLnk<Data>* temp = new BinaryTreeLnk<Data>(tree);

    std::swap(*this, *temp);
    delete temp;

    return *this;
}


template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree) noexcept{
    std::swap(size, tree.size);
    std::swap(root, tree.root);

    return *this;
}


/* ************************************************************************** */

//  Specific Member Functions
template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeLnk<Data>:: Root() const{
    if(size == 0)
        throw std::length_error("The tree is empty!\n");

    return *root;
}

//  Specific Member Functions
template <typename Data>
void BinaryTreeLnk<Data>:: Clear(){
    size = 0;
    
    delete root;
    root = nullptr;
}

/* ************************************************************************** */

// Auxiliary member function
template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::BuildTree(const LinearContainer<Data>& container, const ulong index) const{

    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    if((2*index)+1 < container.Size())
        left = BuildTree(container, (2*index)+1);

    if(2*(index+1) < container.Size())
        right = BuildTree(container, 2*(index+1));
    
    NodeLnk* node = new NodeLnk(container[index], left, right);
    return node;
}


template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopyTree(const struct BinaryTree<Data>::Node& node) const{

    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    if(node.HasRightChild())
        right = CopyTree(node.RightChild());

    if(node.HasLeftChild())
        left = CopyTree(node.LeftChild());
    
    NodeLnk* newNode = new NodeLnk(node.Element(), left, right);
    return newNode;
}


}
