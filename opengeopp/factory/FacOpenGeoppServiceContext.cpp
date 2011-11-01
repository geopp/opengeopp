// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// OPENGEOPP
#include <opengeopp/service/OPENGEOPP_ServiceContext.hpp>
#include <opengeopp/factory/FacSupervisor.hpp>
#include <opengeopp/factory/FacOpenGeoppServiceContext.hpp>

namespace OPENGEOPP {

  FacOpengeoppServiceContext* FacOpengeoppServiceContext::_instance = NULL;

  // //////////////////////////////////////////////////////////////////////
  FacOpengeoppServiceContext::~FacOpengeoppServiceContext () {
    _instance = NULL;
  }

  // //////////////////////////////////////////////////////////////////////
  FacOpengeoppServiceContext& FacOpengeoppServiceContext::instance () {

    if (_instance == NULL) {
      _instance = new FacOpengeoppServiceContext();
      assert (_instance != NULL);
      
      FacSupervisor::instance().registerServiceFactory (_instance);
    }
    return *_instance;
  }

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_ServiceContext& FacOpengeoppServiceContext::create () {
    OPENGEOPP_ServiceContext* aServiceContext_ptr = NULL;

    aServiceContext_ptr = new OPENGEOPP_ServiceContext ();
    assert (aServiceContext_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aServiceContext_ptr);

    return *aServiceContext_ptr;
  }

  // //////////////////////////////////////////////////////////////////////
  OPENGEOPP_ServiceContext& FacOpengeoppServiceContext::
  create (const std::string& iSearchString) {
    OPENGEOPP_ServiceContext* aServiceContext_ptr = NULL;

    aServiceContext_ptr = new OPENGEOPP_ServiceContext (iSearchString);
    assert (aServiceContext_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aServiceContext_ptr);

    return *aServiceContext_ptr;
  }

}
