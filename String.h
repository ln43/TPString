#ifndef STRING_H_
#define STRING_H_
#include <cstdlib>
// ===========================================================================
//                                  Includes
// ===========================================================================
class String{
	public :
  // =========================================================================
  //                               Attribut classe
  // =========================================================================

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
  size_t length() const noexcept; //Return length of the string
  size_t max_size() const noexcept; //Return maxe_size of the string
  size_t capacity() const ;
  size_t size();
  const char* c_str() const;
  // =========================================================================
  //                                  Setters
  // =========================================================================
  void resize (size_t n);//change size, insert null if n>size_
  void resize (size_t n, char c); //change size, insert c if n>size_ 
  void clear();

  // =========================================================================
  //                                 Operators
  // =========================================================================
  String& operator=(char c);
  friend String operator+(const String& lhs,const char* rhs);
  friend String operator+(const char* lhs,const String& rhs);
  // =========================================================================
  //                              Public Methods
  // =========================================================================
  bool empty() const ;
  void reserve(size_t n);
  const String& operator=(const String &s1);
  const String& operator+(const String &s1);
  friend String operator+(const String&,char);
	
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
