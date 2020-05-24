'''
CRACKING THE CODING INTERVIEW 16.2 Word Frequencies
Design a method to find the frequency of occurences of any given
word in a book. What if we were running this algorithm multiple times?
'''
def remove_punctuation(word):
    punctuation = ',.",;:'

    new_word = ''
    for letter in word:
        if letter not in punctuation:
            new_word += letter
    return new_word

def create_dict(book):
    book = remove_punctuation(book)
    book = book.lower().split(' ')
    map = {}
    for word in book:
        if word in map:
            map[word] += 1
        else:
            map[word] = 1

    return map

def word_frequencies(book,word):

    my_dict = create_dict(book)
    return my_dict[word.lower()]

def main():
    book = 'Hello, this my impersonation of a book. Hello what is your name. As you can see, I am using the word\
            Hello alot. This is the Hello book. Oh one more thing, did I say Hello yet?'
    word = 'Hello'

    print(word,'appears in the book', word_frequencies(book,word),'times')

if __name__ == '__main__':
    main()
