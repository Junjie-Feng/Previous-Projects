from textblob import TextBlob

from textblob.sentiments import NaiveBayesAnalyzer
# blob = TextBlob("Thinking Kate Winslet was the best thing about the Steve Jobs movie.", analyzer=NaiveBayesAnalyzer())
# print(blob.sentiment)

#Loved, loved, loved the new James Bond, Spectre. Hats off to Sam Mendes- simply brilliant- & so pleased to see the return of Blofeld's cat

#Thinking Kate Winslet was the best thing about the Steve Jobs movie. 

#Kate Winslet in Steve Jobs


twt1 = "I went to see Spectre this evening - great film, I really enjoyed it - Daniel Craig is the best Bond ever."
twt2 = "Saw Spectre, it was shit, Sam Smith's song is an abomination, fair play to Daniel Craig for playing a hot character as an ugly man."

twts = [twt1, twt2]

for i in twts:
	blob = TextBlob(i, analyzer=NaiveBayesAnalyzer())
	print("Tweet text: ",i)
	print("NaiveBayes result: ", blob.sentiment)

