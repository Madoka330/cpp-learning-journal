#include <iostream>
 
int main()
{
    std::cout << "Joe\n";
 
#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    /* Some
     * multi-line
     * comment here
     */
    std::cout << "Steve\n";
#endif // until this point
 
    return 0;
}