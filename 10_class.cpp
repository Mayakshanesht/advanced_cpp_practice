/*Goal: practice creating and using a class*/

#include"Dog.hpp"

int main()
{
    Dog dog1, dog2;
    dog1.setName("Trixie");
    dog2.setName("Kali");
    dog1.setLicenseNumber(1234);
    dog2.setLicenseNumber(5678);
    
    dog1.printInfo();
    cout<<"\n";
    dog2.printInfo();
    return 0;
}