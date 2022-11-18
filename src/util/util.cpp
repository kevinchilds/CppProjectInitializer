#include <iostream>
#include <fstream>
#include "util.hpp"

using namespace std;

void libcheck(void){
    cout << "its all good" << endl;
}


void generateMain(std::string projName){
    std::string mainFile = "./" + projName +"/src/main.cpp";

    std::ofstream outfile;
    outfile.open(mainFile);

    std::string content = "#include <iostream>\n#include \"util.hpp\"\n\nusing namespace std;";
    content.append("\n int main(){\n\tlibcheck();\n\n\treturn 0;\n}");

    outfile << content;
}

void generatePremake5(std::string projName){
    std::string premakeFile = "./" + projName +"/premake5.lua";

    std::ofstream outfile;
    outfile.open(premakeFile);

    std::string content = "workspace \"App\"\n";
    content.append("\tconfigurations { \"Debug\", \"Release\" }\n");
    content.append("\n");
    content.append("project \"" + projName + "\"\n");
    content.append("\tkind \"ConsoleApp\"\n");
    content.append("\tlanguage \"C++\"\n");
    content.append("\ttargetdir \"bin/%{cfg.buildcfg}\"\n");
    content.append("\n");
    content.append("\tfiles { \"include/**.hpp\", \"src/**.cpp\" }\n");
    content.append("\n");
    content.append("\n");
    content.append("\tincludedirs{\n");
    content.append("\t\t\"include\"\n");
    content.append("\t}\n");
    content.append("\tfilter \"configurations:Debug\"\n");
    content.append("\t\tdefines { \"DEBUG\" }\n");
    content.append("\t\tsymbols \"on\"\n");
    content.append("\n");
    content.append("\tfilter \"configurations:Relase\"\n");
    content.append("\t\tdefines { \"NDEBUG\" }\n");
    content.append("\t\toptimize \"on\"\n");

    
    outfile << content;
}

void generateUtil(string projName){
    std::string mainFile = "./" + projName +"/src/util/util.cpp";

    std::ofstream outfile;
    outfile.open(mainFile);

    std::string content = "#include <iostream>\n#include \"util.hpp\"\n\nusing namespace std;\n\n";

    content.append("void libcheck(void){\n");
    content.append("\tcout << \"Project: \" << \"" + projName + " initialized\" << endl;\n}");


    outfile << content;
    outfile.close();


    std::string headerFile = "./" + projName +"/include/util.hpp";
    outfile.open(headerFile);

    content = "#include<iostream>\n\nusing namespace std;\n\nvoid libcheck(void);";


    outfile << content;



}


void generateGitIgnore(string projName){
    std::string gitIgnoreFile = "./" + projName + "/.gitignore";

    std::ofstream outfile;
    outfile.open(gitIgnoreFile);

    std::string content = "";

    content.append("Makefile\n");
    content.append("**.make\n");
    content.append("bin/\n");
    content.append("obj/\n");


    outfile << content;
}