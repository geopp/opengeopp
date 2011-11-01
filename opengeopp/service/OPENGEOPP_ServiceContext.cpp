// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// OPENGEOPP
#include <opengeopp/basic/BasConst_OPENGEOPP_Service.hpp>
#include <opengeopp/factory/FacSupervisor.hpp>
#include <opengeopp/service/OPENGEOPP_ServiceContext.hpp>

namespace OPENGEOPP {

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_ServiceContext::
  OPENGEOPP_ServiceContext (const std::string& iSearchString) :
    _searchString (iSearchString) {
    init (iSearchString);
  }
  
  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_ServiceContext::OPENGEOPP_ServiceContext () : 
    _searchString ("") {
    init ("");
  }
  
  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_ServiceContext::
  OPENGEOPP_ServiceContext (const OPENGEOPP_ServiceContext&) :
    _searchString ("") {
    init ("");
  }

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_ServiceContext::~OPENGEOPP_ServiceContext() {
  }

  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_ServiceContext::init (const std::string& iSearchString) {
  }

  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_ServiceContext::
  setSearchString (const std::string& iSearchString) {
    _searchString = iSearchString;
    init (iSearchString);
  }

  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_ServiceContext::reset () {
    _searchString = "";
  }

}
