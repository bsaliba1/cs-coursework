#SUBSTITUTION
import json

jfile = open('substitutions.json','r').read()
jdictionary = json.loads(jfile)
news = open('Nytimes.txt').read()

for key in jdictionary:
	news = news.replace(key,jdictionary([key]))

file2 = open('better_news.txt', 'w')
file2.write(text)
file2.close()
