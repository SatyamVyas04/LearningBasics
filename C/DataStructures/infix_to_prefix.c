/*
 * File: infix_to_prefix.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program converts an infix expression to prefix (polish
 * notation)
 */

#include <string.h>

#include "helper_functions.c"
#include "stack.c"

// precedence map
// 1-> highest ; 4 -> lowest
// ^ -> 1
// *, / -> 2
// +, - -> 3
// others -> 4

struct Stack* infix_to_prefix(char* expression) {
  struct Stack* stack = initialize_stack(100);
  struct Stack* prefix = initialize_stack(100);

  for (int i = sizeof(expression) / sizeof(char) - 1; i >= 0; i--) {
    char current = expression[i];
    if (is_operator(current) == 1 || current == ")") {
      push(stack, current);
    } else if (65 <= current <= 90) {
      push(prefix, current);
    } else {
      char popped;
      popped = pop(stack);
      pop(stack);  // Extra bracket removed
      push(prefix, popped);
    }
  }
  return prefix;
}

void main() {
  char str[100];
  printf("> Enter the Infix Expression: ");
  scanf("%[^\n]s", str);
  printf("%s", str);
  struct Stack* prefix = infix_to_prefix(&exp);
  display(prefix);
}
