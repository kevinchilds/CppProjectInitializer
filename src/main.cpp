#include <iostream>
#include "util.hpp"


int main(){
    std::string projName;
    std::cout << "C++ project initializer" << std::endl;

    //project name
    std::cout << "Project Name: ";
    std::cin >> projName;

    std::string mkdirCommand = "mkdir " + projName + " ./" + projName + "/src" + " ./" + projName + "/src/util" + " ./" + projName + "/include";
    system(mkdirCommand.c_str());

    generatePremake5(projName);
    generateMain(projName);
    generateUtil(projName);
    generateGitIgnore(projName);
    


    std::cout << "Project \"" << projName << "\" created successfully" << std::endl;
    return 0;
}