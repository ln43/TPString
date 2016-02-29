// ===========================================================================
//                                  Includes
// ===========================================================================
#include "String.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
const size_t String::MAX_SIZE_ = 100 ;
// ===========================================================================
//                                Constructors
// ===========================================================================
String::String(){
  size_ = 0 ;
  grid_ = new char[1] ;
  grid_[0] ='\0' ;
  capacity_ = 0;
}

String::String(const char* cstr){
  int i=0; // initialise iterator
  size_=0;
  while(cstr[i]!='\0'){
    size_++;
    i++;
  }
  grid_=new char[size_+1];
  for(size_t i=0;i<=size_;i++){
    grid_[i]=cstr[i];
  }
  capacity_=size_;
  
}

String::String(const String& model){
  size_=model.size_;
  capacity_=model.capacity_;
  grid_=new char[size_+1];  //taking into account the \0

  for(size_t i=0;i<size_;i++){ //revoir le int(size)!!!
    grid_[i]=model.grid_[i];
    }
  grid_[size_]='\0';
}
<<<<<<< HEAD


=======
>>>>>>> fe8b8d2eb2667c6d6d5aa02cc35e13b8325d4620


// ===========================================================================
//                                 Destructor
// ===========================================================================
String::~String(){
  delete[] grid_ ;
}
// ===========================================================================
//                               Public Methods
// ===========================================================================
size_t String::length() const noexcept{
  return size_;
}

size_t String::max_size() const noexcept{
  return MAX_SIZE_;
}

void String::resize(size_t n){
  char* newChar=new char[n+1];
  if(n<=size_){
    for(size_t i=0;i<n;i++){
      newChar[i]=grid_[i];
    }
    newChar[n]='\0';
    size_=n; //capacity stay unchanged
    delete[] grid_;
    grid_=newChar;
  }else{
    for(size_t i=0;i<=size_;i++){
      newChar[i]=grid_[i];
    }
    for(size_t i=size_;i<n;i++){
      newChar[i]=char();
    }
    newChar[n]='\0';
    size_=n;
    capacity_=n;
    delete[] grid_;
    grid_=newChar;
  }
}

void String::resize(size_t n, char c){
  char* newChar=new char[n+1];
  if(n<=size_){
    for(size_t i=0;i<n;i++){
      newChar[i]=grid_[i];
    }
    newChar[n]='\0';
    size_=n; //capacity stay unchanged
    delete[] grid_;
    grid_=newChar;
  }else{
    for(size_t i=0;i<=size_;i++){
      newChar[i]=grid_[i];
    }
    for(size_t i=size_;i<n;i++){
      newChar[i]=c;
    }
    newChar[n]='\0';
    size_=n;
    capacity_=n;
    delete[] grid_;
    grid_=newChar;
  }
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================


