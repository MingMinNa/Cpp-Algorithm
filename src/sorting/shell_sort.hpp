#ifndef ALGO_SHELL_SORT
#define ALGO_SHELL_SORT

#include "../algo_utils.hpp"
#include <vector>
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

// Pratt Gap seqeunces is 3-smooth numbers.
// the sequence below doesn't contain all Pratt gap sequences, but enough.
const std::vector<uint64_t> PRATT_GAP_SEQUENCE = {
    1llu, 	2llu, 	3llu, 	4llu, 	6llu, 	8llu, 	9llu, 	12llu, 	16llu, 	18llu, 	24llu, 	27llu, 	32llu, 	36llu, 	48llu, 	54llu, 	64llu, 	72llu, 	81llu, 	96llu, 	
    108llu, 	128llu, 	144llu, 	162llu, 	192llu, 	216llu, 	243llu, 	256llu, 	288llu, 	324llu, 	384llu, 	432llu, 	486llu, 	512llu, 	576llu, 	648llu, 	729llu, 	768llu, 	864llu, 	972llu, 	
    1024llu, 	1152llu, 	1296llu, 	1458llu, 	1536llu, 	1728llu, 	1944llu, 	2048llu, 	2187llu, 	2304llu, 	2592llu, 	2916llu, 	3072llu, 	3456llu, 	3888llu, 	4096llu, 	4374llu, 	4608llu, 	5184llu, 	5832llu, 	
    6144llu, 	6561llu, 	6912llu, 	7776llu, 	8192llu, 	8748llu, 	9216llu, 	10368llu, 	11664llu, 	12288llu, 	13122llu, 	13824llu, 	15552llu, 	16384llu, 	17496llu, 	18432llu, 	19683llu, 	20736llu, 	23328llu, 	24576llu, 	
    26244llu, 	27648llu, 	31104llu, 	32768llu, 	34992llu, 	36864llu, 	39366llu, 	41472llu, 	46656llu, 	49152llu, 	52488llu, 	55296llu, 	59049llu, 	62208llu, 	65536llu, 	69984llu, 	73728llu, 	78732llu, 	82944llu, 	93312llu, 	
    98304llu, 	104976llu, 	110592llu, 	118098llu, 	124416llu, 	131072llu, 	139968llu, 	147456llu, 	157464llu, 	165888llu, 	177147llu, 	186624llu, 	196608llu, 	209952llu, 	221184llu, 	236196llu, 	248832llu, 	262144llu, 	279936llu, 	294912llu, 	
    314928llu, 	331776llu, 	354294llu, 	373248llu, 	393216llu, 	419904llu, 	442368llu, 	472392llu, 	497664llu, 	524288llu, 	531441llu, 	559872llu, 	589824llu, 	629856llu, 	663552llu, 	708588llu, 	746496llu, 	786432llu, 	839808llu, 	884736llu
};

template <HasCompareOps T, typename Compare = std::less<T>>
void shell_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "shell_sort.tpp"

#endif