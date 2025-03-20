#include "unity.h"
#include <stdio.h>
#include <stdlib.h>

// ANSI color definitions for terminal output
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED   "\033[1;31m"
#define COLOR_RESET "\033[0m"

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to add two numbers represented as linked lists.
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        int digit = sum % 10;
        
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        if (!newNode) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        newNode->val = digit;
        newNode->next = NULL;
        
        tail->next = newNode;
        tail = newNode;
    }
    return dummy.next;
}

// Helper function to create a linked list from an array.
struct ListNode* createList(int* arr, int size) {
    if (size <= 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    if (!head) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    head->val = arr[0];
    head->next = NULL;
    
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        if (!newNode) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        newNode->val = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return head;
}

// Helper function to free a linked list.
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Helper function to print a linked list.
void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next)
            printf(", ");
        head = head->next;
    }
    printf("]");
}

// Helper function to compare a linked list to an array.
// Returns 1 if equal, 0 otherwise.
int listEqual(struct ListNode* head, int* arr, int size) {
    int i = 0;
    while (head && i < size) {
        if (head->val != arr[i])
            return 0;
        head = head->next;
        i++;
    }
    return (head == NULL && i == size);
}

// Unity setUp and tearDown functions.
void setUp(void) { }
void tearDown(void) { }

// Test Case 1: [2,4,3] + [5,6,4] = [7,0,8]
void test_AddTwoNumbers_Case1(void) {
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int expected[] = {7, 0, 8};
    
    struct ListNode* l1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    struct ListNode* l2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    TEST_ASSERT_TRUE_MESSAGE(listEqual(result, expected, sizeof(expected) / sizeof(expected[0])),
                             "Case 1 failed: Result list doesn't match expected output.");
    printf(COLOR_GREEN "Case 1 PASSED: " COLOR_RESET);
    printList(result);
    printf("\n");
    
    freeList(l1);
    freeList(l2);
    freeList(result);
}

// Test Case 2: [0] + [0] = [0]
void test_AddTwoNumbers_Case2(void) {
    int arr1[] = {0};
    int arr2[] = {0};
    int expected[] = {0};
    
    struct ListNode* l1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    struct ListNode* l2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    TEST_ASSERT_TRUE_MESSAGE(listEqual(result, expected, sizeof(expected) / sizeof(expected[0])),
                             "Case 2 failed: Result list doesn't match expected output.");
    printf(COLOR_GREEN "Case 2 PASSED: " COLOR_RESET);
    printList(result);
    printf("\n");
    
    freeList(l1);
    freeList(l2);
    freeList(result);
}

// Test Case 3: [9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]
void test_AddTwoNumbers_Case3(void) {
    int arr1[] = {9, 9, 9, 9, 9, 9, 9};
    int arr2[] = {9, 9, 9, 9};
    int expected[] = {8, 9, 9, 9, 0, 0, 0, 1};
    
    struct ListNode* l1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    struct ListNode* l2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    TEST_ASSERT_TRUE_MESSAGE(listEqual(result, expected, sizeof(expected) / sizeof(expected[0])),
                             "Case 3 failed: Result list doesn't match expected output.");
    printf(COLOR_GREEN "Case 3 PASSED: " COLOR_RESET);
    printList(result);
    printf("\n");
    
    freeList(l1);
    freeList(l2);
    freeList(result);
}

// Main function running Unity tests.
int app_main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_AddTwoNumbers_Case1);
    RUN_TEST(test_AddTwoNumbers_Case2);
    RUN_TEST(test_AddTwoNumbers_Case3);
    return UNITY_END();
}
