#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../zlasdtest/test.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************ */

// Print option functions

void ImplementationChoose(ushort& choice){

    std::cout<<"Please Select any implementation  for your Hash Map:\n";
    std::cout << "1) Closed Addressing\n";
    std::cout << "2) Open Addressing\n";
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
    std::cout << "2) double\n";
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
    std::cout << "1) Get the elements of the Hash Map\n";
    std::cout << "2) Check Existence of any value\n";
    std::cout << "3) Insert new Element\n";
    std::cout << "4) Remove any Element\n";
    std::cout << "5) Apply Specific Type Fold Function\n";
    std::cout << "6) Resize the Hash Map\n";
    std::cout << "7) Clear the Table\n";
    std::cout << "8) Get the number of elements in the Table\n";
    std::cout << "9) Back\n";

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


double SetFloat(){
    double v;
    std::cout<<"\nPlease enter any Float value\n";

    std::cin>>v;
    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore('\n'); 
        std::cout<< "Invalid input! Please enter a vaild number \n";
    }

    const double value = v;
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


int setValue(lasd::HashTable<int>& table){
    return SetInt();
}


double setValue(lasd::HashTable<double>& table){
    return SetFloat();
}


std::string setValue(lasd::HashTable<std::string>& table){
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


double getRandomFloat(){
  return static_cast<double>(getRandomInt())/100;
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


void FloatFill(lasd::Vector<double>& vector){
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


void FoldFunctFloat(const double& key, const void* value, void* result){
    if(key > *(static_cast<const double*>(value)))
        *(static_cast<double*>(result)) += key;
}


void FoldFunctString(const std::string& key, const void* value, void* result){
    if(key.length() <= *(static_cast<const int*>(value)))
        *(static_cast<std::string*>(result)) += key;
}



void Fold(lasd::FoldableContainer<double>& container){
    double v;
    std::cout<<"Please insert any value\n";
    std::cin>>v;

    const void* value = &v;

    double r = 0;
    void* result = &r;

    container.Fold(FoldFunctFloat, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<const double*>(result))<<"\n";
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

bool CheckExistence(lasd::HashTable<int>& table){
    return table.Exists(SetInt());
}


bool CheckExistence(lasd::HashTable<double>& table){
    return table.Exists(SetFloat());
}


bool CheckExistence(lasd::HashTable<std::string>& table){
    std::string v;
    std::cout<<"Please do enter any string:\n";
    std::cin>>v;
    return table.Exists(v);
}


/* ************************************************************************ */

// Test

template <typename Data>
void Test(lasd::HashTable<Data>& table){
    bool exit = false;
    ushort choice;

    try{
        do{
            OperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The elements of the Hash Table are :\n";
                    table.Map(MapPrint<Data>, 0);
                    break;}

                case 2:{
                    if(CheckExistence(table))
                        std::cout<<"The element is in the Hash table!\n";
                    else
                        std::cout<<"The element is not in the Hash table!\n";
                    break;}

                case 3:{
                    if(table.Insert(setValue(table)))
                        std::cout<<"Insert completed!\n";
                    else
                        std::cout<<"The element is already in the Hash Table!\n";
                    break;}

                case 4:{
                    if(table.Remove(setValue(table)))
                        std::cout<<"Element removed!\n";
                    else
                        std::cout<<"The element is not in the Hash Table!\n";
                    break;}

                case 5:{
                    Fold(table);
                    break;}

                case 6:{
                        table.Resize(SetInt());
                        std::cout<<"Table resized!\n";
                    break;}

                case 7:{
                        table.Clear();
                        std::cout<<"Table cleared!\n";
                    break;}

                case 8:{
                        std::cout<<"There are "<<table.Size()<<" elements in the Hash table!";
                    break;}

                case 9:{
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

void OpnAdr(){
bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                const ulong lenght = SetLenght();
                lasd::Vector<int> vector(lenght);
                IntFill(vector);

                lasd::HashTableOpnAdr<int> table((vector.Size())/2, vector);
                Test(table);
                break;}
            
            case 2:{
                const ulong lenght = SetLenght();
                lasd::Vector<double> vector(lenght);
                FloatFill(vector);

                lasd::HashTableOpnAdr<double> table((vector.Size())/2,vector);
                Test(table);
                break;}

            case 3:{
                const ulong lenght = SetLenght();
                lasd::Vector<std::string> vector(lenght);
                StringFill(vector);

                lasd::HashTableOpnAdr<std::string> table((vector.Size())/2,vector);
                Test(table);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void ClsAdr(){
bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                const ulong lenght = SetLenght();
                lasd::Vector<int> vector(lenght);
                IntFill(vector);

                lasd::HashTableClsAdr<int> table((vector.Size())/2, vector);
                Test(table);
                break;}
            
            case 2:{
                const ulong lenght = SetLenght();
                lasd::Vector<double> vector(lenght);
                FloatFill(vector);

                lasd::HashTableClsAdr<double> table((vector.Size())/2, vector);
                Test(table);
                break;}

            case 3:{
                const ulong lenght = SetLenght();
                lasd::Vector<std::string> vector(lenght);
                StringFill(vector);

                lasd::HashTableClsAdr<std::string> table((vector.Size())/2, vector);
                Test(table);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void HashTable(){
    bool exit = false;
    ushort choice;

    do{
        ImplementationChoose(choice);

        switch(choice){
            
            case 1:{
                ClsAdr();
                break;}
            
            case 2:{
                OpnAdr();
                break;}

            case 3:{
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
                HashTable();
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
