// @(#)root/net:$Name:  $:$Id: TWebFile.h,v 1.4 2002/11/07 18:17:46 rdm Exp $
// Author: Fons Rademakers   17/01/97

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TWebFile
#define ROOT_TWebFile


//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TWebFile                                                             //
//                                                                      //
// A TWebFile is like a normal TFile except that it reads its data      //
// via a (slightly modified) apache web server. A TWebFile is a         //
// read-only file.                                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TFile
#include "TFile.h"
#endif
#ifndef ROOT_TUrl
#include "TUrl.h"
#endif


class TWebFile : public TFile {

private:
   TUrl     fUrl;        // URL of file
   Seek_t   fOffset;     // seek offset

   TWebFile() : fUrl("dummy") { }
   void Init(Bool_t);

public:
   TWebFile(const char *url);
   TWebFile(TUrl url);
   virtual ~TWebFile() { }

   Seek_t  GetSize() const;
   Bool_t  IsOpen() const;
   Int_t   ReOpen(Option_t *mode);
   Bool_t  ReadBuffer(char *buf, Int_t len);
   void    Seek(Seek_t offset, ERelativeTo pos = kBeg);

   ClassDef(TWebFile,1)  //A ROOT file that reads via a http server
};

#endif
