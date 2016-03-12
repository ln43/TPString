#ifndef STRING_H_
#define STRING_H_
// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdlib>

class String{
	public :
  // =========================================================================
  //                               Constructors
  // =========================================================================
  String();
  String(const String&);
  String(const char* cstr);
  
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~String();
  // =========================================================================
  //                                  Getters
  // =========================================================================
  size_t length() const noexcept; //Returns length of the string
  size_t max_size() const noexcept; //Returns maxe_size of the string
  size_t capacity() const ;
  size_t size();
  const char* c_str() const;
  // =========================================================================
  //                                  Setters
  // =========================================================================
  void resize (size_t n);//changes size, inserts null if n>size_
  void resize (size_t n, char c); //changes size, inserts c if n>size_ 
  void clear();

  // =========================================================================
  //                                 Operators
  // =========================================================================
  String& operator=(char c);
  String& operator=(char* s);
  String& operator=(const String &s1); 
  friend String operator+(const String& lhs,const char* rhs);
  friend String operator+(const char* lhs,const String& rhs);
  friend String operator+(const String& lhs,const String& rhs);
  friend String operator+(const String&,char);
  friend String operator+(char,const String&);
	
  // =========================================================================
  //                              Public Methods
  // =========================================================================
  bool empty() const ;
  void reserve(size_t n);

	protected :

  // =========================================================================
  //                                Attributes
  // =========================================================================
	char* grid_ ; //Pointer on an array of char (\0 included)
	size_t size_ ; // number of char in the string (\0 not included)
	size_t capacity_ ; // useful capacity (\0 not included)
	static const size_t MAX_SIZE_ ;
};


#endif
