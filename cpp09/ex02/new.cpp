/* BEFORE SORTING

1. insert numbers into container

2. start recursive sort*/




/*

RECURSIVE SORT FUNCTION

// BASE CASE: only 1 pair left

1. make pairs
    - check for leftover, isolate and put it aside

2. sort within the pairs

3. call the recursive sort function again with level +1 (power * 2)

4. split the pairs into main chain (bigger elements) and pend chain (smaller elements)

5. use binary search to insert the pend chain elements into the main chain
    - insert B1 at the beginning of main chain
    - insert according to jacobsthal sequence
        - insert B3 into main chain: { B1, A1, A2, A3 }
        - insert B2 into main chain: { ... A2 }
*/
//jacobsthal:
//https://en.wikipedia.org/wiki/Jacobsthal_number

