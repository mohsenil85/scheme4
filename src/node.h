#ifndef NODE_H
#define NODE_H
typedef long double number_t  ;

typedef enum type_t {
  t_string,
  t_number,
  t_delim,
  t_fun
} type_t;
typedef struct Node {
  number_t* idata;
  char * cdata;
  type_t;
  
  struct Node* next;
} Node;

#endif /* NODE_H */
