# Task 5 – Memory diagram (likes / ptrLikes)

```
 Variable        Address        Value
 ┌────────────┬──────────────┬──────────────┐
 │ likes      │ 0x1000       │ 250          │◄──────┐
 ├────────────┼──────────────┼──────────────┤       │
 │ ptrLikes   │ 0x1008       │ 0x1000       │───────┘  (pointer stores ADDRESS of likes)
 └────────────┴──────────────┴──────────────┘

  &likes    = 0x1000     ptrLikes  = 0x1000
  *ptrLikes = 250        &ptrLikes = 0x1008
```
(Addresses are illustrative; real addresses are printed by pointers.c.)
