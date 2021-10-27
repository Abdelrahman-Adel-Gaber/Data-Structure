# python3

import sys
from collections import namedtuple

Answer = namedtuple('answer_type', 'i j len')

def HashTable(s, prime, x):
    hash_table = list([] for _ in range(len(s) + 1))
    hash_table[0] = 0
    for i in range(1, len(s) + 1):
        hash_table[i] = (hash_table[i - 1] * x + ord(s[i - 1])) % prime
    return hash_table

def HashValue(hash_table, prime, x, start, length):
    y = pow(x, length, prime)
    hash_value = (hash_table[start + length] - y * hash_table[start]) % prime
    return hash_value


def AreEqual(table1, table2, prime1, prime2, x, a, b, l):
    a_hash1 = HashValue(table1, prime1, x, a, l)
    a_hash2 = HashValue(table2, prime2, x, a, l)
    b_hash1 = HashValue(table1, prime1, x, b, l)
    b_hash2 = HashValue(table2, prime2, x, b, l)
    if a_hash1 == b_hash1 and a_hash2 == b_hash2:
        return 'Yes'
    else:
        return 'No'

def solve(s, t):
	ans = Answer(0, 0, 0)
	m1 = 1000000007
    m2 = 1000000009
    x = 263
   
	HashTable1_s=hash_table(s,m1)
	HashTable2_s=hash_table(s,m1)
	HashTable1_t=hash_table(t,m1)
	HashTable2_t=hash_table(t,m1)
	if(len(s)>len(t)) :
      for(i=len(t)-1 down to 0 ):
       j=i
	   while(j<=len(t)-1):
	     if(AreEqual(HashTable1_s,HashTable1_t,m1,m2))
		 j++
		
	else :

	return ans

for line in sys.stdin.readlines():
	s, t = line.split()
	ans = solve(s, t)
	print(ans.i, ans.j, ans.len)
