#ifndef __OPENGEOPP_SVC_OPENGEOPP_SERVICE_HPP
#define __OPENGEOPP_SVC_OPENGEOPP_SERVICE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// OPENGEOPP
#include <opengeopp/OPENGEOPP_Types.hpp>

namespace OPENGEOPP {

  /** Forward declaration. */
  class OPENGEOPP_ServiceContext;

  /** Interface for the OPENGEOPP Services. */
  class OPENGEOPP_Service {
  public:
    /** Constructor. */
    OPENGEOPP_Service (std::ostream& ioLogStream,
                       const std::string& iSearchString);
    /** Destructor. */
    ~OPENGEOPP_Service();

    /** Set the search string. */
    void setSearchString (const std::string& iSearchString);

    /** Clear the context. */
    void reset ();

  private:
    /** Default Constructors. */
    OPENGEOPP_Service ();
    OPENGEOPP_Service (const OPENGEOPP_Service&);

    /** Initialise. */
    void init (std::ostream& ioLogStream,
               const std::string& iSearchString);
    
    /** Initilise the log. */
    void logInit (const LOG::EN_LogLevel iLogLevel, std::ostream& ioLogStream);

    /** Finaliser. */
    void finalise ();

  private:
    // ////////// Service Context //////////
    /** Service Context. */
    OPENGEOPP_ServiceContext* _opengeoppServiceContext;
  };
}
#endif // __OPENGEOPP_SVC_OPENGEOPP_SERVICE_HPP
