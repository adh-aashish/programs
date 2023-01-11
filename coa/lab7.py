pages=[2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2]
f=int(input("Enter number of frames: "))
frame=[ 0 for _ in range(f)]
frames=[[0 for _ in range(12)] for _ in range(f)]

i=0
hit=0
for k in range(12):
    if pages[k] in frame: hit+=1
    else: 
        frame[i]=pages[k]
        i=(i+1)%f
    for j in range(f):
        frames[j][k]=frame[j]

print(pages)

for i in range(f):
    print(frames[i])

print("HIT: ", hit)
print("HIT ratio: ", hit/12)