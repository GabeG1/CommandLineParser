
/*
 *Filename        header.h
 *Date            2/6/19
 *Author          Gabriel Goldstein
 *Email           gjg180000@utdallas.edu
 *Course          CS 3377.502 Spring 2019
 *Version         1.0
 *Copyright 2019, All Rights Reserved
 *
 *Description
 *
 *     Stores the enum and the cmdParser function prototype, the latter of which is implemented in the file commandLineParser
 */



#include <map>
#include <string>

//Create an enum that has the names of the flags as the variables
enum argsEnum{ LOWER, UPPER, OUTFILE, INFILE };

//cmdParser function prototype
void cmdParser(std::map<argsEnum, std::string>&, int, char**);
