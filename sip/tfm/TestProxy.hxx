#ifndef TestProxy_hxx
#define TestProxy_hxx

#include <set>
#include "resiprocate/os/Data.hxx"
#include "resiprocate/os/TransportType.hxx"
#include "resiprocate/NameAddr.hxx"
#include "tfm/Source.hxx"

namespace resip
{
class Uri;
}

class TestProxy
{
   public:
      TestProxy(const resip::Data& name,
                const resip::Data& host, 
                int port, 
                const resip::Data& interface = resip::Data::Empty);
      TestProxy();
      ~TestProxy();

      void addSource(const resip::Data& host, int port, resip::TransportType transport);
      void addSource(const Source& source);
      void addSources(const SourceSet& sources);
      bool isFromMe(const resip::SipMessage& msg);

      const resip::Data& getDomain() const;
      const int getPort() const;
      const resip::NameAddr& getProxyUrl() const;
      const resip::Uri& getUri() const;
      const resip::NameAddr& getContact() const;
      resip::NameAddr makeUrl(const resip::Data& name) const;
      resip::Data toString() const;

   protected:
      resip::Data mName;
      resip::NameAddr mProxyUrl; //really more than one possible url
      mutable resip::NameAddr mContact;
      SourceSet mSources;
      int mPort;

   private:
      TestProxy(const TestProxy&);
      TestProxy& operator=(const TestProxy&);

};

#endif

// Copyright 2005 Purplecomm, Inc.
/*
  Copyright (c) 2005, PurpleComm, Inc. 
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  * Neither the name of PurpleComm, Inc. nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
