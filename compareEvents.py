a=[]
for line in open("fying.txt"):
    #aa = line.split() 
    a.append(line)

b=[]
for line2 in open("raman.txt"):
    #bb = line.split()
    b.append(line2)


aminusb=set(a)-set(b)
bminusa=set(b)-set(a)
sameevent=set(a)&set(b)

ab=list(aminusb)
ba=list(bminusa)
same=list(sameevent)

print " one - two "
for jevent in range(len(ab)):
    print ab[jevent]


print "two - one"
for ievent in range(len(ba)):
    print ba[ievent]


#print "same of pixel seed and conv veto"




print "lenght of a-b =", len(ab)
print "lenght of b-a =", len(ba)
print "length of sameevent =", len(same)
