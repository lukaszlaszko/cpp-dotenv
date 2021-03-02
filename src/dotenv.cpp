#include "dotenv.h"

#include "environ.h"
#include "Parser.h"

#include <fstream>
#include <utility>


using namespace std;
using namespace cppdotenv;


cppdotenv::dotenv& cppdotenv::dotenv::load_dotenv(const string& dotenv_path, const bool overwrite, const bool interpolate)
{
    ifstream env_file;
    env_file.open(dotenv_path);

    if (env_file.good())
    {
        Parser parser;
        parser.parse(env_file, overwrite, interpolate);
        env_file.close();
    }

    return *this;
}


const cppdotenv::dotenv::value_type cppdotenv::dotenv::operator[](const key_type& k) const
{
    return getenv(k).second;
}


cppdotenv::dotenv& cppdotenv::dotenv::instance()
{
    return _instance;
}


const string cppdotenv::dotenv::env_filename = ".env";
cppdotenv::dotenv cppdotenv::dotenv::_instance;

cppdotenv::dotenv& cppdotenv::env = dotenv::instance();
