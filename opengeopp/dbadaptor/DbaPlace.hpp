#ifndef __OPENGEOPP_DBA_DBAPLACE_HPP
#define __OPENGEOPP_DBA_DBAPLACE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// SOCI
#include <soci/core/soci.h>

// Forward declarations
namespace OPENGEOPP {
  class Place;
}

namespace soci {

  /** Specify how the Place class can be converted to (resp. from) values
      stored into (resp. retrieved from) database, using the SOCI framework. */
  template <>
  struct type_conversion<OPENGEOPP::Place> {

    typedef values base_type;

    /** Fill an Place object from the database values. */
    static void from_base (values const& iPlaceValues,
                           indicator /* ind */,
                           OPENGEOPP::Place& ioPlace);


    /** Fill the database values from an Place object. */
    static void to_base (const OPENGEOPP::Place& iPlace,
                         values& ioPlaceValues,
                         indicator& ioIndicator);
  };
}
#endif // __OPENGEOPP_DBA_DBAPLACE_HPP
