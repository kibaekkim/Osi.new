// Copyright (C) 2000, International Business Machines
// Corporation and others.  All Rights Reserved.
#if defined(_MSC_VER)
// Turn off compiler warning about long names
#  pragma warning(disable:4786)
#endif

#include "OsiColCut.hpp"
#include <cstdlib>
#include <cstdio>
#include <iostream>

//-------------------------------------------------------------------
// Default Constructor 
//-------------------------------------------------------------------
OsiColCut::OsiColCut() :
   OsiCut(),
   lbs_(),
   ubs_()
{
  // nothing to do here
}
//-------------------------------------------------------------------
// Copy constructor 
//-------------------------------------------------------------------
OsiColCut::OsiColCut(const OsiColCut & source) :
   OsiCut(source),
   lbs_(source.lbs_),
   ubs_(source.ubs_)
{  
  // Nothing to do here
}


//----------------------------------------------------------------
// Clone
//----------------------------------------------------------------
OsiColCut * OsiColCut::clone() const
{ return (new OsiColCut(*this)); }

//-------------------------------------------------------------------
// Destructor 
//-------------------------------------------------------------------
OsiColCut::~OsiColCut ()
{
  // Nothing to do here
}

//----------------------------------------------------------------
// Assignment operator 
//-------------------------------------------------------------------
OsiColCut &
OsiColCut::operator=(const OsiColCut& rhs)
{
  if (this != &rhs) {
    
    OsiCut::operator=(rhs);
    lbs_=rhs.lbs_;
    ubs_=rhs.ubs_;
  }
  return *this;
}
//----------------------------------------------------------------
// Print
//-------------------------------------------------------------------

void
OsiColCut::print() const
{
  const CoinPackedVector & cutLbs = lbs();
  const CoinPackedVector & cutUbs = ubs();
  int i;
  std::cout<<"Column cut has "<<cutLbs.getNumElements()
	   <<" Lower bound cuts"<<std::endl;
  for ( i=0; i<cutLbs.getNumElements(); i++ ) {
    int colIndx = cutLbs.getIndices()[i];
    double newLb= cutLbs.getElements()[i];
    std::cout<<"[ x"<<colIndx<<" >= "<<newLb<<"] ";
  }
  std::cout<<std::endl;
  std::cout<<"    and "<<cutUbs.getNumElements()
	   <<" Upper bound cuts"<<std::endl;
  for ( i=0; i<cutUbs.getNumElements(); i++ ) {
    int colIndx = cutUbs.getIndices()[i];
    double newUb= cutUbs.getElements()[i];
    std::cout<<"[ x"<<colIndx<<" <= "<<newUb<<"] ";
  }
  std::cout<<std::endl;
}

