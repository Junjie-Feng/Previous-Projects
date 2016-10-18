	
import re	
import nltk
import os
from nltk.stem import WordNetLemmatizer
lemmatizer = WordNetLemmatizer()


f=open('e:/data.txt')
g=open("e:/result.txt",'wb')
for line in f:
    rule=re.compile(r'[^a-zA-z0-9 ]')
    result = rule.sub(' ',line)
    line1 = result.lower() 
    tmp=""		
    y=re.findall(r"\w+",line1)
    len = nltk.pos_tag(y)
    for x in len:	 
	    if x[1][0:1] == "V":
		    tmp1 = lemmatizer.lemmatize(x[0],pos='v')
	    else:
		    tmp1 = lemmatizer.lemmatize(x[0])
	    tmp = tmp + " " + tmp1
    print tmp
    g.write('\n')
    g.write(tmp)
    
	
f.close()
g.close()
os.remove('e:/data.txt')
