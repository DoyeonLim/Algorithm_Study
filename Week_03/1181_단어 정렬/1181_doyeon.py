n = int(input())
word_list = [input() for i in range(n)]

set_word_list = set(word_list)
word = list(set_word_list)
word.sort()
word.sort(key=len)

for i in word:
    print(i)

