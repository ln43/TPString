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

size_t String::capacity() const{
  return capacity_ ;
}


void String::resize(size_t n){

  if(n<=size_){
    for(size_t i=n;i<=capacity_;i++){
      grid_[i]='\0'; //keep capacity, insert null character
    }
    size_=n;
  }else{
    char* newChar=new char[n+1];
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
  if(n<=size_){
    for(size_t i=n;i<=capacity_;i++){
      grid_[i]='\0'; //keep capacity, insert null character
    }
    size_=n;
  }else{
    char* newChar=new char[n+1];
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

size_t String::size(){
  return size_;
}

void String::clear(){

  delete[] grid_;
  grid_ = new char[1] ; //remplacer le 1 par la capacity?
  grid_[0] ='\0' ;
  size_=0;
  }

//test if the string is empty (if size_==0)
bool String::empty() const{
  bool empty = false ;
  if (size_ == 0){
    empty = true ;
  }
  return empty ;
}
 
const String& String::operator=(String const& s1){
  grid_=s1.grid_;
  size_=s1.size_;
  capacity_=s1.capacity_;
  return *this;
}

char* String::c_str() const{
  char* newChar=new char[size_]; //creation of a new String since we're dealing with pointers
  for(size_t i=0;i<size_;i++){   //if we modify grid_, newChar returned won't be modified
    newChar[i]=grid_[i];
  }
  return newChar;
}

void String::reserve(size_t n) {
  char* newGrid = new char[n+1] ;
  if (n > capacity_ || (n < capacity_ && n > size_)){
    for(size_t i=0 ; i<=size_ ; i++){
      newGrid[i]=grid_[i] ;
    }
    capacity_ = n ;
    delete[] grid_ ;
    grid_ = newGrid ;
  }
}

String& String::operator=(char c){
  grid_[0]=c;
  for(size_t i=1;i<=capacity_;i++){
    grid_[i]='\0';
  }
  size_=1;
  return *this;
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================


