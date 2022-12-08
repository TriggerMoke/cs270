#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Debug.h"
#include "symbol.h"

/** @file symbol.c
 *  @brief You will modify this file and implement the symbol.h interface
 *  @details Your implementation of the functions defined in symbol.h.
 *  You may add other functions if you find it helpful. Added functions
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file. The reference implementation added approximately
 *  110 lines of code to this file. This count includes lines containing
 *  only a single closing bracket (}).
 * <p>
 * @author <b>Your name</b> goes here
 */

/** size of LC3 memory */
#define LC3_MEMORY_SIZE  (1 << 16)
//calloc(LC3MEM, sizeof(char*))

/*
  P4A
    init capacity
    add name address
    list
    count
    exit/quit

    symbol_init()
    symbol_add()
    symbol_iterate()
    symbol_search()
*/


/** Provide prototype for strdup() */
char *strdup(const char *s);

/** defines data structure used to store nodes in hash table */
typedef struct node {
  struct node* next;     /**< linked list of symbols at same index */
  int          hash;     /**< hash value - makes searching faster  */
  symbol_t     symbol;   /**< the data the user is interested in   */
} node_t;

/** defines the data structure for the hash table */
struct sym_table {
  int      capacity;    /**< length of hast_table array                  */
  int      size;        /**< number of symbols (may exceed capacity)     */
  node_t** hash_table;  /**< array of head of linked list for this index */
  char**   addr_table;  /**< look up symbols by addr                     */
};

/** djb hash - found at http://www.cse.yorku.ca/~oz/hash.html
 * tolower() call to make case insensitive.
 */

static int symbol_hash (const char* name) {
  unsigned char* str  = (unsigned char*) name;
  unsigned long  hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */

  c = hash & 0x7FFFFFFF; /* keep 31 bits - avoid negative values */

  return c;
}

/** @todo implement this function */
sym_table_t* symbol_init (int capacity) {
  sym_table_t *tab = calloc(1, sizeof(sym_table_t));
  tab -> hash_table = calloc(capacity, sizeof(node_t*));
  tab -> addr_table = calloc(LC3_MEMORY_SIZE, sizeof(char));
  tab -> size = capacity;
  return tab;
}

/** @todo implement this function */
void symbol_term (sym_table_t* symTab) {

}

/** @todo implement this function */
void symbol_reset(sym_table_t* symTab) {
}

/** @todo implement this function */
int symbol_add (sym_table_t* symTab, const char* name, int addr) {

  if(symTab -> addr_table[addr] != NULL)
    return 0;

  symbol_t sym;
  sym.name = strdup(name);
  sym.addr = addr;

  int hash = symbol_hash(strdup(name));
  int temp = hash % (symTab -> size);

  node_t* curr = symTab -> hash_table[temp];
  node_t* newNode = calloc(1, sizeof(node_t));

  newNode -> next = curr;
  newNode -> hash = hash;
  newNode -> symbol = sym;

  symTab -> hash_table[temp] = newNode;

  
  
  //else

  

  return 0;
}

/** @todo implement this function */
struct node* symbol_search (sym_table_t* symTab, const char* name, int* hash, int* index) {
  *hash = symbol_hash(name);
  return NULL;
}

/** @todo implement this function */
symbol_t* symbol_find_by_name (sym_table_t* symTab, const char* name) {
  //symbol_search();
  return NULL;

}

/** @todo implement this function */
char* symbol_find_by_addr (sym_table_t* symTab, int addr) {
  return symTab -> addr_table[addr];
}

/** @todo implement this function */
void symbol_iterate (sym_table_t* symTab, iterate_fnc_t fnc, void* data) {
  for(int i = 0; i < symTab -> size; i++){
    node_t* current = symTab -> hash_table[i];
    while(current != NULL){
      node_t* temp = current;
      (*fnc)(&(temp -> symbol), data);
      current = current -> next;
    }
  }
}

/** @todo implement this function */
int symbol_size (sym_table_t* symTab) {
  return 0;
}

/** @todo implement this function */
int compare_names (const void* vp1, const void* vp2) {
  symbol_t* sym1 = *((symbol_t**) vp1); // study qsort to understand this
  symbol_t* sym2 = *((symbol_t**) vp2);

  return qsort(sym1, sym2);
}

/** @todo implement this function */
int compare_addresses (const void* vp1, const void* vp2) {
  return 0;
}

/** @todo implement this function */
symbol_t** symbol_order (sym_table_t* symTab, int order) {
  // will call qsort with either compare_names or compare_addresses
  symbol_t** symArr = calloc(order,sizeof(symbol_t*));
  //Loops: Add -> symArr
  if(order == 0){
    qsort();
  }
  else if (order == 1)
  {
    qsort();
  }
  
  return symArr;
}

