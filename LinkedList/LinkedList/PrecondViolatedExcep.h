//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-5.
    @file PrecondViolatedExcep.h */


#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep 
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-6.
    @file PrecondViolatedExcep.cpp */

PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

