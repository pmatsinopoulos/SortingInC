//
//  Customer.h
//  SortingInC
//
//  Created by Panayotis Matsinopoulos on 10/7/21.
//

#ifndef Customer_h
#define Customer_h

typedef struct {
  char *firstName;
  char *lastName;
} Customer;
typedef Customer * CustomerRef;

CustomerRef CreateCustomer(const char *iFirstName, const char *iLastName);
void DestroyCustomer(CustomerRef *oCustomer);
int CustomerComparison(const void *aCustomer, const void *bCustomer);
char *CustomerFullNameCString(CustomerRef iCustomer);
void PrintCustomers(CustomerRef customers[], size_t numberOfCustomers);
#endif /* Customer_h */
