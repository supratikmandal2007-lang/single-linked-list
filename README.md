# Singly Linked List — C Implementation
A menu-driven implementation of a singly linked list in C, covering the full
standard set of operations through a consistent nd** (pointer-to-pointer)
interface.
Features
Create a list interactively
Insert at the beginning, at the end, after a specific value, or after a
specific position
Delete from the beginning, from the end, a specific value, or a specific
position
Traverse and print the list
Count the number of nodes
Linear search by value
Design notes
Every mutating function takes nd** rather than nd*, so the head pointer
itself can be updated (e.g. when inserting/deleting at the beginning)
without needing special-case code paths outside the function.
find_insert_point() is a single lookup function used by both
value-based and position-based operations. It returns the node before
the target in both modes ('K' for key/value, 'P' for position), so
del_pos() and insert_after() can consume its result the same way
regardless of how the target was located.
A NULL return from find_insert_point() means "no previous node" —
which happens when the target is the head of the list, or when the
target value doesn't exist. Callers check for the head case explicitly
(start->data == key) before treating NULL as "not found."
Build
Bash
Menu
Code
Status
Core list operations (insert/delete at head, tail, by value, by position;
traversal; search) are implemented and working. See commit history for the
debugging process.
