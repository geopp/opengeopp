// C
#include <assert.h>
// STL
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
// Boost (Extended STL)
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/program_options.hpp>
// OPENGEOPP
#include <opengeopp/OPENGEOPP_Service.hpp>
#include <opengeopp/config/opengeopp-paths.hpp>


// //////// Constants //////
/** Default name and location for the log file. */
const std::string K_OPENGEOPP_DEFAULT_LOG_FILENAME ("opengeopp.log");

/** Default search string. */
const std::string K_OPENGEOPP_DEFAULT_SEARCH_STRING ("nce rio de janeiro 22/10/2009");


// ///////// Parsing of Options & Configuration /////////
// A helper function to simplify the main part.
template<class T> std::ostream& operator<< (std::ostream& os,
                                            const std::vector<T>& v) {
  std::copy (v.begin(), v.end(), std::ostream_iterator<T> (std::cout, " ")); 
  return os;
}

/** Early return status (so that it can be differentiated from an error). */
const int K_OPENGEOPP_EARLY_RETURN_STATUS = 99;

/** Read and parse the command line options. */
int readConfiguration (int argc, char* argv[], std::string& ioSearchString,
                       std::string& ioLogFilename) {

  // Declare a group of options that will be allowed only on command line
  boost::program_options::options_description generic ("Generic options");
  generic.add_options()
    ("prefix", "print installation prefix")
    ("version,v", "print version string")
    ("help,h", "produce help message");
    
  // Declare a group of options that will be allowed both on command
  // line and in config file
  boost::program_options::options_description config ("Configuration");
  config.add_options()
    ("search,s",
     boost::program_options::value< std::string >(&ioSearchString)->default_value(K_OPENGEOPP_DEFAULT_SEARCH_STRING),
     "Search string")
    ("log,l",
     boost::program_options::value< std::string >(&ioLogFilename)->default_value(K_OPENGEOPP_DEFAULT_LOG_FILENAME),
     "Filename for the logs")
    ;

  // Hidden options, will be allowed both on command line and
  // in config file, but will not be shown to the user.
  boost::program_options::options_description hidden ("Hidden options");
  hidden.add_options()
    ("copyright",
     boost::program_options::value< std::vector<std::string> >(),
     "Show the copyright (license)");
        
  boost::program_options::options_description cmdline_options;
  cmdline_options.add(generic).add(config).add(hidden);

  boost::program_options::options_description config_file_options;
  config_file_options.add(config).add(hidden);

  boost::program_options::options_description visible ("Allowed options");
  visible.add(generic).add(config);
        
  boost::program_options::positional_options_description p;
  p.add ("copyright", -1);
        
  boost::program_options::variables_map vm;
  boost::program_options::
    store (boost::program_options::command_line_parser (argc, argv).
	   options (cmdline_options).positional(p).run(), vm);

  std::ifstream ifs ("opengeopp.cfg");
  boost::program_options::store (parse_config_file (ifs, config_file_options),
                                 vm);
  boost::program_options::notify (vm);
    
  if (vm.count ("help")) {
    std::cout << visible << std::endl;
    return K_OPENGEOPP_EARLY_RETURN_STATUS;
  }

  if (vm.count ("version")) {
    std::cout << PACKAGE_NAME << ", version " << PACKAGE_VERSION << std::endl;
    return K_OPENGEOPP_EARLY_RETURN_STATUS;
  }

  if (vm.count ("prefix")) {
    std::cout << "Installation prefix: " << PREFIXDIR << std::endl;
    return K_OPENGEOPP_EARLY_RETURN_STATUS;
  }

  if (vm.count ("search")) {
    ioSearchString = vm["search"].as< std::string >();
    std::cout << "Search string is: " << ioSearchString << std::endl;
  }

  if (vm.count ("log")) {
    ioLogFilename = vm["log"].as< std::string >();
    std::cout << "Log filename is: " << ioLogFilename << std::endl;
  }

  return 0;
}


// ///////// M A I N ////////////
int main (int argc, char* argv[]) {
  try {
    
    // Search string
    std::string lSearchString;

    // Output log File
    std::string lLogFilename;

    // Call the command-line option parser
    const int lOptionParserStatus = 
      readConfiguration (argc, argv, lSearchString, lLogFilename);

    if (lOptionParserStatus == K_OPENGEOPP_EARLY_RETURN_STATUS) {
      return 0;
    }

    // Check wether or not a search string is given
    bool hasSearchString = false;
    if (lSearchString.empty() == false) {
      hasSearchString = true;
    }

    // Set the log parameters
    std::ofstream logOutputFile;
    // Open and clean the log outputfile
    logOutputFile.open (lLogFilename.c_str());
    logOutputFile.clear();
    
    // Initialise the list of classes/buckets
    OPENGEOPP::OPENGEOPP_Service opengeoppService (logOutputFile,
                                                   lSearchString);
    
    
  } catch (const std::exception& stde) {
    std::cerr << "Standard exception: " << stde.what() << std::endl;
    return -1;
    
  } catch (...) {
    return -1;
  }
  
  return 0;	
}
