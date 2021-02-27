#! /usr/bin/env python3

"""
This utility is useful to generate almost sorted, fully sorted,
reverse sorted, almost reverse sorted and other controlled 
random sequences with multiple occurences of the same number. 
Allows user to create files with random permutations of distinct
integers. we start with a sorted list and give user the control 
as to how many random permutations they would like
"""

import argparse
import sys
import random

def parse_arguments():
    parser = argparse.ArgumentParser(description="Generates a random sequence of"
                                     + " distinct integers, one per line")
    parser.add_argument("num_ints", help="number of integers in the output", type=int)
    parser.add_argument("swaps",
                        help="number of random swaps as a percentage of num_ints; For num_ints = 200, swaps = 10 would result in 20 random swaps from the sorted array",
                        type=int)
    parser.add_argument("min_occurrences",
                        help="minimum number of occurrences of a distinct value",
                        type=int)
    parser.add_argument("max_occurrences",
                        help="maximum number of occurrences of a distinct value",
                        type=int)
    
    parser.add_argument("-s", "--seed",
                        help="random seed; if not specified, system clock is used",
                        type=int)
    parser.add_argument("-r", "--reverse",
                        help="if true, resultant sequence is reversed before returning",
                        type=bool)
    
    args = parser.parse_args()
    return args
                      

if __name__ == '__main__':
    args = parse_arguments()
    num_ints = args.num_ints
    swaps = args.swaps
    num_swaps = int(swaps * num_ints / 100)
    reverse = args.reverse

    min_occurrences = args.min_occurrences
    max_occurrences = args.max_occurrences

    if not args.seed:
        pass
        random.seed(5)
    else:
        random.seed(args.seed)
    
    int_list = []
    
    curr_number = 1
    while len(int_list) < num_ints:
        occur = random.randint(min_occurrences, max_occurrences)

        int_list.extend([curr_number for i in range(occur)])
        curr_number +=1

    int_list = int_list[:num_ints]
    assert len(int_list) == num_ints
    for i in range(num_swaps):
        a = random.randint(0, num_ints-1)
        b = random.randint(0, num_ints-1)
        
        int_list[a], int_list[b] = int_list[b], int_list[a]


    if reverse:
        int_list.reverse()
    for i in int_list:
        print(i)

