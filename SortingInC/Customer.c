//
//  Customer.c
//  SortingInC
//
//  Created by Panayotis Matsinopoulos on 10/7/21.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Customer.h"

CustomerRef CreateCustomer(const char *iFirstName, const char *iLastName) {
  CustomerRef result = NULL;
  
  if (!iFirstName && !iLastName) {
    return result;
  }
  
  result = malloc(sizeof(Customer));
  
  unsigned long sizeOfBuffer = 0;
  if (iFirstName) {
    sizeOfBuffer = sizeof(char) * (strlen(iFirstName) + 1);
    result->firstName = malloc(sizeOfBuffer);
    memset(result->firstName, 0, sizeOfBuffer);
    strcpy(result->firstName, iFirstName);
  }
  else {
    result->firstName = NULL;
  }
  
  if (iLastName) {
    sizeOfBuffer = sizeof(char) * (strlen(iLastName) + 1);
    result->lastName = malloc(sizeOfBuffer);
    memset(result->lastName, 0, sizeOfBuffer);
    strcpy(result->lastName, iLastName);
  }
  else {
    result->lastName = NULL;
  }
  return result;
}

void DestroyCustomer(CustomerRef *oCustomer) {
  if (oCustomer && *oCustomer) {
    if ((*oCustomer)->firstName) {
      free((*oCustomer)->firstName);
      (*oCustomer)->firstName = NULL;
    }
    if ((*oCustomer)->lastName) {
      free((*oCustomer)->lastName);
      (*oCustomer)->lastName = NULL;
    }
    free(*oCustomer);
    *oCustomer = NULL;
  }
}

char *CustomerFullNameCString(CustomerRef iCustomer) {
  if (!iCustomer) {
    return NULL;
  }
  
  size_t bufferSize = (strlen(iCustomer->lastName) + 1 + strlen(iCustomer->firstName) + 1) * sizeof(char);
  char *result = malloc(bufferSize);
  memset((void *)result, 0, bufferSize);
  
  sprintf((char *)result, "%s %s", iCustomer->lastName, iCustomer->firstName);
  
  return result;
}

// follows the prototype that "qsort()" prescribes for the comparison function
int CustomerComparison(const void *aCustomer, const void *bCustomer) {
  CustomerRef a = *(CustomerRef *)aCustomer;
  CustomerRef b = *(CustomerRef *)bCustomer;
  
  char *fullNameA = CustomerFullNameCString(a);
  char *fullNameB = CustomerFullNameCString(b);
  
  if (!fullNameA && !fullNameB) {
    return 0;
  }
  if (fullNameA && !fullNameB) {
    return -1;
  }
  if (!fullNameA && fullNameB) {
    return 1;
  }
  
  int result = strcmp(fullNameA, fullNameB);
  
  if (fullNameA) {
    free((void *)fullNameA);
  }
  if (fullNameB) {
    free((void *)fullNameB);
  }
  
  return result;
}

void PrintCustomers(CustomerRef customers[], size_t numberOfCustomers) {
  for(size_t i = 0; i < numberOfCustomers; i++) {
    char *fullName = CustomerFullNameCString(customers[i]);
    printf("Customer %lu: %s\n", i, fullName);
    free(fullName);
  }
}

