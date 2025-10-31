PUNCTUATION_CHARS = '!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
STOPWORDS_SET = {'i','me','my','a','an','the','is','am','was','and','but','if','or','to','of','at','by','for','with','this','that'}
POSITIVE_WORDS_SET = {'love','amazing','great','helpful','resolved'}
NEGATIVE_WORDS_SET = {'disaster','broken','worst','avoid','bad'}

allPosts = [
    {'id': 1, 'text': 'I LOVE the new #GuIPhone! Battery life is amazing.'},
    {'id': 2, 'text': 'My #GuIPhone is a total disaster. The screen is already broken!'},
    {'id': 3, 'text': 'Worst customer service ever from @GuIPhoneSupport. Avoid this.'},
    {'id': 4, 'text': 'The @GuIPhoneSupport team was helpful and resolved my issue. Great service!'}
]

def preprocessText(text, punctuationList, stopwordsSet):
    text = text.lower()
    for ch in punctuationList:
        text = text.replace(ch, '')
    words = text.split()
    clean_words = [word for word in words if word not in stopwordsSet]
    return clean_words

def analyzePosts(postsList, punctuation, stopwords, positive, negative):
    def scoreText(words):
        score = 0
        for w in words:
            if w in positive:
                score += 1
            elif w in negative:
                score -= 1
        return score
    return list(map(lambda post: {
        'id': post['id'],
        'text': post['text'],
        'processedText': preprocessText(post['text'], punctuation, stopwords),
        'score': scoreText(preprocessText(post['text'], punctuation, stopwords))
    }, postsList))

def getFlaggedPosts(posts):
    flagged = list(filter(lambda p: p['score'] < 0, posts))
    return flagged

def findNegativeTopics(posts):
    hashtags = {}
    mentions = {}
    for post in posts:
        words = post['text'].split()
        for word in words:
            if word.startswith('#'):
                hashtags[word] = hashtags.get(word, 0) + 1
            elif word.startswith('@'):
                mentions[word] = mentions.get(word, 0) + 1
    return {'hashtags': hashtags, 'mentions': mentions}

analyzed = analyzePosts(allPosts, PUNCTUATION_CHARS, STOPWORDS_SET, POSITIVE_WORDS_SET, NEGATIVE_WORDS_SET)
flagged = getFlaggedPosts(analyzed)
topics = findNegativeTopics(flagged)

print("Analyzed Posts:")
for post in analyzed:
    print(post)

print("\nFlagged (Negative) Posts:")
for post in flagged:
    print(post)

print("\nNegative Topics Found:")
print(topics)
