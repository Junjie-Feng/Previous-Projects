
from os import path
from wordcloud import WordCloud

a = path.dirname(__file__)
# Read the whole text.
text = open(path.join(a, 'pseudo_code.txt')).read()
# Read the whole text.
#text = """The Zen of Python, by Tim Peters Beautiful is better than ugly. Explicit is better than implicit. Simple is better than complex. Complex is better than complicated. Flat is betteris easy to explain, it may be a good idea. Namespaces are one honking great idea -- let's do more of those!"""

# Generate a word cloud image
wordcloud = WordCloud().generate(text)

# Display the generated image:
# the matplotlib way:
import matplotlib.pyplot as plt
plt.imshow(wordcloud)
plt.axis("off")

# take relative word frequencies into account, lower max_font_size
wordcloud = WordCloud(max_font_size=40, relative_scaling=.5).generate(text)
#plt.figure()
plt.imshow(wordcloud)
plt.axis("off")
plt.show()
