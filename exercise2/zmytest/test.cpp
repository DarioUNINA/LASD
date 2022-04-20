#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../zlasdtest/test.hpp"
#include "../container/container.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"


/* ************************************************************************ */

// Print option functions

void DataStructureChoose(ushort& choice){

    std::cout<<"Please Select any Data Structure:\n";
    std::cout << "1) Stack (List)\n";
    std::cout << "2) Stack (Vector)\n";
    std::cout << "3) Queue (List)\n";
    std::cout << "4) Queue (Vector)\n";
    std::cout << "5) Back \n";

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
    std::cout << "1) Add new element\n";
    std::cout << "2) Remove Element\n";
    std::cout << "3) Remove and Read Element\n";
    std::cout << "4) Read Element\n";
    std::cout << "5) Emptiness Test\n";
    std::cout << "6) Size of the DS\n";
    std::cout << "7) Clear of the DF\n";
    std::cout << "8) Back\n";

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

void Fill(lasd::Stack<int>& stack){
    const ulong lenght = SetLenght();

    for(ulong i = 0; i<lenght; i++)
        stack.Push(getRandomInt());
}

void Fill(lasd::Queue<int>& queue){
    const ulong lenght = SetLenght();

    for(ulong i = 0; i<lenght; i++)
       queue.Enqueue(getRandomInt());
}

void Fill(lasd::Stack<float>& stack){
    const ulong lenght = SetLenght();

    for(ulong i = 0; i<lenght; i++)
        stack.Push(getRandomFloat());
}

void Fill(lasd::Queue<float>& queue){
    const ulong lenght = SetLenght();

    for(ulong i = 0; i<lenght; i++)
        queue.Enqueue(getRandomFloat());
}

void Fill(lasd::Stack<std::string>& stack){
    const ulong lenght = SetLenght();

    for(ulong i = 0; i<lenght; i++)
        stack.Push(getRandomString());
}

void Fill(lasd::Queue<std::string>& queue){
    const ulong lenght = SetLenght();

    for(ulong i = 0; i<lenght; i++)
        queue.Enqueue(getRandomString());
}


/* ************************************************************************ */

// Specific Insert Auxiliary FUnctions

void Insert(lasd::Stack<int>& stack){
    stack.Push(SetInt());
}

void Insert(lasd::Stack<float>& stack){
    stack.Push(SetFloat());
}

void Insert(lasd::Stack<std::string>& stack){
    std::string value;
    std::cout<<"Please choose any string to Push\n";
    std::cin>>value;
    stack.Push(value);
}

void Insert(lasd::Queue<int>& queue){
    queue.Enqueue(SetInt());
}

void Insert(lasd::Queue<float>& queue){
    queue.Enqueue(SetFloat());
}

void Insert(lasd::Queue<std::string>& queue){
    std::string value;
    std::cout<<"Please choose any string to Enqueue\n";
    std::cin>>value;
    queue.Enqueue(value);
}


/* ************************************************************************ */

// Tests

template <typename Data>
void StackTest(lasd::Stack<Data>& stack){

    bool exit = false;
    ushort choice;

    try{
        do{
            OperationChoose(choice);

            switch(choice){

                case 1:{
                    Insert(stack);
                    std::cout<<"Element Pushed!\n";
                    break;}

                case 2:{
                    stack.Pop();
                    std::cout<<"Element Removed!\n";
                    break;}

                case 3:{
                    std::cout<<"The element removed is "<<stack.TopNPop()<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The Top of the stack is "<<stack.Top()<<"\n";
                    break;}
                
                case 5:{
                    if(stack.Empty())
                        std::cout<<"The stack is Empty!\n";
                    else
                        std::cout<<"The stack is not Empty!\n";
                    break;}

                case 6:{
                    std::cout<<"The stack has "<<stack.Size()<<" elements!\n";
                    break;}

                case 7:{
                    stack.Clear();
                    std::cout<<"The stack has been Cleared!\n";
                    break;}

                case 8:{
                    exit = true;
                    break;}
                
                default:
                    break;    
            }
        }while(!exit);
    }catch(...){
        std::cout<<"\nERROR: An exception was thrown!\n";

    }
}

template <typename Data>
void QueueTest(lasd::Queue<Data>& queue){

    bool exit = false;
    ushort choice;

    try{
        do{
            OperationChoose(choice);

            switch(choice){

                case 1:{
                    Insert(queue);
                    std::cout<<"Element Pushed!\n";
                    break;}

                case 2:{
                    queue.Dequeue();
                    std::cout<<"Element Removed!\n";
                    break;}

                case 3:{
                    std::cout<<"The element removed is "<<queue.HeadNDequeue()<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The Head of the queue is "<<queue.Head()<<"\n";
                    break;}
                
                case 5:{
                    if(queue.Empty())
                        std::cout<<"The queue is Empty!\n";
                    else
                        std::cout<<"The queue is not Empty!\n";
                    break;}

                case 6:{
                    std::cout<<"The queue has "<<queue.Size()<<" elements!\n";
                    break;}

                case 7:{
                    queue.Clear();
                    std::cout<<"The queue has been Cleared!\n";
                    break;}

                case 8:{
                    exit = true;
                    break;}
                
                default:
                    break;    
            }
        }while(!exit);
    }catch(...){
        std::cout<<"\nERROR: An exception was thrown!\n";

    }
}

/* ************************************************************************ */

// Data Structure Initialization

void StackVec(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                lasd::StackVec<int> stack;

                Fill(stack);
                StackTest(stack);
                break;}
            
            case 2:{
                lasd::StackVec<float> stack;

                Fill(stack);
                StackTest(stack);
                break;}

            case 3:{
                lasd::StackVec<std::string> stack;

                Fill(stack);
                StackTest(stack);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void StackLst(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                lasd::StackLst<int> stack;

                Fill(stack);
                StackTest(stack);
                break;}
            
            case 2:{
                lasd::StackLst<float> stack;

                Fill(stack);
                StackTest(stack);
                break;}

            case 3:{
                lasd::StackLst<std::string> stack;

                Fill(stack);
                StackTest(stack);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void QueueVec(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                lasd::QueueVec<int> queue;

                Fill(queue);
                QueueTest(queue);
                break;}
            
            case 2:{
                lasd::QueueVec<float> queue;

                Fill(queue);
                QueueTest(queue);
                break;}

            case 3:{
                lasd::QueueVec<std::string> queue;

                Fill(queue);
                QueueTest(queue);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void QueueLst(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                lasd::QueueLst<int> queue;

                Fill(queue);
                QueueTest(queue);
                break;}
            
            case 2:{
                lasd::QueueLst<float> queue;

                Fill(queue);
                QueueTest(queue);
                break;}

            case 3:{
                lasd::QueueLst<std::string> queue;

                Fill(queue);
                QueueTest(queue);
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
                StackLst();
                break;}
                
            case 2:{
                StackVec();
                break;}
            
            case 3:{
                QueueLst();
                break;}

            case 4:{
                QueueVec();
                break;}

            case 5:{
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
lol
/* ************************************************************************ */
