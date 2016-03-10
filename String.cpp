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

/* Constructs a string object
 * param cstr : c-string to initialize the grid_ */
String::String(const char* cstr){
  int i=0; // initialise iterator
  size_=0;
  while(cstr[i]!='\0'){
    size_++;
    i++;
  }
  if(size_>MAX_SIZE_){
      size_=MAX_SIZE_; //we will only copy the 100 first characters
  }
  grid_=new char[size_+1];
  for(size_t i=0;i<size_;i++){
    grid_[i]=cstr[i];
  }
  capacity_=size_;
}

String::String(const String& model){
  size_=model.size_;
  capacity_=model.capacity_;
  grid_=new char[size_+1];  //taking into account the \0

  for(size_t i=0;i<size_;i++){
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

// Returns the length of the string, in terms of bytes.
size_t String::length() const noexcept{
  return size_;
}

// Returns the maximum length the string can reach.
size_t String::max_size() const noexcept{
  return MAX_SIZE_;
}

size_t String::capacity() const{
  return capacity_ ;
}

/*Resize the String
 * param n : the size of the new String**/
void String::resize(size_t n){
  if(n<=size_){
    for(size_t i=n;i<=capacity_;i++){
      grid_[i]='\0'; //keep capacity, insert null character
    }
    size_=n;
  }else if (n>=MAX_SIZE_){
    char* newChar=new char[MAX_SIZE_+1];
    for(size_t i=0;i<=size_;i++){
      newChar[i]=grid_[i];
    }
    for(size_t i=size_;i<MAX_SIZE_;i++){
      newChar[i]='\0';
    }
    newChar[MAX_SIZE_]='\0';
    size_=MAX_SIZE_;
    if(capacity_<MAX_SIZE_){
      capacity_=MAX_SIZE_;
    }
    delete[] grid_;
    grid_=newChar;
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
    if(capacity_<n){
      capacity_=n;
    }
    delete[] grid_;
    grid_=newChar;
  }
}

/*Resize the String
 * param n : the size of the new String
 * param c : the caracter to insert if n<size_ **/
void String::resize(size_t n, char c){
  if(n<=size_){
    for(size_t i=n;i<=capacity_;i++){
      grid_[i]='\0'; //keep capacity, insert null character
    }
    size_=n;
  }else if (n>=MAX_SIZE_){
    char* newChar=new char[MAX_SIZE_+1];
    for(size_t i=0;i<=size_;i++){
      newChar[i]=grid_[i];
    }
    for(size_t i=size_;i<MAX_SIZE_;i++){
      newChar[i]=c;
    }
    newChar[MAX_SIZE_]='\0';
    size_=MAX_SIZE_;
    if(capacity_<MAX_SIZE_){
      capacity_=MAX_SIZE_;
    }
    delete[] grid_;
    grid_=newChar;
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
    if(capacity_<n){
      capacity_=n;
    }
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

//tests if the string is empty (if size_==0)
bool String::empty() const{
  bool empty = false ;
  if (size_ == 0){
    empty = true ;
  }
  return empty ;
}
 
const char* String::c_str() const{
  return grid_;
}

void String::reserve(size_t n) {
  char* newGrid ;
  if(n <= MAX_SIZE_) {
    newGrid = new char[n+1] ;
  } else {
    newGrid = new char[MAX_SIZE_+1] ;
  }
  if (n > capacity_ || (n < capacity_ && n > size_)){
    for(size_t i=0 ; i<=size_ ; i++){
      newGrid[i]=grid_[i] ;
    }
    if(n <= MAX_SIZE_){
      capacity_ = n ;
    } else {
      capacity_ = MAX_SIZE_ ;
    }
    delete[] grid_ ;
    grid_ = newGrid ;
  } else {
    delete[] newGrid ;
  }
}

const String& String::operator=(String const& s1){
  delete[] grid_;
  grid_=new char[s1.size_+1];
  for(size_t i=0;i<s1.size_;i++){
    grid_[i]=s1.grid_[i];
    }
  grid_[s1.size_]='\0';
  size_=s1.size_;
  capacity_=s1.capacity_;
  return *this;
}

/*Assigns a new value to the string, replacing its current contents.
* param c : the character which will replace the String
* return the String as reference*/
String& String::operator=(char c){
  grid_[0]=c;
  for(size_t i=1;i<=capacity_;i++){
    grid_[i]='\0';
  }
  size_=1;
  return *this;
}

String& String::operator=(char* s){
  int i = 0 ;
  size_t size_s = 0 ;
  while(s[i]!='\0'){
    size_s ++;
    i++;
  }
  if(size_s <= capacity_){
    for(size_t j=0 ; j<size_s ; j++){
      grid_[j] = s[j] ;
    }
    grid_[size_s]='\0' ;
    size_ = size_s ;
  } else {
    this->reserve(size_s) ;
    for(size_t j=0 ; j<size_s ; j++){
      grid_[j] = s[j] ;
    }
    if(size_s <= MAX_SIZE_){
      grid_[size_s]='\0' ;
      size_ = size_s ;
    } else {
      grid_[MAX_SIZE_]='\0';
      size_ = MAX_SIZE_ ;
    }
  }
  return *this;
}

// ===========================================================================
//                                 Operators
// ===========================================================================

String operator+(const String& s1,char c){
  char* tempgrid=new char[s1.size_+2] ;
  for(size_t i;i<s1.size_;i++){
    tempgrid[i]=s1.grid_[i];
  }
  tempgrid[s1.size_]=c;
  tempgrid[s1.size_+1]='\0';
  return String(tempgrid);
  delete[] tempgrid;
}

/*Returns a newly constructed string object with its value being 
the concatenation of the characters in lhs followed by those of rhs.
* param lhs : the string to concatenate
* param rhs : the c-string to add at the end of the string
* return : the concatenation of the two params*/
String operator+(const String& lhs,const char* rhs){
  int i=0; // initialize iterator
  size_t sizeRhs=0;
  size_t sizeLhs=lhs.size_;
  while(rhs[i]!='\0'){
    sizeRhs++;
    i++;
  }
  char* newChar=new char[sizeLhs+sizeRhs+1];
  for(size_t i=0;i<sizeLhs;i++){
    newChar[i]=lhs.grid_[i];
  }
  for(size_t i=sizeLhs;i<=sizeLhs+sizeRhs;i++){
    newChar[i]=rhs[i-sizeLhs];
  }
  String newS(newChar);
  delete newChar;
  return newS;
}

/*Returns a newly constructed string object with its value being 
the concatenation of the characters in lhs followed by those of rhs.
* param lhs : the c-string to add at the begining of the string
* param rhs : the string to concatenate
* return : the concatenation of the two params*/
String operator+(const char* lhs,const String& rhs){
  int i=0; // initialize iterator
  size_t sizeLhs=0;
  size_t sizeRhs=rhs.size_;
  while(lhs[i]!='\0'){
    sizeLhs++;
    i++;
  }
  char* newChar=new char[sizeLhs+sizeRhs+1];
  for(size_t i=0;i<sizeLhs;i++){
    newChar[i]=lhs[i];
  }
  for(size_t i=sizeLhs;i<=sizeLhs+sizeRhs;i++){
    newChar[i]=rhs.grid_[i-sizeLhs];
  }
  String newS(newChar);
  delete newChar;
  return newS;
}

String operator+(const String& lhs,const String& rhs){
  char* sum = new char[lhs.size_ + rhs.size_ -1];
  for(size_t i=0 ; i<lhs.size_ ; i++){
    sum[i] = lhs.grid_[i] ;
  }
  for(size_t j=0 ; j<rhs.size_ ; j++){
    sum[lhs.size_ + j] = rhs.grid_[j] ;
  }
  sum[lhs.size_ + rhs.size_]='\0' ;
  String Res(sum) ;
  delete sum;
  return Res;
}

