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
  // =========================================================================
  //                                Destructor
  // =========================================================================

  // =========================================================================
  //                                  Getters
  // =========================================================================

  // =========================================================================
  //                                  Setters
  // =========================================================================

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================

	
	protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
	char* grid_ ; //Pointer on an array of char (\0 included)
	size_t size_ ; // number of char in the string (\0 not included)
	size_t capacity_ ; // useful capacity (\0 not included)
	static const size_t MAX_SIZE_ ;
};
// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================


#endif
