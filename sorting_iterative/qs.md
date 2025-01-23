```bash
QUICKSORT(ARR, BEG, END)
IF (BEG < END)
             PIVOTINDEX = PARTITION(ARR,BEG, END)
             QUICKSORT(ARR, BEG, PIVOTINDEX)
             QUICKSORT(ARR, PIVOTINDEX + 1, END) 
             PARTITION(ARR, BEG, END)
SET END AS PIVOTINDEX 
PINDEX = BEG - 1 
         FOR I = BEG TO END-1 
           IF ARR[I] < PIVOT 
                      SWAP ARR[I] AND ARR[PINDEX] 
                      PINDEX++ 
                      SWAP PIVOT AND ARR[PINDEX+1] 
RETURN PINDEX + 1
```