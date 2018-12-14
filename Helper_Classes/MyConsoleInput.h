/** MyConsoleInput.h
 *	
 *	A re-usable library of input validation functions.
 *	   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#ifndef MY_CONSOLE_INPUT_H

#define MY_CONSOLE_INPUT_H

#include <limits> 
#include <cfloat>  // for limits of a double DBL_MIN and DBL_MAX
#include "MyConsoleInput.cpp"

namespace ConsoleInput
{
	/**	ReadDouble function
	 * Reads a valid double value from the console with range checking
	 *
	 * @param  MIN the minimum value the user may enter; defaults to the maximum negative double.
	 * @param  MIN the minimum value the user may enter; defaults to the maximum double.
	 * @return A validated double input by the user.
	*/
	double ReadDouble(const double MIN = -DBL_MAX, const double MAX = DBL_MAX);
	
	/**	ReadInteger function
	 * Reads a valid int value from the console with range checking
	 *
	 * @param  MIN the minimum value the user may enter; defaults to the minimum int.
	 * @param  MIN the minimum value the user may enter; defaults to the maximum int.
	 * @return A validated int input by the user.
	*/
	int ReadInteger(const int MIN = INT_MIN, const int MAX = INT_MAX);
	
}
#endif // end of ifndef MY_CONSOLE_INPUT_H
