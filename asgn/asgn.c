#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"
#include "htable.h"
#include "rbt.h"
#include "container.h"
#include <time.h>
#include <getopt.h>

/*
 * COSC242 Assignment
 * Authors: Sophie Purdie, Amanda Veldman, Kiri Lenagh-Glue
 */

/* Additional style settings for Help menu */
#define BOLD "\033[1m"  /* Set text style to bold */
#define RESET "\033[0m"     /* Reset text style to default */


/*
 * This function creates an htable of containers (either flexarrays or 
 * red-black trees), and fills it with strings read from a file. The function
 * will read strings from STDIN, and will print out the strings not found in 
 * the htable to STDOUT.
 * Various commands are available to the user. This function will deallocate 
 * all memory before finishing. 
 *
 * @param argc: The number of command line arguments
 * @param argv: An array of strings that holds the command line arguments
 *
 * @return: The exit status of the program, either EXIT_SUCCESS or 
 * EXIT_FALIURE
 */
int main(int argc, char **argv){
    container_t type = FLEX_ARRAY;
    htable ht = NULL;
    const char *optstring = "rs:pih";
    char word[256];
    
    int table_size = 3877;
    char option;
    FILE *stream;
    clock_t start, end;
    
    int print_option = 0;
    int info_option = 0;

    double search_time= 0.0;
    double fill_time = 0.0;
    int unknown = 0;
    
    while ((option = getopt(argc, argv, optstring)) != EOF){
        switch(option){
            case 'r':
                type = RED_BLACK_TREE;
                break;
            case 's':
                table_size = atoi(optarg);
                break;
            case 'p':
                print_option = 1;
                break;
            case 'i':
                info_option = 1;
                break;
            case 'h':
                fprintf(stderr, BOLD "\nName:" RESET);
                fprintf(stderr, " Basic Dictionary Search Program\n\n");
                fprintf(stderr, BOLD "Dictionary Search Options:\n\t");
                fprintf(stderr, RESET "Include any of the following ");
                fprintf(stderr, "command-line options when\n\trunning the ");
                fprintf(stderr, "program to customize dictionary search.\n\n");
                fprintf(stderr, BOLD"\t-h --help\n\t" RESET);
                fprintf(stderr, "\tDisplay the help menu.\n\n\t");
                fprintf(stderr, BOLD "-r --robust\n\t" RESET);
                fprintf(stderr, "\tUse robust chaining method,\n\t");
                fprintf(stderr, "\t(sets container type to red-black tree).");
                fprintf(stderr, "\n\n\t");
                fprintf(stderr, BOLD "-s <table-size> [default: 3877]\n\t");
                fprintf(stderr, RESET "\tSet the hash table size.\n\t\tThe ");
                fprintf(stderr, "hash-table size is 3877 by default.\n\n\t");
                fprintf(stderr, BOLD "-p --print\n\t" RESET);
                fprintf(stderr, "\tPrint hash table.\n\n\t");
                fprintf(stderr, BOLD "-i --info\n\t" RESET);
                fprintf(stderr, "\tPrint information on hash table fill ");
                fprintf(stderr, "time,\n\t\tsearch time & number of unknown");
                fprintf(stderr, " words found.\n\n");
                fprintf(stderr, BOLD"Authors:\n\t"RESET"Sophie Purdie, Amanda");
                fprintf(stderr, " Veldman, Kiri Lenagh-Glue\n\n"); 
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Option not recognised, type -h for help.");
                return EXIT_FAILURE;
        }
    }

    ht = htable_new(table_size, type);

    start = clock();
    stream = fopen(argv[optind], "r"); 
    if (stream == NULL){
        fprintf(stderr, "Error: no file specified");
        return EXIT_FAILURE;
    }

    while(getword(word, sizeof word, stream) != EOF){
        htable_insert(ht, word);
    }
    end = clock();
    fill_time = (end-start)/(double)CLOCKS_PER_SEC;
    fclose(stream);

    if (print_option){
        htable_print(ht);
        htable_free(ht);
        return EXIT_SUCCESS;
        
    } else {
        start = clock();
        while(getword(word, sizeof word, stdin) != EOF){
            int found = htable_search(ht, word);
            if (found == 0 && print_option == 0){
                fprintf(stdout, "%s\n", word);
                unknown++;
            }
        }
        end = clock();
        search_time = (end-start)/(double)CLOCKS_PER_SEC;

        if (info_option){
            fprintf(stderr, BOLD"Fill time:"RESET"\t%f\n",fill_time);
            fprintf(stderr, BOLD"Search time:"RESET"\t%f\n", search_time);
            fprintf(stderr, BOLD"Unknown words:"RESET"\t%d\n", unknown);

        }
    }

    htable_free(ht);
    return EXIT_SUCCESS;
}
