#ifndef __OPENGEOPP_SVC_OPENGEOPP_SERVICE_CONTEXT_HPP
#define __OPENGEOPP_SVC_OPENGEOPP_SERVICE_CONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// OPENGEOPP
#include <opengeopp/OPENGEOPP_Types.hpp>
#include <opengeopp/service/ServiceAbstract.hpp>

namespace OPENGEOPP {

  /** Forward declaration. */

  
  /** Inner class holding the context for the OPENGEOPP Service object. */
  class OPENGEOPP_ServiceContext : public ServiceAbstract {
    /** The OPENGEOPP_Service class should be the sole class to get access to
        ServiceContext content: general users do not want to bother
        with a context interface. */
    friend class OPENGEOPP_Service;
    friend class FacOpengeoppServiceContext;

  private:
    /** Constructors. */
    OPENGEOPP_ServiceContext ();
    OPENGEOPP_ServiceContext (const OPENGEOPP_ServiceContext&);
    OPENGEOPP_ServiceContext (const std::string& iSearchString);
    void init (const std::string& iSearchString);
    /** Destructor. */
    ~OPENGEOPP_ServiceContext();

    /** Set the search string. */
    void setSearchString (const std::string& iSearchString);
    
    /** Clear the context. */
    void reset ();

    
  private:
    // /////////// Attributes ////////////
    /** Search string. */
    std::string _searchString;
  };

}
#endif // __OPENGEOPP_SVC_OPENGEOPP_SERVICE_CONTEXT_HPP
