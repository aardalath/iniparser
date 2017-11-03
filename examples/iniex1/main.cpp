#include <iostream>

#include "iniparser.h"

const char ConfigFile[] = "/tmp/config-jcg.ini";

const char CfgStr[] = 
  "[General]\n"
  "key1=value1\n"
  "key2=value2\n"
  "key3=value3\n"
  "\n"
  "[Section1]\n"
  "key4=3.45\n"
  "key5=234\n"
  "\n"
  "[Section1:Subsection2]\n"
  "key6=Hola\n"
  "key7=127.0.0.1\n"
  ;


void createInitialConfigFile(Config::IniParser & ini,
			     Config::Config * config) 
{
  ini.parse(config, CfgStr);
  ini.saveTo(config, ConfigFile);
}

void addComponents(Config::IniParser & ini,
		   Config::Config * config)
{
  ini.loadFrom(config, ConfigFile);

  ini.with(config)
    .section("Manager")
    .add("component", "Manager")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("DataDissemServMng")
    .add("component", "ddsm")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("DataIngServMng")
    .add("component", "dism")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("DataStorMng")
    .add("component", "dsm")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("ExternalDataSupplier")
    .add("component", "ext-datasup")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("ExternalDisseminationClient")
    .add("component", "ext-discli")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("ExternalMonitInfoConsumer")
    .add("component", "ext-monitcons")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("ExternalProductsIngester")
    .add("component", "ext-proding")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("InternalArchive")
    .add("component", "ia")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("Inventory")
    .add("component", "inv")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("NRTAcqProcElem")
    .add("component", "nrtape")
    .add("address", "127.0.0.1")
    .add("user", "jcgg")

    .section("TaskDistMng")
    .add("component", "tdm")
    .add("address", "127.0.0.1")
    .add("user", "jcgg");

  ini.with(config)
    .section("Components")
    .add<int>("num_of_components", 12)
    .add<int>("num_of_internal_components", 8)
    .add<int>("num_of_external_components", 4)
    .add("internal", 
	 "Manager,"
	 "DataDissemServMng,"
	 "DataIngServMng,"
	 "DataStorMng,"
	 "InternalArchive,"
	 "Inventory,"
	 "NRTAcqProcElem,"
	 "TaskDistMng")
    .add("external",
	 "ExternalDataSupplier,"
	 "ExternalDisseminationClient,"
	 "ExternalMonitInfoConsumer,"
	 "ExternalProductsIngester");
  
  ini.saveTo(config, ConfigFile);
}

int main(int argc, char * argv[]) 
{
  Config::IniParser ini;
  Config::Config * config = ini.createConfig();

  createInitialConfigFile(ini, config);
  addComponents(ini, config);

  int numOfExtComponents = ini.valueAs<int>("Components", "num_of_external_components");
  int numOfIntComponents = ini.valueAs<int>("Components", "num_of_internal_components");

  std::vector<std::string> componentNames;
  ini.section("Components");
  ini.getListOf("external", componentNames);
  ini.getListOf("internal", componentNames);
  
  std::cerr << "Loaded " << numOfExtComponents + numOfIntComponents << " components ("
	    << numOfExtComponents <<  " + " << numOfIntComponents << ")\n";
  for (int i = 0; i < componentNames.size(); ++i) {
    std::string component = componentNames.at(i);
    std::cerr << component << ": {" 
	      << ini.valueOf(component, "user") << " @ "
	      << ini.valueOf(component, "address") << "}\n";
  }

  return 0;
}




