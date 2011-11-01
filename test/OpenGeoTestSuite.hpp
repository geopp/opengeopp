// STL
#include <sstream>
// CPPUNIT
#include <cppunit/extensions/HelperMacros.h>

class OpenGeoTestSuite : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE (OpenGeoTestSuite);
  CPPUNIT_TEST (testOpenGeo);
  //  CPPUNIT_TEST (errorCase);
  CPPUNIT_TEST_SUITE_END ();
public:

  /** Test the string parsing functionality. */
  void testOpenGeo();

  /** Test some error detection functionalities. */
  //  void errorCase ();

  /** Constructor. */
  OpenGeoTestSuite ();
  
protected:
  std::stringstream _describeKey;
};

CPPUNIT_TEST_SUITE_REGISTRATION (OpenGeoTestSuite);
