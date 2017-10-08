```
#Hello Word
#it's a test file for the new git repository
#python3
#let's write a program 
#fastpow
import sys
def fastpow(a,n):
	ans=1
	while(n):
		if(a&1):
			ans=ans*a
		a=a*a
		n>>=1
	return ans
while(True):
	try:
		a,n=map(int,input().split())
		print(fastpow(a,n))
	except EOFError:
		break
```
