// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iomanip>
#include <sstream>
#include <iostream>
// OPENGEOPP
#include <opengeopp/basic/BasConst_OPENGEOPP_Service.hpp>
#include <opengeopp/factory/FacOpenGeoppServiceContext.hpp>
#include <opengeopp/service/OPENGEOPP_ServiceContext.hpp>
#include <opengeopp/service/Logger.hpp>
#include <opengeopp/OPENGEOPP_Service.hpp>

namespace OPENGEOPP {

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_Service::OPENGEOPP_Service () :
    _opengeoppServiceContext (NULL) {
  }

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_Service::OPENGEOPP_Service (const OPENGEOPP_Service& iService) :
    _opengeoppServiceContext (iService._opengeoppServiceContext) {
  }

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_Service::OPENGEOPP_Service (std::ostream& ioLogStream,
                                        const std::string& iSearchString) {
    // Initialise the context
    init (ioLogStream, iSearchString);
  }

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_Service::~OPENGEOPP_Service () {
  }

  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_Service::init (std::ostream& ioLogStream,
                                const std::string& iSearchString) {
    // Set the log file
    logInit (LOG::DEBUG, ioLogStream);

    // Initialise the context
    OPENGEOPP_ServiceContext& lOPENGEOPP_ServiceContext = 
      FacOpengeoppServiceContext::instance().create (iSearchString);
    _opengeoppServiceContext = &lOPENGEOPP_ServiceContext;
  }
  
  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_Service::logInit (const LOG::EN_LogLevel iLogLevel,
                                   std::ostream& ioLogOutputFile) {
    Logger::instance().setLogParameters (iLogLevel, ioLogOutputFile);
  }

  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_Service::setSearchString (const std::string& iSearchString) {
    assert (_opengeoppServiceContext != NULL);
    _opengeoppServiceContext->setSearchString (iSearchString);
  }
  
  // //////////////////////////////////////////////////////////////////////
  void OPENGEOPP_Service::reset () {
    assert (_opengeoppServiceContext != NULL);
    _opengeoppServiceContext->reset ();
  }
  
}
