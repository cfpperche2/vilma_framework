#ifndef OROCOS_RTT_SUPERVISORY_COMPONENT_HPP
#define OROCOS_RTT_SUPERVISORY_COMPONENT_HPP

#include <rtt/RTT.hpp>

namespace VILMA {

	class VilmaSupv : public RTT::TaskContext {
	public:
		VilmaSupv(std::string const& name);
   		/**
       * Implement this method such that it contains the code which will be executed when configure() is called.
       * The default implementation is an empty function which returns true.
  		 * Return values:
  		 * 	true	to indicate that configuration succeeded and the Stopped state may be entered.
  		 *	false	to indicate that configuration failed and the Preoperational state is entered.
       */    
       bool configureHook();
        // {
        // ...
        // return true;
        // }

       /**
       	* Implement this method such that it contains the code which will be executed when start() is called.
    		* The default implementation is an empty function which returns true.
    		* Return values:
    		* 	true	to indicate that the component may run and the Running state may be entered.
    		* 	false	to indicate that the component may not run and the Stopped state is entered.
        */
       bool startHook(); 
        // {
        // ...
        // return true;
        // }

       /**
        * Function where the user must insert his 'application' code.
    		* When the ExecutionEngine's Activity is a periodic, this function is called by the ExecutionEngine in each
    		* periodic step after all messages are processed. When it is executed by a non periodic activity, 
    		* this function is called after a message is received and executed. It should not loop forever, 
    		* since no commands or events are processed when this function executes. 
    		* The default implementation is an empty function.
        */
       void updateHook();
        // {
        // Your component's algorithm/code goes in here.
        // }
       /**
       	* Implement this function if your code might block for long times inside the updateHook() function.
    		* Insert in this hook the code to wake up that code or signal it otherwise that updateHook() is requested 
    		* to return (for example by setting a flag). The method returns false by default.
    		* Returns:
    		*	true 	if well received and updateHook() will soon return. 
    		* 	false 	otherwise.
       	*/
  	   bool breakUpdateHook();
        // {
        // return true;
        // }
       /**
        * Implement this method such that it contains the code which will be executed when stop() is called.
		    * The default implementation is an empty function.
        */
       void stopHook();
        // {
        // Your stop code after last updateHook()
        // }

       /**
    		* Implement this method such that it contains the code which will be executed when cleanup() is called.
    		* The default implementation is an empty function.
        */
       void cleanupHook();
        // {
        // Your configuration cleanup code
        // }

       /**
         * Implement this method to contain code that must be executed in the RunTimeError state, instead of updateHook().
    	   * This allows you to specify the behaviour in an erroneous component. errorHook() is called as long as 
    	   * the component is not recover()'ed. After recover()'ed, the updateHook() is called again.
       */
       void errorHook();
        // {
        // ...
        // }

       /**
    		* Implement this method to contain code that must be executed when transitioning to the Exception state.
    		* This allows you to specify the last actions in an erroneous component, after stopHook() and cleanupHook() 
    		* were called.
       */
       virtual void exceptionHook();
        // {
        // ...
        // }
	};
} // end namespace
#endif
