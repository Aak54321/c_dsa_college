#include <stdio.h>
#include <stdlib.h>
//initializing a node
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
//declaring some useful pointers for list creation
struct node *start, *newnode, *ptr;
/*This is list_generator function creates a list with descending order of the exponents of a polynomial equation*/
struct node *list_generator(struct node *start, int coeff, int exp)
{
    /*creating a newnode and placing the values inside it*/
    newnode = (struct node *)malloc(sizeof(struct node)); // 👈 node creation
    newnode->coeff = coeff;                               // 👈placing coefficient
    newnode->exp = exp;                                   // 👈placing exponent
    newnode->next = NULL;                                 // 👈placing the next of a newnode as NULL(⭐as a default varies in some cases)

    /*  THINGS TO CONSIDER
    (i)if the created term is the very first term in list or it's exp is bigger than the first term which persists in the list
    (ii)else if the created term is smaller than the first term in the list but is bigger than any of the term in the list
    */
    /*implementation of case(i) by insertion at beginning*/
    if (start == NULL || exp > start->exp)
    {
        newnode->next = start; /*👈 varies here*/
        start = newnode;
    }
    // implementation of case(ii) by insertion at a specific place
    else
    {
        /*initializing ptr to start*/
        ptr = start;
        /*traversing till the ptr reaches the last node and the exponent of the term should be greater than the exponent of the created term*/
        while (ptr->next != NULL /*condition for reaching last node*/ && ptr->next->exp > exp /*condition for checking the exponent of the term*/)
        {
            ptr = ptr->next;
        }
        /*once the desired location is reached link the new node after it*/
        newnode->next = ptr->next; /*varies here👈*/
        ptr->next = newnode;
    }
    return start; /*returning start to manipulate the created list*/
}
struct node *create_term(struct node *start)
{
    /*creating a newnode with a while loop with 1/0 choice system*/
    int flag = 1;
    while (flag != 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the coefficient:");
        scanf("%d", &newnode->coeff);
        printf("\nEnter the exponent:");
        scanf("%d", &newnode->exp);
        start = list_generator(start, newnode->coeff, newnode->exp);
        printf("\nIf you want to continue press '1' or '0' to end:");
        scanf("%d", &flag);
    }
    return start; /*returning start to manipulate the created list*/
}
// function to add two polynomials
struct node *add_poly(struct node *start1, struct node *start2, struct node *add_result)
{
    struct node *ptr1, *ptr2;
    /*declaring two pointers useful for list traversal*/
    ptr1 = start1;
    ptr2 = start2;
    /*traverse through both the polynomials until any one of the becomes null*/
    while (ptr1 != NULL && ptr2 != NULL)
    {
        /*checking if both the exponents are equal. if true add them*/
        if (ptr1->exp == ptr2->exp)
        {
            int num_sum = ptr1->coeff + ptr2->coeff;
            // now move this to list_generator and equate the start pointer to add result
            add_result = list_generator(add_result, num_sum, ptr1->exp /*it can also be ptr2->exp*/);
            /*update both the pointer to the next node*/
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        /*else if the check exponent of first term is greater than the second one. if true move the first term to result*/
        else if (ptr1->exp > ptr2->exp)
        {
            // move this to list_generator and equate the start pointer to add result
            add_result = list_generator(add_result, ptr1->coeff, ptr1->exp);
            // update only the ptr1 for further comparisons
            ptr1 = ptr1->next;
        }
        /*else if the check exponent of second term is greater than the first one. if true move the second term to result*/
        else if (ptr1->exp < ptr2->exp)
        {
            // move this to list_generator and equate the start pointer to add result
            add_result = list_generator(add_result, ptr2->coeff, ptr2->exp);
            // update only the ptr2 for further comparisons
            ptr2 = ptr2->next;
        }
    }
    /*any one of two possibilities arises after the traversal
    (i)polynomial 1's pointer ptr1 becomes null,as it reached the end of first polynomial
    (ii)polynomials 2's pointer ptr2 becomes null,as it  reached the end of second polynomial
    */
    // addressing case(i)
    if (ptr1 == NULL)
    {
        // moving all the remaining contents of polynomial to the result linked list
        while (ptr2 != NULL)
        {
            add_result = list_generator(add_result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    // addressing case(ii)
    if (ptr2 == NULL)
    {
        // moving all the remaining contents of polynomial to the result linked list
        while (ptr1 != NULL)
        {
            add_result = list_generator(add_result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return add_result; /*this is the start pointer of the added polynomial's linked list*/
}
// function to subtract polynomial 2 from polynomial 1 (polynomial 1 - polynomial 2)(⭐ Exactly Same as Addition logic only subtracting the coefficients)
struct node *sub_poly(struct node *start1, struct node *start2, struct node *sub_result)
{
    struct node *ptr1, *ptr2;
    ptr1 = start1;
    ptr2 = start2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            int diff_num;
            /*Only change👇*/
            diff_num = ptr1->coeff - ptr2->coeff;
            sub_result = list_generator(sub_result, diff_num, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            sub_result = list_generator(sub_result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            sub_result = list_generator(sub_result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            sub_result = list_generator(sub_result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            sub_result = list_generator(sub_result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return sub_result;
}
void display(struct node *start)
{
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->exp == 0)
        {
            printf("%d", ptr->coeff);
        }
        else
        {
            printf("%dx^%d", ptr->coeff, ptr->exp);
        }
        if (ptr->next != NULL)
        {
            if (ptr->next->coeff < 0)
                printf("");

            else
                printf("+");
        }
        ptr = ptr->next;
    }
}
void main()
{
    struct node *start1 = NULL, *start2 = NULL, *add_res = NULL, *sub_res = NULL;
    int choice;
    printf("\n*************MAIN MENU***************");
    printf("\nEnter 1 to create first Polynomial");
    printf("\nEnter 2 to create second polynomial");
    printf("\nEnter 3 to add two polynomials");
    printf("\nEnter 4 to subtract two polynomials");
    printf("\nEnter 5 to exit");
    do
    {
        printf("\n\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start1 = create_term(start1);
            printf("\nYour First Polynomial is:");
            display(start1);
            printf("\n");
            break;
        case 2:
            start2 = create_term(start2);
            printf("\nYour Second Polynomial is:");
            display(start2);
            printf("\n");
            break;
        case 3:
            add_res = add_poly(start1, start2, add_res);
            printf("\nYour added polynomial is:");
            display(add_res);
            printf("\n");
            break;
        case 4:
            sub_res = sub_poly(start1, start2, sub_res);
            printf("\nYour subtracted polynomial is:");
            display(sub_res);
            printf("\n");
            break;
        }
    } while (choice != 5);
    char quer[100];
    printf("\nDo you know Why Polynomial Tree Fell Down?(What's your Idea)\n");
    scanf("%s", quer);
    printf("\nBecause It doesn't have real roots :)\n");
}