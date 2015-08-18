/** 
* Aug. 2015
* Author: Carlos Felipe de Paiva Perche 
*/

#include "rtt_supervisory-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

namespace VILMA {
	
	using namespace RTT;
	using namespace std;
	// param PreOperational demand configure() call.
	VilmaSupv::VilmaSupv(const std::string& name) : TaskContext(name, PreOperational){
		std::cout << "VilmaSupv constructed !" <<std::endl;
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
	  	this->cleanup();

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
	  	this->stop();
	}

	void VilmaSupv::errorHook() {
	  	std::cout << "VilmaSupv errorHook up !" <<std::endl;
	  	this->recover();
	}

	void VilmaSupv::exceptionHook() {
	  	std::cout << "VilmaSupv exceptionHook up !" <<std::endl;
	  	this->recover();
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