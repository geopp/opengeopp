// STL
#include <fstream>
#include <string>
// CPPUNIT
#include <test/com/CppUnitCore.hpp>
// OPENGEOPP
#include <opengeopp/OPENGEOPP_Service.hpp>
#include <opengeopp/OPENGEOPP_Types.hpp>
// OPENGEOPP Test Suite
#include <test/OpenGeoTestSuite.hpp>

// //////////////////////////////////////////////////////////////////////
bool testOpenGeoHelper () {

  // Return value
  bool oHasSucceeded = true;

  try {

    // Output log File
    std::string lLogFilename ("OpenGeoTestSuite.log");
    
    // Search string
    const std::string lSearchString ("nce rio de janeiro 22/10/2009");

    // Set the log parameters
    std::ofstream logOutputFile;
    // Open and clean the log outputfile
    logOutputFile.open (lLogFilename.c_str());
    logOutputFile.clear();
    
    // Initialise the OPENGEOPP service
    OPENGEOPP::OPENGEOPP_Service opengeoppService(logOutputFile, lSearchString);
    
        
  } catch (const std::exception& stde) {
    std::cerr << "Standard exception: " << stde.what() << std::endl;
    
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

  return oHasSucceeded;
}


// //////////////////////////////////////////////////////////////////////
void OpenGeoTestSuite::testOpenGeo() {
  CPPUNIT_ASSERT_NO_THROW (testOpenGeoHelper(););
}

// //////////////////////////////////////////////////////////////////////
// void OpenGeoTestSuite::errorCase () {
//  CPPUNIT_ASSERT (false);
// }

// //////////////////////////////////////////////////////////////////////
OpenGeoTestSuite::OpenGeoTestSuite () {
  _describeKey << "Running test on OpenGeo++ function";  
}

// /////////////// M A I N /////////////////
CPPUNIT_MAIN()

