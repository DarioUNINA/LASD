#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../zlasdtest/test.hpp"
#include "../bst/bst.hpp"


/* ************************************************************************ */

// Print option functions


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
    std::cout << "4) Iterator Menu\n";
    std::cout << "5) Insert new Element\n";
    std::cout << "6) Remove any Element\n";
    std::cout << "7) Get Minimum\n";
    std::cout << "8) Get Maximum\n";
    std::cout << "9) Remove Minimum\n";
    std::cout << "10) Read and Remove Minimum\n";
    std::cout << "11) Remove Maximum\n";
    std::cout << "12) Read and Remove Maximum\n";
    std::cout << "13) Get Predecessor of a given Value\n";
    std::cout << "14) Remove Predecessor of a given Value\n";
    std::cout << "15) Read and Remove Predecessor of a given Value\n";
    std::cout << "16) Get Successor of a given Value\n";
    std::cout << "17) Remove Successor of a given Value\n";
    std::cout << "18) Read and Remove Successor of a given Value\n";
    std::cout << "19) Back\n";

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
    std::cout << "2) Increment Iterator\n";
    std::cout << "3) Reset Iterator\n";
    std::cout << "4) Check Termination\n";
    std::cout << "5) Back\n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
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


template <typename Data>
void MapPrint(const Data& key, void* value){
    std::cout << key << ", ";
}


template <typename Data>
void Print(uint& choice, lasd::BST<Data>& bst){
    std::cout<<"The elements are:\n";

    switch(choice){

    case 1:{
        bst.MapPreOrder(MapPrint<Data>, 0);

        break;}

    case 2:{
        bst.MapInOrder(MapPrint<Data>, 0);
        break;}

    case 3:{
        bst.MapPostOrder(MapPrint<Data>, 0);
        break;}

    case 4:{
        bst.MapBreadth(MapPrint<Data>, 0);
        break;}
   
    default:
        break;    
    }
}


int setValue(lasd::BST<int>& bst){
    return SetInt();
}


float setValue(lasd::BST<float>& bst){
    return SetFloat();
}


std::string setValue(lasd::BST<std::string>& bst){
    std::cout<<"Please insert any string\n";
    std::string s;

    std::cin>>s;
    return s;
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
    std::cout<<"Please insert any value\n";
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
    std::cout<<"Please insert any value\n";
    std::cin>>v;

    const void* value = &v;

    int r = 1;
    void* result = &r;

    container.Fold(FoldFunctInt, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<const int*>(result))<<"\n";
}


/* ************************************************************************ */

bool CheckExistence(lasd::BST<int>& bst){
    return bst.Exists(SetInt());
}


bool CheckExistence(lasd::BST<float>& bst){
    return bst.Exists(SetFloat());
}


bool CheckExistence(lasd::BST<std::string>& bst){
    std::string v;
    std::cout<<"Please do enter any string:\n";
    std::cin>>v;
    return bst.Exists(v);
}


/* ************************************************************************ */

// Test

template <typename Data>
void Test(lasd::Iterator<Data>& i){
bool exit = false;
    ushort choice;

    do{
        try{
            IOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"Current element is "<<*i<<"\n";
                    break;}

                case 2:{
                    ++(dynamic_cast<lasd::ForwardIterator<Data>&>(i));
                    std::cout<<"Iterator incremented!\n";
                    break;}

                case 3:{
                    (dynamic_cast<lasd::ResettableIterator<Data>&>(i)).Reset();
                    std::cout<<"Iterator Resetted!\n";
                    break;}
                
                case 4:{
                    if(i.Terminated())
                        std::cout<<"The visit has terminated!\n";
                    else
                        std::cout<<"The visit has not terminated!\n";
                    break;}

                case 5:{
                    exit = true;
                    break;}

                default:
                    break;    
            }
        }catch(...){
            std::cout<<"ERROR: The visit is over!\n";
        }
    }while(!exit);
}


template <typename Data>
void Iterator(lasd::BST<Data>& bst){
    uint choice;

    try{
            OrderChoice(choice);

            switch(choice){

                case 1:{
                    lasd::BTPreOrderIterator<Data> iterator(bst);
                    Test(iterator);
                    break;}

                case 2:{
                    lasd::BTInOrderIterator<Data> iterator(bst);
                    Test(iterator);
                    break;}

                case 3:{
                    lasd::BTPostOrderIterator<Data> iterator(bst);
                    Test(iterator);
                    break;}

                case 4:{
                    lasd::BTBreadthIterator<Data> iterator(bst);
                    Test(iterator);
                    break;}
                
                default:
                    break;    
            }
    }catch(...){
        std::cout<<"ERROR: An exception was thrown!\n";
    }
}


template <typename Data>
void Test(lasd::BST<Data>& bst){
    bool exit = false;
    ushort choice;

    try{
        do{
            OperationChoose(choice);

            switch(choice){

                case 1:{
                    uint check;
                    OrderChoice(check);

                    Print(check, bst);
                    break;}

                case 2:{
                    if(CheckExistence(bst))
                        std::cout<<"The element is in the bst!\n";
                    else
                        std::cout<<"The element is not in the bst!\n";
                    break;}

                case 3:{
                    Fold(bst);
                    break;}

                case 4:{
                    Iterator(bst);
                    break;}
                
                case 5:{
                    if(bst.Insert(setValue(bst)))
                        std::cout<<"Insert completed!\n";
                    else
                        std::cout<<"The element is already in the BST!\n";
                    break;}

                case 6:{
                    if(bst.Remove(setValue(bst)))
                        std::cout<<"Element removed!\n";
                    else
                        std::cout<<"The element is not in the BST!\n";
                    break;}

                case 7:{
                    try{
                        std::cout<<"The minimum of the tree is "<<bst.Min();
                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;}

                case 8:{
                    try{
                        std::cout<<"The maximum of the tree is "<<bst.Max();
                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;}

                case 9:{
                    try{
                        bst.RemoveMin();
                        std::cout<<"The minimum of the tree has been removed!\n";

                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;}

                case 10:{
                    try{
                        std::cout<<"The minimum of the tree was "<< bst.MinNRemove()<<" and has been removed!\n";
                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;}                    

                case 11:{
                    try{
                        bst.RemoveMax();
                        std::cout<<"The maximum of the tree has been removed!\n";
                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;}

                case 12:{
                    try{
                        std::cout<<"The maximum of the tree was "<< bst.MaxNRemove()<<" and has been removed!\n";
                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;} 

                case 13:{
                    try{
                        Data data = bst.Predecessor(setValue(bst));
                        std::cout<<"The predecessor of the given value in the bst is "<<data;
                    }catch(std::length_error e){
                            std::cout<<e.what();
                    }
                    break;}

                case 14:{
                    try{
                        bst.RemovePredecessor(setValue(bst));
                        std::cout<<"The predecessor of the given value has been removed!";
                    }catch(std::length_error e){
                            std::cout<<e.what();
                    }
                    break;} 

                case 15:{
                        try{
                            Data data = bst.PredecessorNRemove(setValue(bst));
                            std::cout<<"The predecessor of the given value  was "<<data<<" and it has been removed!\n"; 
                        }catch(std::length_error e){
                            std::cout<<e.what();
                        }
                    break;}

                case 16:{
                    try{
                        Data data = bst.Successor(setValue(bst));
                        std::cout<<"The successor of the given value in the bst is "<<data; 
                    }catch(...){
                        std::cout<<"There is no successor of the given value in the bst!\n";
                    }
                    break;}

                case 17:{
                    try{
                        bst.RemoveSuccessor(setValue(bst));
                        std::cout<<"The successor of the given value has been removed!";
                    }catch(...){
                        std::cout<<"There is no successor of the given value in the bst!\n";
                    }
                    break;} 

                case 18:{
                    try{
                        Data data = bst.SuccessorNRemove(setValue(bst));
                        std::cout<<"The successor of the given value  was "<<data<<" and it has been removed!\n"; 
                    }catch(std::length_error e){
                        std::cout<<e.what();
                    }
                    break;}                    

                case 19:{
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

void BST(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                const ulong lenght = SetLenght();
                lasd::Vector<int> vector(lenght);
                IntFill(vector);

                lasd::BST<int> bst(vector);
                Test(bst);
                break;}
            
            case 2:{
                const ulong lenght = SetLenght();
                lasd::Vector<float> vector(lenght);
                FloatFill(vector);

                lasd::BST<float> bst(vector);
                Test(bst);
                break;}

            case 3:{
                const ulong lenght = SetLenght();
                lasd::Vector<std::string> vector(lenght);
                StringFill(vector);

                lasd::BST<std::string> bst(vector);
                Test(bst);
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
                BST();
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