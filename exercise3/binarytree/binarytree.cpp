
// #include ".../iterator.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
    if(key == key)
        if(HasLeftChild() == node.HasLeftChild())
            if(!HasLeftChild() || LeftChild() == node.LeftChild())
                if(HasRightChild() == node.HasRightChild())
                    if(!HasRightChild() || RightChild() == node.RightChild())
                        return true;            
return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
    return !(*this == node);
}

template <typename Data>
Data& BinaryTree<Data>::Node::Element() noexcept{
    return key;
}

template <typename Data>
const Data& BinaryTree<Data>::Node::Element() const noexcept{
    return key;
}

/* ************************************************************************** */

 // Comparison operators

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept{
    return Root() == tree.Root();
}

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept{
    return !(Root() == tree.Root());
}


// Specific member functions (inherited from MappableContainer)
template <typename Data>
void BinaryTree<Data>::Map(MapFunctor function, void* value){
    MapBreadth(function, value);
}

// Specific member functions (inherited from PreOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor function, void* value){
    MapPreOrder(function, value, Root());
}

// Specific member functions (inherited from PostOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor function, void* value){
    MapPostOrder(function, value, Root());
}

// Specific member functions (inherited from InOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor function, void* value){
    MapInOrder(function, value, Root());
}

// Specific member functions (inherited from PreOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor function, const void* value, void* data) const{
    FoldPreOrder(function, value, Root());
}

// Specific member functions (inherited from PostOrerFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor function, const void* value, void* data) const{
    FoldPostOrder(function, value, Root());
}

// Specific member functions (inherited from InOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor function, const void* value, void* data) const{
    FoldInOrder(function, value, Root());
}

// Specific member functions (inherited from BreadthFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor function, const void* value, void* data) const{
    FoldBreadth(function, value, Root());
}


//Auxiliary member Functions for Map and Fold

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor function, void* value, Node* node){
    if(node!=nullptr){
        function(node.Element(), value);
        if(node.HasLeftChild())
            MapPreOrder(function, value, node.LeftChild());
        if(node.HasRightChild())
            MapPreOrder(function, value, node.RightChild());
    }

}

// Specific member functions (inherited from PostOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor function, void* value, Node* node){
    if(node!=nullptr){
        if(node.HasLeftChild())
            MapPostOrder(function, value, node.LeftChild());
        if(node.HasRightChild())
            MapPostOrder(function, value, node.RightChild());
        function(node.Element(), value);
    }

    
}

// Specific member functions (inherited from InOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor function, void* value, Node* node){
    if(node!=nullptr){
        if(node.HasLeftChild())
            MapPostOrder(function, value, node.LeftChild());
        
        function(node.Element(), value);

        if(node.HasRightChild())
            MapPostOrder(function, value, node.RightChild());   
    }

}

// Specific member functions (inherited from BreadthMappableContainer)
template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor function, void* value){
    BTBreadthIterator i(*this);

    for(;i.Terminated();i++)
        function(i->Element(), value);
}


// Specific member functions (inherited from PreOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor function, const void* value, void* data, Node* node) const{
    if(node!=nullptr){
        function(node.Element(), value);
        if(node.HasLeftChild())
            FoldPreOrder(function, value, node.LeftChild());
        if(node.HasRightChild())
            FoldPreOrder(function, value, node.RightChild());
    }

}

// Specific member functions (inherited from PostOrerFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor function, const void* value, void* data, Node* node) const{
    if(node!=nullptr){
        if(node.HasLeftChild())
            FoldPostOrder(function, value, node.LeftChild());
        if(node.HasRightChild())
            FoldPostOrder(function, value, node.RightChild());
        function(node.Element(), value);
    }
    
}

// Specific member functions (inherited from InOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor function, const void* value, void* data, Node* node) const{
    if(node!=nullptr){
        if(node.HasLeftChild())
            FoldInOrder(function, value, node.LeftChild());
        
        function(node.Element(), value);

        if(node.HasRightChild())
            FoldInOrder(function, value, node.RightChild());
    }

    
}

// Specific member functions (inherited from BreadthFoldableContainer)
template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor function, const void* value, void* data) const{
    BTBreadthIterator i(*this);

    for(;i.Terminated();i++)
        function(i->Element(), value);
} 




/* ************************************************************************** */






}
