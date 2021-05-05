/*
 *Filename        commandLineParser.cc
 *Date            2/6/19
 *Author          Gabriel Goldstein
 *Email           gjg180000@utdallas.edu
 *Course          CS 3377.502 Spring 2019
 *Version         1.0
 *Copyright 2019, All Rights Reserved
 *
 *Description
 *
 *      Deals with the tclap related operations, including, but most certainly not limited to, determining the input file name, if an output file name has been printed and what that name is, as well as if the uppercase and/or lowercase flags have been written to the command line. Saves all values to a map. Prints errors if a violation of the magical tclap rules has occurred  
 */



#include "header.h"
#include <map>
#include <tclap/CmdLine.h>

using namespace std;
string boolToString(bool);

void cmdParser(map<argsEnum, string> &parseResults, int argc, char* argv[])
{
  try{

    //Creates a command line object 
    TCLAP::CmdLine cmd("CS3376.502", ' ',"1.0");

    //Creates an ouput file value argument. Default name is "output.txt"
    TCLAP::ValueArg<string> outfileArg("o","outfile", "The name of the output file",false,"output.txt","output filename");

    //Add the outfile argument to the cmd object
    cmd.add(outfileArg);

    //Creates uppercase and lowercase switch arguments
    TCLAP::SwitchArg uppercaseArg("u","upper", "Convert all text to uppercase", cmd, false);
    TCLAP::SwitchArg lowercaseArg("l","lower", "Convert all text to lowercase", cmd, false);
    //Create an unlabeled value argument for the input file. Default name is "infile.txt"
    TCLAP::UnlabeledValueArg<std::string> infileArg("infile", "Input File", true, "infile.txt", "input filename", false);
    cmd.add(infileArg);

    //Parse the command line
    cmd.parse(argc, argv);

    //Store the values of the arguments to the hashmap, with the keys being the enumerated type and the values being stored as strings
    parseResults[LOWER] = boolToString(lowercaseArg.getValue());
    parseResults[UPPER] = boolToString(uppercaseArg.getValue());
    parseResults[OUTFILE] = outfileArg.getValue();
    parseResults[INFILE] = infileArg.getValue();

    //If both the uppercase and lowercase flags have been written, print out error and the usage
    if (parseResults[LOWER] == "1" && parseResults[UPPER] == "1")
      {
	cerr << "ERROR" << endl;
	cmd.getOutput()->usage(cmd);
      }


  }
  catch(TCLAP::ArgException &e)
    {
      cerr << "error: " << e.error() << "for arg" << e.argId() << endl;
    }

}


//Convert the bool values crated by the switch args to strings 
string boolToString(bool b)
{

  //If the boolean is true, return 1
  if(b == true)
    {
      return "1";
    }
  //If the boolean is false, return 0
  else
    {
      return "0";
    }

}
