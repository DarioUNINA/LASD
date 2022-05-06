#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../zlasdtest/test.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"


/* ************************************************************************ */

// Print option functions

void DataStructureChoose(ushort& choice){

    std::cout<<"Please Select any Binary Tree Implementation:\n";
    std::cout << "1) Using Vector\n";
    std::cout << "2) Using Pointers\n";
    std::cout << "3) Back \n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
}

void TypeChoose(ushort& choice){

    std::cout<<"Please Select any type for your Data Structure:\n";
    std::cout << "1) int\n";
    std::cout << "2) float\n";
    std::cout << "3) String \n";
    std::cout << "4) Back \n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
}

void OperationChoose(ushort& choice){

    std::cout <<"\nSelect any operation\n";
    std::cout << "1) Get the elements of the Binary Tree\n";
    std::cout << "2) Check Existence of any value\n";
    std::cout << "3) Apply Specific Type Fold Function\n";
    std::cout << "4) Apply Specific Type Map Function\n";
    std::cout << "5) Back\n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
}

void IOperationChoose(ushort& choice){

    std::cout <<"\nSelect any operation\n";
    std::cout << "1) Read Current Node\n";
    std::cout << "2) Update Current Node\n";
    std::cout << "3) Increment Iterator\n";
    std::cout << "4) Reset Iterator\n";
    std::cout << "4) Check Termination\n";
    std::cout << "5) Back\n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
}

/* ************************************************************************ */

// Auxiliary functions

int SetInt(){
    int v;
    std::cout<<"Please enter any integer value\n";

    std::cin>>v;
    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(INT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }

    std::cin.clear();
    const int value = v;
    return value; 
}


float SetFloat(){
    float v;
    std::cout<<"\nPlease enter any Float value\n";

    std::cin>>v;
    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore('\n'); 
        std::cout<< "Invalid input! Please enter a vaild number \n";
    }

    const float value = v;
    return value; 
}


ulong SetLenght(){
    ulong n;

    std::cout << "Please insert any size value\n";
    std::cin >> n;

    while (std::cin.fail() || n > USHRT_MAX){
                    std::cin.clear(); 
                    std::cin.ignore('\n'); 
                    std::cout << "Please insert any size value:\n";
                    std::cin >> n;
    }

    std::cin.clear(); 
    const ulong lenght = n;
    return lenght;
}


void OrderChoice(uint& choice){
    std::cout<<"Select any order:\n";
    std::cout<<"1)Pre Order\n";
    std::cout<<"2)In order:\n";
    std::cout<<"3)Post order\n";
    std::cout<<"4)Breadth\n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
}

template <typename Data>
void MapPrint(const Data& key, void* value){
    std::cout << key << ", ";
}

template <typename Data>
void Print(uint& choice, lasd::BinaryTree<Data>& tree){
    std::cout<<"The elements are:\n";

    switch(choice){

    case 1:{
        tree.MapPreOrder(MapPrint<Data>, 0);

        break;}

    case 2:{
        tree.MapInOrder(MapPrint<Data>, 0);
        break;}

    case 3:{
        tree.MapPostOrder(MapPrint<Data>, 0);
        break;}

    case 4:{
        tree.MapBreadth(MapPrint<Data>, 0);
        break;}
   
    default:
        break;    
    }
}


/* ************************************************************************ */

// Random values generators

int getRandomInt(){
  std::default_random_engine genx(std::random_device{}());
  std::uniform_int_distribution<int> distx(-1000, 1000);
  return distx(genx);
}

float getRandomFloat(){
  return static_cast<float>(getRandomInt())/100;
}

std::string getRandomString(){
  
  std::string randomString;
  std::string litterals = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

  std::default_random_engine genx(std::random_device{}());
  std::uniform_int_distribution<int> distx(0, litterals.length()-1);
  
  int limit = distx(genx);
    
  for (int i = 0; i<limit; i++)
    randomString = randomString + litterals.at(distx(genx));
  
  return randomString;
}


/* ************************************************************************ */

// Filling Data Structure functions

void IntFill(lasd::Vector<int>& vector){
    for(ulong i = 0; i<vector.Size(); i++)
        vector[i] = getRandomInt();
}

void FloatFill(lasd::Vector<float>& vector){
    for(ulong i = 0; i<vector.Size(); i++)
        vector[i] = getRandomFloat();
}


void StringFill(lasd::Vector<std::string>& vector){
    for(ulong i = 0; i<vector.Size(); i++)
        vector[i] = getRandomString();
}


/* ************************************************************************ */

// Specific Fold functions and Auxliary functions

void FoldFunctInt(const int& key, const void* value, void* result){
    if(key < *(static_cast<const int*>(value)))
        *((int*)result) *= key;
}


void FoldFunctFloat(const float& key, const void* value, void* result){
    if(key > *(static_cast<const float*>(value)))
        *(static_cast<float*>(result)) += key;
}


void FoldFunctString(const std::string& key, const void* value, void* result){
    if(key.length() <= *(static_cast<const int*>(value)))
        *(static_cast<std::string*>(result)) += key;
}



void Fold(lasd::FoldableContainer<float>& container){
    float v;
    std::cout<<"Please insert any value";
    std::cin>>v;

    const void* value = &v;

    float r = 0;
    void* result = &r;

    container.Fold(FoldFunctFloat, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<const float*>(result))<<"\n";
}


void Fold(lasd::FoldableContainer<std::string>& container){
    int v;
    std::cout<<"Please insert any lenght value\n";
    std::cin>>v;

    const void* value = &v;

    std::string r = "";
    void* result = &r;

    container.Fold(FoldFunctString, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<std::string*>(result))<<"\n";
}


void Fold(lasd::FoldableContainer<int>& container){
    int v;
    std::cout<<"Please insert any value";
    std::cin>>v;

    const void* value = &v;

    int r = 1;
    void* result = &r;

    container.Fold(FoldFunctInt, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<const int*>(result))<<"\n";
}


/* ************************************************************************ */

// Specific Map functions and Auxliary functions

void MapFunctInt(int& key, void* value){
    key = key*(*(static_cast<const int*>(value)));
}


void MapFunctFloat(float& key, void* value){
    key = static_cast<float>(std::pow(key, (*(static_cast<const float*>(value)))));
}


void MapFunctString(std::string& key, void* value){
    key = *(static_cast<std::string*>(value)) + key;
}



void Map(lasd::BinaryTree<int>& tree){
    int v = 3;
    void* value = &v;
    tree.Map(MapFunctInt, value);
}


void Map(lasd::BinaryTree<float>& tree){
    float v = 3;
    void* value = &v;
    tree.Map(MapFunctFloat, value);
}


void Map(lasd::BinaryTree<std::string>& tree){
    std::string v;
    std::cout<<"Please do enter any string:\n";
    std::cin>>v;

    void* value = &v;
    tree.Map(MapFunctString, value);
}


/* ************************************************************************ */

bool CheckExistence(lasd::BinaryTree<int>& tree){
    int v = SetInt();
    return tree.Exists(v);
}


bool CheckExistence(lasd::BinaryTree<float>& tree){
    float v = SetFloat();
    return tree.Exists(v);
}


bool CheckExistence(lasd::BinaryTree<std::string>& tree){
    std::string v;
    std::cout<<"Please do enter any string:\n";
    std::cin>>v;
    return tree.Exists(v);
}


/* ************************************************************************ */


// Test

template <typename Data>
void Iterator(lasd::BinaryTree<Data>& tree){
    uint choice;

    try{
            OrderChoice(choice);

            switch(choice){

                case 1:{
                    lasd::BTPreOrderIterator<Data> iterator(tree);

                    Test(iterator)
                    break;}

                case 2:{
                    lasd::BTInOrderIterator<Data> iterator(tree);
                    Test(iterator)
                    break;}

                case 3:{
                    lasd::BTPostOrderIterator<Data> iterator(tree);
                    Test(iterator)
                    break;}

                case 4:{
                    lasd::BTBreadthIterator<Data> iterator(tree);
                    Test(iterator)
                    break;}
                
                default:
                    break;    
            }
    }catch(...){
        std::cout<<"ERROR: An exception was thrown!\n";
    }
}

template <typename Data>
void Test(lasd::BTPreOrderIterator<Data>& i){

}


template <typename Data>
void Test(lasd::BTInOrderIterator<Data>& i){

}


template <typename Data>
void Test(lasd::BTPostOrderIterator<Data>& i){

}


template <typename Data>
void Test(lasd::BTBreadthIterator<Data>& i){

}


template <typename Data>
void Test(lasd::BinaryTree<Data>& tree){

    bool exit = false;
    ushort choice;

    try{
        do{
            OperationChoose(choice);

            switch(choice){

                case 1:{
                    uint check;
                    OrderChoice(check);

                    Print(check, tree);
                    break;}

                case 2:{
                    if(CheckExistence(tree))
                        std::cout<<"The element is in the tree!\n";
                    else
                        std::cout<<"The element is not in the tree!\n";
                    break;}

                case 3:{
                    Fold(tree);
                    break;}

                case 4:{
                    Map(tree);
                    std::cout<<"Map Function applied!\n";
                    break;}
                
                case 5:{
                    // Node(tree.root);
                    break;}

                case 6:{
                    Iterator(tree);
                    break;}

                case 7:{
                    exit = true;
                    break;}

                default:
                    break;    
            }
        }while(!exit);
    }catch(...){
        std::cout<<"ERROR: An exception was thrown!\n";
    }
}


/* ************************************************************************ */

// Data Structure Initialization


void BTVec(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                const ulong lenght = SetLenght();
                lasd::Vector<int> vector(lenght);
                IntFill(vector);

                lasd::BinaryTreeVec<int> tree(vector);
                Test(tree);
                break;}
            
            case 2:{
                const ulong lenght = SetLenght();
                lasd::Vector<float> vector(lenght);
                FloatFill(vector);

                lasd::BinaryTreeVec<float> tree(vector);
                Test(tree);
                break;}

            case 3:{
                const ulong lenght = SetLenght();
                lasd::Vector<std::string> vector(lenght);
                StringFill(vector);

                lasd::BinaryTreeVec<std::string> tree(vector);
                Test(tree);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void BTLnk(){

    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);
       
        switch(choice){
            
            case 1:{
                const ulong lenght = SetLenght();
                lasd::Vector<int> vector(lenght);

                IntFill(vector);

                lasd::BinaryTreeLnk<int> tree(vector);

                Test(tree);
                break;}
            
            case 2:{
                const ulong lenght = SetLenght();
                lasd::Vector<float> vector(lenght);

                FloatFill(vector);

                lasd::BinaryTreeLnk<float> tree(vector);

                Test(tree);
                break;}

            case 3:{
                const ulong lenght = SetLenght();
                lasd::Vector<std::string> vector(lenght);

                StringFill(vector);

                lasd::BinaryTreeLnk<std::string> tree(vector);

                Test(tree);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}



/* ************************************************************************ */

// Main Menu

void myTest(){

    bool exit = false;
    ushort choice;
    
    do{
        DataStructureChoose(choice);

        switch(choice){
            case 1:{
                BTVec();
                break;}
                
            case 2:{
                BTLnk();
                break;}

            case 3:{
                exit = true;
                break;}

            default:
                break;
        }
    }while(!exit);
}

void Menu(){

    bool exit = false;
    ushort choice;

    do{

        std::cout<<"\tWelcome to the Menu!\nWhat do you want to run?\n";
        std::cout<<"0) LASD Test Suite\n";
        std::cout<<"1) Data Structure Test\n";
        std::cout<<"2) Exit\n";
    
        std::cin>>choice;
        
        switch(choice){
            case 0:{
                lasdtest();
                break;}
                
            case 1:{
                myTest();
                break;}

            case 2:{
                std::cout<<"GoodBye!\n";
                exit = true;
                break;}

            default:
                break;
        }
    }while(!exit);
}