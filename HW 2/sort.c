/*************************************************************************
Name: sort.c
Date: 11 February 2022
Course Section: CS 392-C
Author: Barry A. Diaz
Description: Using the merge sort algorithm from contents of a  file using 
             pointers, pointer arrays using dynamic allocation, pointer arithmetics,
             and multiple files.
Pledge: I pledge my honor that I have abided by the Stevens Honor System.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>
#include "mergesort.h"

// Called when only the executable command is called or unknown option is entered via terminal
void help() {
  fprintf(stderr, "Usage: ./sort [-i|-d] filename\n"
                  "-i: Specifies the file contains ints.\n"
                  "-d: Specifies the file contains doubles.\n"
                  "filename: The file to sort.\n");
}

int main(int argc, char *argv[]) {
    // If only the executable command is called
    if(argc == 1) {
        help();
        return EXIT_FAILURE;
    }
    
    // Create initial vairables and pointers
    FILE* fp;
    int opt;
    int flag1 = 0, flag2 = 0, count = 0;
    char* msg = (char*)malloc(sizeof(char) * 1024);

    // Using the getopts library to iterate the flags entered from the terminal
    while ((opt = getopt(argc, argv, ":id")) != -1) {
     switch (opt) 
     {
      case 'i':
        flag1++; // Increment 'i' flag counter
        break;
      case 'd':
        flag2++; // Increment 'd' flag counter
        break;
      case '?':
        free(msg);
        fprintf(stderr, "Error: Unknown option \'-%c\' specified.\n", optopt);
        help();
        return EXIT_FAILURE;
     }
  }

  // Verifies the sum of both flag counters doesn't equal 0.
  // (This test will not be tested for assignment but in case only a file is given as an argument)
  if(flag1 + flag2 == 0) {
      free(msg);
      fprintf(stderr, "Error: No flags specified.\n");
      return EXIT_FAILURE;
  }

  // Verifies the sum isn't greater than 1
  if(flag1 + flag2 > 1) {
      free(msg);
      fprintf(stderr, "Error: Too many flags specified.\n");
      return EXIT_FAILURE;
  }
  
  // Runs if flag1 equals 1
  if(flag1 == 1) {
    // Verifies only ONE file is entered through terminal
    if(argv[2] == NULL) {
      free(msg);
      fprintf(stderr, "Error: No input file specified.\n");
      return EXIT_FAILURE;
    }
    else if(argv[3] != NULL) {
      free(msg);
      fprintf(stderr, "Error: Too many files specified.\n");
      return EXIT_FAILURE;
    }
    // Open the file
    else if ((fp = fopen(argv[2], "r")) == NULL) {
      free(msg);
      fprintf(stderr, "Error: Cannot open \'%s\'. %s.\n", argv[2], strerror(errno));
      return EXIT_FAILURE;
    }
    else {
      // Allocation (use fgets)
      int* int_array = (int*)malloc(sizeof(int) * 1024);
      
      // Transferring file content into integer array
      while (fgets(msg, 1024, fp) != NULL) {
        int_array[count] = atoi(msg);
        count++;
      }

      // Calling mergesort function with int_cmp as compare function
      size_t size = sizeof(int);
      mergesort(int_array, count, size, int_cmp);

      // Printing output of int_array
      for(int i = 0; i < count; i++) {
        printf("%d\n", int_array[i]);
      }

      // Freeing memory
      free(int_array);
    }
  }

  // Runs if flag2 equals 1
  if(flag2 == 1) {
    // Verifies only ONE file is entered through terminal
    if(argv[2] == NULL) {
      free(msg);
      fprintf(stderr, "Error: No input file specified.\n");
      return EXIT_FAILURE;
    }
    else if(argv[3] != NULL) {
      free(msg);
      fprintf(stderr, "Error: Too many files specified.\n");
      return EXIT_FAILURE;
    }
    // Open the file
    else if ((fp = fopen(argv[2], "r")) == NULL) {
      free(msg);
      fprintf(stderr, "Error: Cannot open \'%s\'. %s.\n", argv[2], strerror(errno));
      return EXIT_FAILURE;
    }
    else {
      // Allocation (use fgets)
      double* dbl_array = (double*)malloc(sizeof(double) * 1024);
      while (fgets(msg, 1024, fp) != NULL) {
        dbl_array[count] = atof(msg);
        count++;
      }

      // Calling mergesort function with dbl_cmp as the compare function
      size_t size = sizeof(double);
      mergesort(dbl_array, count, size, dbl_cmp);

      // Printing output of dbl_array
      for(int i = 0; i < count; i++) {
        printf("%f\n", dbl_array[i]);
      }
      // Freeing memory
      free(dbl_array);
    }
  }
  // Closing file, freeing memory in msg, and returning 0
  fclose(fp);
  free(msg);
  return 0;
}