#include <iostream>
#include <string>
#include <climits>
#include <random>

#include "../zlasdtest/test.hpp"
#include "../container/container.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

/* ************************************************************************ */

// Print option functions

void DataStructureChoose(ushort& choice){

    std::cout<<"Please Select any Data Structure:\n";
    std::cout << "1) Vector\n";
    std::cout << "2) List\n";
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

void VecOperationChoose(ushort& choice){

    std::cout <<"\nSelect any operation\n";
    std::cout << "1) Get first element of the Vector\n";
    std::cout << "2) Get last element of the Vector\n";
    std::cout << "3) Get element at a given index of the Vector\n";
    std::cout << "4) Get all elements of the Vector\n";
    std::cout << "5) Check existance of a value\n";
    std::cout << "6) Specific Fold\n";
    std::cout << "7) Specific Map\n";
    std::cout << "8) Resize\n";
    std::cout << "9) Back\n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retry\n";
    }
}

void ListOperationChoose(ushort& choice){

    std::cout <<"\nSelect any operation\n";
    std::cout << "1) Get first element of the List\n";
    std::cout << "2) Get last element of the List\n";
    std::cout << "3) Get element at a given index of the List\n";
    std::cout << "4) Get all elements of the List\n";
    std::cout << "5) Check existance of a value\n";
    std::cout << "6) Specific Fold\n";
    std::cout << "7) Specific Map\n";
    std::cout << "8) Insert at the Back of the list\n";
    std::cout << "9) Insert at the Front of the List\n";
    std::cout << "10) Remove the element at the Front of the List\n";
    std::cout << "11) Remove and read the element at the Front of the List\n";
    std::cout << "12) Back\n";

    std::cin>>choice;

    while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(USHRT_MAX, '\n'); 
        std::cout<< "Invalid input! Please retryn";
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

void SetIndex(ulong& index, const ulong& limit){

    std::cout << "Choose an index: ";
    std::cin >> index;

    while(index > limit){
        std::cout << "Invalid index, please retry.\n";
        std::cout << "Choose an index :\n";
        std::cin >> index;
    }
}

template <typename Data>
ulong Resize(lasd::Vector<Data>& vector){

    ulong size;
    std::cout<<"Please insert new lenght\n";
    std::cin>>size;

    while(size > ULONG_MAX){
        std::cout<<"Lenght error! The choosen value is too big, please choose another value \n";
        std::cin>>size;
    }

    const ulong newSize = size;
    vector.Resize(newSize);

    return newSize;
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

template <typename Data>
void IntFill(lasd::Vector<Data>& vector){
    for(ulong i = 0; i<vector.Size(); i++)
        vector[i] = getRandomInt();
}

template <typename Data>
void IntFill(lasd::List<Data>& list, const ulong& size){

    for(ulong i = 0; i<size; i++)
        list.InsertAtBack(getRandomInt());
}

template <typename Data>
void FloatFill(lasd::Vector<Data>& vector){
    for(ulong i = 0; i<vector.Size(); i++)
        vector[i] = getRandomFloat();
}

template <typename Data>
void FloatFill(lasd::List<Data>& list, const ulong& limit){
    for(ulong i = 0; i<limit; i++)
        list.InsertAtBack(getRandomFloat());
}

template <typename Data>
void StringFill(lasd::Vector<Data>& vector){
    for(ulong i = 0; i<vector.Size(); i++)
        vector[i] = getRandomString();
}

template <typename Data>
void StringFill(lasd::List<Data>& list, const ulong& lenght){
    for(ulong i = 0; i<lenght; i++)
        list.InsertAtBack(getRandomString());
}


/* ************************************************************************ */

// Fold functions and Auxliary functions

void FoldFunctInt(const int& key, const void* value, void* result){
    if(key < *(static_cast<const int*>(value)))
        *((int*)result) += key;
}

void FoldFunctFloat(const float& key, const void* value, void* result){
    if(key > *(static_cast<const float*>(value)))
        *(static_cast<float*>(result)) *= key;
}

void FoldFunctString(const std::string& key, const void* value, void* result){
    if(key.length() <= *(static_cast<const int*>(value)))
        *(static_cast<std::string*>(result)) += key;
}

template <typename Data>
void FoldInt(lasd::FoldableContainer<Data>& container){
    int v;
    std::cout<<"Please insert any value";
    std::cin>>v;

    const void* value = &v;

    int r = 0;
    void* result = &r;

    container.Fold(FoldFunctInt, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<const int*>(result))<<"\n";
}

template <typename Data>
void FoldFloat(lasd::FoldableContainer<Data>& container){
    float v;
    std::cout<<"Please insert any value";
    std::cin>>v;

    const void* value = &v;

    float r = 1;
    void* result = &r;

    container.Fold(FoldFunctFloat, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<const float*>(result))<<"\n";
}

template <typename Data>
void FoldString(lasd::FoldableContainer<Data>& container){
    int v;
    std::cout<<"Please insert any lenght value\n";
    std::cin>>v;

    const void* value = &v;

    std::string r = "";
    void* result = &r;

    container.Fold(FoldFunctString, value, result);
    std::cout<<"The result of the fold operation is: "<<*(static_cast<std::string*>(result))<<"\n";
}


/* ************************************************************************ */

// Specific Map functions

void MapFunctInt(int& key, void* value){
    key = key*(*(static_cast<const int*>(value)));
}

void MapFunctFloat(float& key, void* value){
    key = static_cast<float>(std::pow(key, (*(static_cast<const int*>(value)))));
}

void MapFunctString(std::string& key, void* value){
    for(ulong i = 0; i<key.length(); ++i)
        key[i] = std::toupper(key[i]);
}


/* ************************************************************************ */

// Print Function (using Map function)

void MapPrintInt(const int& key, void* value) {
  std::cout << key << ", ";
}

void MapPrintFloat(const float& key, void* value) {
  std::cout << key << ", ";
}

void MapPrintString(const std::string& key, void* value) {
  std::cout << key << ", ";
}

/* ************************************************************************ */

// Vector Tests

void IntTest(lasd::Vector<int>& vector){

    bool exit = false;
    ushort choice;

    try{
        do{
            VecOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The front element of the vector is "<<vector.Front()<<"\n";
                    break;}

                case 2:{
                    std::cout<<"The back element of the vector is "<<vector.Back()<<"\n";
                    break;}

                case 3:{
                    ulong index;
                    SetIndex(index, vector.Size()-1);
                    std::cout<<"The element at index "<<index<<" of the vector is: "<<vector[index]<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The elements of the vector are:\n";
                    vector.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}
                
                case 5:{
                    int value;
                    std::cout<<"Insert any value\n";
                    std::cin>>value;

                    if(vector.Exists(value))
                        std::cout<<"The element "<<value<<" is in the vector\n";
                    else
                        std::cout<<"The element "<<value<<" is not in the vector\n";
                    break;}

                case 6:{

                    FoldInt(vector);
                    break;}

                case 7:{
                    int v = 2;
                    void* value = &v;
                    vector.Map(MapFunctInt, value);
                    
                    std::cout<<"\nMap function applied!\nThe elements now are:\n";
                    vector.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}

                case 8:{
                    ulong oldSize = vector.Size();
                    
                    if(Resize(vector) > oldSize)
                        for(ulong i = oldSize; i<vector.Size(); ++i)
                            vector[i] = getRandomInt();

                    std::cout<<"Resize applied!\nThe vector now is:\n";
                    vector.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}
                
                case 9:
                    exit = true;
                    break;

                default:
                    break;    
            }
        }while(!exit);
    }catch(...){
        std::cout<<"ERROR: An exception was thrown!\n";
    }
}


void FloatTest(lasd::Vector<float>& vector){

    bool exit = false;
    ushort choice;

    try{
        do{
            VecOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The front element of the vector is "<<vector.Front()<<"\n";
                    break;}

                case 2:{
                    std::cout<<"The back element of the vector is "<<vector.Back()<<"\n";
                    break;}

                case 3:{
                    ulong index;
                    SetIndex(index, vector.Size()-1);
                    std::cout<<"The element at index "<<index<<" of the vector is: "<<vector[index]<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The elements of the vector are:\n";
                    vector.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}
                
                case 5:{
                    float value;
                    std::cout<<"Insert any value\n";
                    std::cin>>value;

                    if(vector.Exists(value))
                        std::cout<<"The element "<<value<<" is in the vector\n";
                    else
                        std::cout<<"The element "<<value<<" is not in the vector\n";
                    break;}

                case 6:{

                    FoldFloat(vector);
                    break;}

                case 7:{
                    int v = 2;
                    void* value = &v;
                    vector.Map(MapFunctFloat, value);
                    
                    std::cout<<"\nMap function applied!\nThe elements now are:\n";
                    vector.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}

                case 8:{
                    ulong oldSize = vector.Size();
                    
                    if(Resize(vector) > oldSize)
                        for(ulong i = oldSize; i<vector.Size(); ++i)
                            vector[i] = getRandomFloat();

                    std::cout<<"Resize applied!\nThe vector now is:\n";
                    vector.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}
                
                case 9:
                    exit = true;
                    break;

                default:
                    break;    
            }
        }while(!exit);
}catch(...){
    std::cout<<"ERROR: An exception was thrown!\n";
}

}


void StringTest(lasd::Vector<std::string>& vector){

    bool exit = false;
    ushort choice;

    try{
        do{
            VecOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The front element of the vector is "<<vector.Front()<<"\n";
                    break;}

                case 2:{
                    std::cout<<"The back element of the vector is "<<vector.Back()<<"\n";
                    break;}

                case 3:{
                    ulong index;
                    SetIndex(index, vector.Size()-1);
                    std::cout<<"The element at index "<<index<<" of the vector is: "<<vector[index]<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The elements of the vector are:\n";
                    vector.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}
                
                case 5:{
                    std::string value;
                    std::cout<<"Insert any string\n";
                    std::cin>>value;
                    const std::string stringa = value;

                    if(vector.Exists(stringa))
                        std::cout<<"The element "<<value<<" is in the vector\n";
                    else
                        std::cout<<"The element "<<value<<" is not in the vector\n";
                    break;}

                case 6:{

                    FoldString(vector);
                    break;}

                case 7:{
                    vector.Map(MapFunctString, 0);
                    
                    std::cout<<"\nMap function applied!\nThe elements now are:\n";
                    vector.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}

                case 8:{
                    ulong oldSize = vector.Size();
                    
                    if(Resize(vector) > oldSize)
                        for(ulong i = oldSize; i<vector.Size(); ++i)
                            vector[i] = getRandomString();

                    std::cout<<"Resize applied!\nThe vector now is:\n";
                    vector.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}
                
                case 9:
                    exit = true;
                    break;

                default:
                    break;    
            }
        }while(!exit);
    }catch(...){
        std::cout<<"\nERROR: An exception was thrown!";

    }
}

//List Tests

void IntTest(lasd::List<int>& list){

    bool exit = false;
    ushort choice;

    try{
        do{

            ListOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The front element of the lis is "<<list.Front()<<"\n";
                    break;}

                case 2:{
                    std::cout<<"The back element of the list is "<<list.Back()<<"\n";
                    break;}

                case 3:{
                    ulong index;
                    SetIndex(index, list.Size());
                    std::cout<<"The element at index "<<index<<" of the list is: "<<list[index]<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The elements of the list are:\n";
                    list.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}
                
                case 5:{
                    const int value = SetInt();

                    if(list.Exists(value))
                        std::cout<<"The element "<<value<<" is in the list\n";
                    else
                        std::cout<<"The element "<<value<<" is not in the list\n";
                    break;}

                case 6:{
                    FoldInt(list);
                    break;}

                case 7:{
                    int v = 2;
                    void* value = &v;
                    list.Map(MapFunctInt, value);
                    
                    std::cout<<"\nMap function applied!\nThe elements now are:\n";
                    list.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}

                case 8:{
                    const int value = SetInt();
                    list.InsertAtBack(value);

                    std::cout<<"\nValue added at the Back of the List!\nThe elements now are:\n";
                    list.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}
                
                case 9:{
                    const int value = SetInt();
                    list.InsertAtFront(value);

                    std::cout<<"\nValue added at the Front of the List!\nThe elements now are:\n";
                    list.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}

                case 10:{
                    list.RemoveFromFront();

                    std::cout<<"\nValue removed from the Front of the List!\nThe elements now are:\n";
                    list.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}
                
                case 11:{
                    const int value = list.FrontNRemove();

                    std::cout<<"The element remove from the front of the list is "<<value<<std::endl;
                    std::cout<<"The list now is:\n";
                    list.Map(MapPrintInt, 0);
                    std::cout << std::endl;
                    break;}

                case 12:
                    exit = true;
                    break;

                default:
                    break;    
            }
        }while(!exit);

    }catch(...){
        std::cout<<"\nERROR: An exception was thrown!";
    }
}


void FloatTest(lasd::List<float>& list){

    bool exit = false;
    ushort choice;

    try{
        do{

            ListOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The front element of the lis is "<<list.Front()<<"\n";
                    break;}

                case 2:{
                    std::cout<<"The back element of the list is "<<list.Back()<<"\n";
                    break;}

                case 3:{
                    ulong index;
                    SetIndex(index, list.Size());
                    std::cout<<"The element at index "<<index<<" of the list is: "<<list[index]<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The elements of the list are:\n";
                    list.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}
                
                case 5:{
                    const float value = SetFloat();

                    if(list.Exists(value))
                        std::cout<<"The element "<<value<<" is in the list\n";
                    else
                        std::cout<<"The element "<<value<<" is not in the list\n";
                    break;}

                case 6:{
                    FoldFloat(list);
                    break;}

                case 7:{
                    int v = 2;
                    void* value = &v;
                    list.Map(MapFunctFloat, value);
                    
                    std::cout<<"\nMap function applied!\nThe elements now are:\n";
                    list.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}

                case 8:{
                    const float value = SetFloat();
                    list.InsertAtBack(value);

                    std::cout<<"\nValue added at the Back of the List!\nThe elements now are:\n";
                    list.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}
                
                case 9:{
                    const float value = SetFloat();
                    list.InsertAtFront(value);

                    std::cout<<"\nValue added at the Front of the List!\nThe elements now are:\n";
                    list.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}

                case 10:{
                    list.RemoveFromFront();

                    std::cout<<"\nValue removed from the Front of the List!\nThe elements now are:\n";
                    list.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}
                
                case 11:{
                    const float value = list.FrontNRemove();

                    std::cout<<"The element remove from the front of the list is "<<value<<std::endl;
                    std::cout<<"The list now is:\n";
                    list.Map(MapPrintFloat, 0);
                    std::cout << std::endl;
                    break;}

                case 12:
                    exit = true;
                    break;

                default:
                    break;    
            }
        }while(!exit);
        
}catch(...){
    std::cout<<"\nERROR: An exception was thrown!";
    }
}


void StringTest(lasd::List<std::string>& list){

    bool exit = false;
    ushort choice;

    try{

        do{

            ListOperationChoose(choice);

            switch(choice){

                case 1:{
                    std::cout<<"The front element of the lis is "<<list.Front()<<"\n";
                    break;}

                case 2:{
                    std::cout<<"The back element of the list is "<<list.Back()<<"\n";
                    break;}

                case 3:{
                    ulong index;
                    SetIndex(index, list.Size());
                    std::cout<<"The element at index "<<index<<" of the list is: "<<list[index]<<"\n";
                    break;}

                case 4:{
                    std::cout<<"The elements of the list are:\n";
                    list.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}
                
                case 5:{
                    std::string value;
                    std::cout<<"Insert any string\n";
                    std::cin>>value;
                    const std::string stringa = value;

                    if(list.Exists(stringa))
                        std::cout<<"The element "<<value<<" is in the list\n";
                    else
                        std::cout<<"The element "<<value<<" is not in the list\n";
                    break;}

                case 6:{
                    FoldString(list);
                    break;}

                case 7:{
                    list.Map(MapFunctString,0);
                    
                    std::cout<<"\nMap function applied!\nThe elements now are:\n";
                    list.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}

                case 8:{
                    std::string value;
                    std::cout<<"Insert any string\n";
                    std::cin>>value;
                    const std::string stringa = value;

                    list.InsertAtBack(value);

                    std::cout<<"\nValue added at the Back of the List!\nThe elements now are:\n";
                    list.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}
                
                case 9:{
                    std::string value;
                    std::cout<<"Insert any string\n";
                    std::cin>>value;
                    const std::string stringa = value;

                    list.InsertAtFront(value);

                    std::cout<<"\nValue added at the Front of the List!\nThe elements now are:\n";
                    list.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}

                case 10:{
                    list.RemoveFromFront();

                    std::cout<<"\nValue removed from the Front of the List!\nThe elements now are:\n";
                    list.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}
                
                case 11:{
                    const std::string value = list.FrontNRemove();

                    std::cout<<"The element remove from the front of the list is "<<value<<std::endl;
                    std::cout<<"The list now is:\n";
                    list.Map(MapPrintString, 0);
                    std::cout << std::endl;
                    break;}

                case 12:
                    exit = true;
                    break;

                default:
                    break;    
            }
        }while(!exit);

    }catch(...){
        std::cout<<"\nERROR: An exception was thrown!";
    }
}

/* ************************************************************************ */

// Data Structure Initialization


void Vector(){
    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);

        switch(choice){
            
            case 1:{
                const ulong lenght = SetLenght();
                lasd::Vector<int> vector(lenght);

                IntFill(vector);
                IntTest(vector);
                break;}
            
            case 2:{
                const ulong lenght = SetLenght();
                lasd::Vector<float> vector(lenght);

                FloatFill(vector);
                FloatTest(vector);
                break;}

            case 3:{
                const ulong lenght = SetLenght();
                lasd::Vector<std::string> vector(lenght);

                StringFill(vector);
                StringTest(vector);
                break;}

            case 4:{
                exit = true;
                break;}

            default:
                break;            
        }
    }while(!exit);
}


void List(){

    bool exit = false;
    ushort choice;

    do{
        TypeChoose(choice);
       
        switch(choice){
            
            case 1:{
                
                lasd::List<int> list;

                const ulong lenght = SetLenght();
                IntFill(list, lenght);
                IntTest(list);
                break;}
            
            case 2:{
                lasd::List<float> list;

                const ulong lenght = SetLenght();
                FloatFill(list, lenght);
                FloatTest(list);
                break;}

            case 3:{
                lasd::List<std::string> list;

                const ulong lenght = SetLenght();
                StringFill(list, lenght);
                StringTest(list);
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
                Vector();
                break;}
                
            case 2:{
                List();
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