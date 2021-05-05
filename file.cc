
/*
 *Filename        file.cc
 *Date            2/6/19
 *Author          Gabriel Goldstein
 *Email           gjg180000@utdallas.edu
 *Course          CS 3377.502 Spring 2019
 *Version         1.0
 *Copyright 2019, All Rights Reserved
 *
 *Description
 *
 *      The function main calls the function cmdParser to parse the command line and fill the map. Main in turn uses the map to determine the input file it must read from and determines if the text from the input file must be made all uppercase or all lowercase, and carries out the approriate command when it prints out the text to the outfile.1  
 */

#include <fstream>
#include <map>
#include <cctype>
#include <string>
#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{
  //Create a map to store the command line argument values
  map<argsEnum, string> parseResults;

  //Call the cmdParser to parse the command line and store the values in the map
  cmdParser(parseResults, argc, argv);
	
  //Open the input and output files using the names stored in the map
	ifstream inputFile(parseResults[INFILE].c_str());
	ofstream outputFile(parseResults[OUTFILE].c_str());
	string line = "";

	//Make sure the input file is open
	  if(inputFile.is_open())
	    {
	      //While there is a line to be read in the input file
	      while(getline(inputFile, line))
		{

		  //If the lowercase flag is set, convert all text to lowercase and print it to the outfile
	  if(parseResults[LOWER] == "1")
		    {
		      for(int i = 0;  i < line.length(); i++)
			{
			  char c = line[i];		   
			  c = (char) tolower(c);
			  outputFile << c; 
		    
			}
		    }
	  ///If the uppercase flag is set, set all the text to uppercase and print it to the outfile
		  else if(parseResults[UPPER] == "1")
		    {
		      for(int i = 0;  i < line.length(); i++)
			{
			  char c = line[i];
			  c = (char) toupper(c);
			  outputFile << c;
			} 
		    }
	  //If no flags set for the text, print the text as is to the uppercase file
		  else
		    {
		      outputFile << line;
		    } 
		  outputFile << "\r\n";
		}
	    }
	  //Close the input and output files
	inputFile.close(); 
	outputFile.close();      
      

      return 0;
}
