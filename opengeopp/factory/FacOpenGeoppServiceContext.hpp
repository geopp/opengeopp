#ifndef __OPENGEOPP_FAC_FACOPENGEOPPSERVICECONTEXT_HPP
#define __OPENGEOPP_FAC_FACOPENGEOPPSERVICECONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// OPENGEOPP
#include <opengeopp/OPENGEOPP_Types.hpp>
#include <opengeopp/factory/FacServiceAbstract.hpp>

namespace OPENGEOPP {

  /** Forward declarations. */
  class OPENGEOPP_ServiceContext;

  /** Factory for Bucket. */
  class FacOpengeoppServiceContext : public FacServiceAbstract {
  public:

    /** Provide the unique instance.
        <br> The singleton is instantiated when first used
        @return FacServiceContext& */
    static FacOpengeoppServiceContext& instance();

    /** Destructor.
        <br> The Destruction put the _instance to NULL
        in order to be clean for the next FacServiceContext::instance() */
    virtual ~FacOpengeoppServiceContext();

    /** Create a new ServiceContext object.
        <br>This new object is added to the list of instantiated objects.
        @return ServiceContext& The newly created object. */
    OPENGEOPP_ServiceContext& create ();

    /** Create a new ServiceContext object.
        <br>This new object is added to the list of instantiated objects.
        @return ServiceContext& The newly created object. */
    OPENGEOPP_ServiceContext& create (const std::string& iSearchString);

    
  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacOpengeoppServiceContext () {}

  private:
    /** The unique instance.*/
    static FacOpengeoppServiceContext* _instance;

  };
}
#endif // __OPENGEOPP_FAC_FACOPENGEOPPSERVICECONTEXT_HPP
