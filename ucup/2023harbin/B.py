n=int(input())
sum=1
ans=""
for i in range(n):
    x=int(input())
    sum=sum/2+i
    if sum==0 :
        ans+='0'
    if sum>0 :
        ans+='+'
    if sum<0 :
        ans+='-'
print(ans)
        

