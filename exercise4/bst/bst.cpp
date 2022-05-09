
namespace lasd {

/* ************************************************************************** */

// Specific Constructor

 template <typename Data>
 BST<Data>::BST(const LinearContainer<Data>& container){
     container.Sort();

     root = BuildTree(container, 0, conntainer.Size()-1);
     size = container.Size();
 }

//  Auxiliary Member Function

template <typename Data>
 struct BST<Data>::NodeLnk* BST<Data>:: BuildTree(const LinearContainer<Data>& container, ulong first, ulong last){
     NodeLnk* left = nullptr;
     NodeLnk* right = nullptr;
     ulong middle = (first+last)/2;

     if(last>first){
        NodeLnk* left = BuildTree(container, first, middle-1);
        NodeLnk* right = BuildTree(container, middle+1, last);
     }
     
     node = new NodeLnk*(container[middle], left, right); //Probabilmente devo aggiungere BST<Data> ...

     return node;
 }

/* ************************************************************************** */

// Copy and Move Assignment

 template <typename Data>
 BST<Data>& BST<Data>::operator=(const BST<Data>& tree){
   return BinaryTreeLnk<Data>::operator=(tree);
 }

 template <typename Data>
 BST<Data>& BST<Data>::operator=(BST<Data>&& tree) noexcept{
   return BinaryTreeLnk<Data>::operator=(std::move(tree));
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
 const Data& BST<Data>::Min() const{
    if(size==0)
        throw std::length_error("The tree is empty!\n");

    NodeLnk* current = root;

    while(current->HasLeftChild())
        current = &(current->LeftChild());

    return current->Element();
}


 template <typename Data>
 bool BST<Data>::Exists(const Data& data) const noexcept{
     NodeLnk* current = root;
     
     if current == nullptr
        return false;
     else
        while(current!=nullptr)
            if(current->Element()==data)
                return true;
            else
                if(current->Element()>data && current->HasLeftChild())
                    current = &(current->LeftChild())
                else
                    if(current->HasRightChild())
                        current = &(current->RightChild())
                    else
                        return false;
 }



 /* ************************************************************************** */

//  Auxiliary Member Function

template <typename Data>
 struct BST<Data>::NodeLnk* BST<Data>:: BuildTree(const LinearContainer<Data>& container, ulong first, ulong last){
     NodeLnk* left = nullptr;
     NodeLnk* right = nullptr;
     ulong middle = (first+last)/2;

     if(last>first){
        NodeLnk* left = BuildTree(container, first, middle-1);
        NodeLnk* right = BuildTree(container, middle+1, last);
     }
     
     node = new NodeLnk*(container[middle], left, right);

     return node;
 }


}
