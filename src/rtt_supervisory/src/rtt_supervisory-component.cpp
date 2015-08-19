/** 
* Aug. 2015
* Author: Carlos Felipe de Paiva Perche 
*/

#include "rtt_supervisory-component.hpp"
#include <rtt/Component.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Property.hpp>
#include <iostream>

namespace VILMA {
	
	using namespace RTT;
	using namespace std;
	// param PreOperational demand configure() call, before call start().
	VilmaSupv::VilmaSupv(const std::string& name) : TaskContext(name, PreOperational),
		param("The String"),
    	value( 1.23 ),
        aflag(false), max(5), pi(3.14) {
		std::cout << "VilmaSupv constructed !" <<std::endl;

		// attributes and constants don't take a .doc() description.
       this->addAttribute( "aflag", aflag );
       this->addAttribute( "max", max );
      
       this->addConstant( "pi", pi );

       this->addProperty( "Param", param ).doc("Param Description");
       this->addProperty( "Palue", value ).doc("Value Description");
	}

	bool VilmaSupv::configureHook(){
  		std::cout << "VilmaSupv configured !" <<std::endl;
	  	return true;
	}

	bool VilmaSupv::startHook(){
	  	std::cout << "VilmaSupv started !" <<std::endl;
	  	return true;
	}

	void VilmaSupv::updateHook(){
	  	std::cout << "VilmaSupv executes updateHook !" <<std::endl;
	}

	bool VilmaSupv::breakUpdateHook(){
	  	std::cout << "VilmaSupv executes breakUpdateHook !" <<std::endl;
	   	return true;
	}

	void VilmaSupv::stopHook() {
	  	std::cout << "VilmaSupv executes stopping !" <<std::endl;
	}

	void VilmaSupv::cleanupHook() {
	  	std::cout << "VilmaSupv cleaning up !" <<std::endl;
	}

	void VilmaSupv::errorHook() {
	  	std::cout << "VilmaSupv errorHook up !" <<std::endl;
	}

	void VilmaSupv::exceptionHook() {
	  	std::cout << "VilmaSupv exceptionHook up !" <<std::endl;
	}

} // end namespace

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(VilmaSupv)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(VILMA::VilmaSupv)