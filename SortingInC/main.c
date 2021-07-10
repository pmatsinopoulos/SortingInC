//
//  main.c
//  SortingInC
//
//  Created by Panayotis Matsinopoulos on 10/7/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

int main(int argc, const char * argv[]) {
  const int numberOfCustomers = 3;
  
  CustomerRef customers[numberOfCustomers] = {
    CreateCustomer("Peter", "Pan"),
    CreateCustomer("Mary", "Foo"),
    CreateCustomer("John", "Woo")
  };

  PrintCustomers(customers, numberOfCustomers);
  
  qsort(customers, numberOfCustomers, sizeof(CustomerRef), CustomerComparison);
  
  printf("After sorting:\n");
  
  PrintCustomers(customers, numberOfCustomers);
  
  for(int i = 0; i < numberOfCustomers; i++) {
    DestroyCustomer(&customers[i]);
  }
  
  printf("Bye!\n");
  
  return 0;
}
