# algoritma

<<< Insertion Sort <<<

[22,27,16,2,18,6] -> Insertion Sort

[22,27,16,2,18,6] -> n

[2,27,16,22,18,6] -> (n-1)

[2,6,16,22,18,27] -> (n-2)

[2,6,16,18,22,27] -> 1 
n*(n-1) ~ n2

Big-O gösterimi = O(n2)


              Time Complexity:

Average case: Aradığımız sayının ortada olması

Worst case: Aradığımız sayının sonda olması

Best case: Aradığımız sayının dizinin en başında olması.

Dizi sıralandıktan sonra 18 sayısı Average Case kapsamındadır.


[7,3,5,8,2,9,4,15,6] Dizisinin Insertion Sort'a göre ilk 4 adımı

Adım [2,3,5,8,7,9,4,15,6]

Adım [2,3,4,8,7,9,5,15,6]

Adım [2,3,4,5,7,9,8,15,6]

Adım [2,3,4,5,6,9,8,15,7]


