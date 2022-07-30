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


<<< Binary Search Tree <<<

[7,5,1,8,3,6,0,9,4,2] Dizisinin Binary-Search-Tree Aşamaları

Root 7'dir.

5, 7'den küçük olduğu için root'un solunda bulunur.

1, 7'den ve 5'ten küçük olduğu için 5'in solunda bulunur.

8, 7'den büyük olduğu için 7'nin sağında bulunur.

3, 7'den ve 5'ten küçük; 1'den büyük olduğu için 1'in sağında bulunur.

6, 7'den küçük 5'den büyük olduğu için 5'in sağında bulunur.

0, hepsinden küçük olduğu için kendinden önceki en küçük sayı olan 1'in solunda bulunur.

9, hepsinden büyük olduğu için kendinden önceki en büyük sayı olan 8'in sağında bulunur.

4, 7 ve 5'ten küçük; 1 ve 3'ten büyük olduğu için 3'ün sağında bulunur.

2, 7 ve 5'ten küçük; 1'den büyük ve 3'ten küçük olduğu için 3'ün solunda bulunur.




