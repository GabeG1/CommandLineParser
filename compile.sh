#!/usr/bin/bash

 #                                                                              
 #Filename        compile.sh
 #Date            2/6/19
 #Author          Gabriel Goldstein                                             
 #Email           gjg180000@utdallas.edu                                        
 #Course          CS 3377.502 Spring 2019                                       
 #Version         1.0                                                           
 #Copyright 2019, All Rights Reserved                                           
 #                                                                              
 #Description           
 #                                                                              
 # Compile and Link the files file.cc and comandParser.cc, making sure to use the flag -I in order to indicate where to find the tclap header files     
 #

#Compile file.cc
g++ -c file.cc
#Compile commandLineParser.cc
g++ -I ~/include commandLineParser.cc  -c commandLineParser.cc
#Linke file.cc and commandLineParser.cc to program2
g++ -I ~/include file.cc commandLineParser.cc -o program2
